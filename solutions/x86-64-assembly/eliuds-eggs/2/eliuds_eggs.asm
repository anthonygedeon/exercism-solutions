section .text
global egg_count
egg_count:
    xor rax, rax                ; total = 0;
.loop:
    ;; this loop handles shifting until RDI is 0
    cmp rdi, 0                  
    je .done
    shr rdi, 1                  ; arg >>= 1
    ;; if a bit gets shifted and it's a 1 then it will be inserted into the CF flag
    jnc .loop
    ;; this means that the mask resulted in a 1 ∴ RDI AND 0x1 = 1
    inc rax
    jmp .loop
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
