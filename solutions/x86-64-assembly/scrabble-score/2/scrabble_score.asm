default rel

section .data
    scrabble_scores: db 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10

section .text
global score
score:
    xor rcx, rcx
    xor rax, rax                ; total = 0
.loop:
    mov cl, byte [rdi]          ; char al = *rdi
    cmp cl, 0
    jz .done

    and cl, 0x5F                ; toupper(al)
    sub cl, 'A'
    lea r10, [scrabble_scores]
    add al, byte [r10 + rcx]

    add rdi, 1                  ; advance to next char
    jmp .loop
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
