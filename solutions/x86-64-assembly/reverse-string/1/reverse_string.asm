section .text

global reverse
reverse:
    call strlen
    mov rbx, rax                ; store the length of the word in ebx
    inc rbx                     ; handle '\0'
    sub rsp, rbx
    mov rcx, 0
reverse_loop:
    cmp rbx, 0
    je reverse_done
    inc rcx
    mov rax, [rdi + (rbx - 1)]
    mov [rsp + rcx], rax
    dec rbx
    jmp reverse_loop
reverse_done:
    mov rdi, [rsp + 1]
    leave
    ret

strlen:
    xor rax, rax                ; length = 0
strlen_loop:
    cmp byte [rdi + rax], 0
    je strlen_done
    inc rax
    jmp strlen_loop
strlen_done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
