section .text
global distance
distance:
    call strlen
    mov rbx, rdi
    mov rdi, rsi
    mov rcx, rax
    call strlen
    cmp rcx, rax
    jne .error
    mov rdi, rbx
    xor rcx, rcx                ; distance = 0;
    mov rax, rdi                ; $rax pointer to arg1
    mov rbx, rsi                ; $rbx pointer to arg2
.loop:
    movzx rdx, byte [rax]
    cmp rdx, 0
    je .done
    cmp rdx, [rbx]              ; if arg1[0] != arg2[0] then
    jne .increment
    jmp .loop
.increment:
    inc rcx
    inc rax
    inc rbx
    jmp .loop
.done:
    mov rax, rcx
    leave
    ret
.error:
    mov rax, -1
    leave
    ret

strlen:
    xor rax, rax                ; length = 0
.loop:
    cmp byte [rdi + rax], 0
    je .done
    inc rax
    jmp .loop
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
