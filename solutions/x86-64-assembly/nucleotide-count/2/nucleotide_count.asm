section .text
global nucleotide_counts
nucleotide_counts:
    ;; Prefer unrolling the loop and directly moving the value into the array
    mov qword [rsi + (0 * 8)], 0
    mov qword [rsi + (1 * 8)], 0
    mov qword [rsi + (2 * 8)], 0
    mov qword [rsi + (3 * 8)], 0

.loop:
    cmp byte [rdi], 0
    je .done

    ;; modify specific indexes in the array that RSI points to
    cmp byte [rdi], 'G'
    je .guanine

    cmp byte [rdi], 'A'
    je .adenine

    cmp byte [rdi], 'C'
    je .cytosine

    cmp byte [rdi], 'T'
    je .thymine

    ;; else the character is not valid since the set of nucleotides is { A C G T }
    mov qword [rsi + (0 * 8)], -1
    mov qword [rsi + (1 * 8)], -1
    mov qword [rsi + (2 * 8)], -1
    mov qword [rsi + (3 * 8)], -1

    ret

.adenine:
    add byte [rsi], 1
    jmp .end

.cytosine:
    add byte [rsi + 8], 1
    jmp .end

.guanine:
    add byte [rsi + 16], 1
    jmp .end

.thymine:
    add byte [rsi + 24], 1
    jmp .end

.end:
    inc rdi
    jmp .loop

.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
