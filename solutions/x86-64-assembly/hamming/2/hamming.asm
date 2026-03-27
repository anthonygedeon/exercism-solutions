section .text
global distance
distance:
    call strlen
    mov r8, rdi
    mov rdi, rsi
    mov rcx, rax
    call strlen
    cmp rcx, rax
    jne .error
    mov rdi, r8
    xor rax, rax                ; distance = 0;
.loop:
    mov cl, byte [rdi]
    cmp cl, 0
    je .done
    cmp cl, byte [rsi]          ; if arg1[0] != arg2[0] then
    jne .increment
    inc rdi
    inc rsi
    jmp .loop
.increment:
    inc rax                     ; hamming difference
    inc rdi
    inc rsi
    jmp .loop
.error:
    mov rax, -1
.done:
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
