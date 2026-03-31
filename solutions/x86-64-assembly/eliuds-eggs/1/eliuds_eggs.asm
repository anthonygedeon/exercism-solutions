section .text
global egg_count
egg_count:
    xor rax, rax                ; total = 0;
.loop:
    ;; this loop handles shifting until RDI is 0
    cmp rdi, 0                  
    je .done

    ;; if the result of the AND operation is zero then set ZF = 1
    test rdi, 0x1
    jz .skip

    ;; this means that the mask resulted in a 1 ∴ RDI AND 0x1 = 1
    inc rax                     
.skip:
    shr rdi, 1                  ; arg >>= 1
    jmp .loop
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
