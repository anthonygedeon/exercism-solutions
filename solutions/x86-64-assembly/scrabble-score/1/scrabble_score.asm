default rel

section .data
scrabble_scores: db 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 5, 8, 10, 10

section .text
global score
score:
    xor rax, rax                ; total = 0
.loop:
    cmp byte [rdi], 0
    jz .done
    mov al, byte [rdi]          ; char al = *rdi
    and al, 0x5F                ; toupper(al)
    sub al, 'A'
    movzx rbx, al
    add rax, [scrabble_scores + rbx]
    add rdi, 1                  ; advance to next char
    jmp .loop
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
