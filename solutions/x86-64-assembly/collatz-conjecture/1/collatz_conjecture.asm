section .text
global steps
steps:
    xor rcx, rcx
    xor rbx, rbx
    mov rcx, rdi
.loop:
    cmp rcx, 1
    je .done
    jl .error
    inc rbx
    mov rcx, rdi
    and rdi, 1
    cmp rdi, 0                  ; if lsb is 0
    je .is_even
    jmp .is_odd
.is_even:
    ;; (rdx:rax) / rcx
    mov rax, rcx
    xor rdx, rdx
    mov rcx, 2
    div rcx
    mov rcx, rax
    mov rdi, rcx
    jmp .loop
.is_odd:
    ;; (rdx:rax) * rcx
    mov rax, rcx
    xor rdx, rdx
    mov rcx, 3
    mul rcx
    mov rcx, rax
    inc rcx
    mov rdi, rcx
    jmp .loop
.done:
    mov rax, rbx
    leave
    ret
.error:
    mov rax, -1
    leave
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
