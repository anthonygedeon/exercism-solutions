section .text
global nucleotide_counts
nucleotide_counts:
    mov qword [rsi],      0
    mov qword [rsi + 8],  0
    mov qword [rsi + 16], 0
    mov qword [rsi + 24], 0

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

    ;; else the character is not valid since the set of nucleotides is { A G C T }
    mov qword [rsi],      -1
    mov qword [rsi + 8],  -1
    mov qword [rsi + 16], -1
    mov qword [rsi + 24], -1

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
