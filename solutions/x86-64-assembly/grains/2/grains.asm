section .text
global square
square:
    xor rax, rax                ; bitstring

    ;; if (n <= 0 || n >= 65) return -1
    cmp dil, 0
    jle .done
    cmp dil, 65
    jge .done

    ;; Assume rdi is 3
    sub rdi, 1
    ;; set the bit at position 3 to 1
    ;; 0000_0000 = 0000_1000 => 8
    bts rax, rdi                ; set a specific bit

.done:
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
