section .text
global steps
steps:
    push rbp
    mov rbp, rsp                ; prologue
    ;; valid arguments must be greater than 0
    cmp edi, 1
    jl .error
    ;; clobber rdx as this will be our counter variable
    xor rax, rax                ; count = 0
.loop:
    cmp rdi, 1                  ; if rdi == 1 then we know we are done
    je .done
    inc rax
    ;; we just check the lsb to see if it's even or odd
    bt rdi, 0
    jnc .is_even
    ;; else rdi must be odd
    imul rdi, rdi, 3            ; rdi *= 3
    inc rdi
    jmp .loop
.is_even:
    shr rdi, 1                  ; since rdi is even we can use powers of 2 and just shift right once
    jmp .loop
.error:
    mov rax, -1
.done:
    leave                       ; epilogue
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
