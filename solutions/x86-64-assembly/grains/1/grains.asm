section .text
global square
square:
    ;; if (n <= 0 || n >= 65) return -1
    cmp dil, 0
    jle .error
    cmp dil, 65
    jge .error

    ;; 1 << (arg - 1)
    mov rax, 1
    sub dil, 1
    mov cl, dil
    shl rax, cl
    ret
.error:
    xor rax, rax
    ret

global total
total:
    ;; The RAX register isn't unsigned or signed and should be thought of as a block of bits
    ;; that store a value.
    mov rax, -1
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
