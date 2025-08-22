section .text
global to_rna
to_rna:
    xor rcx, rcx
.loop:
    cmp byte [rdi + rcx], 0
    je .done
    mov al, byte [rdi + rcx]
    call match_complement
    mov [rsi + rcx], al
    inc rcx
    jmp .loop
.done:
    mov rax, rsi
    mov byte [rsi + rcx], 0
    ret

match_complement:
    cmp al, 'G'
    je .case1
    cmp al, 'C'
    je .case2
    cmp al, 'T'
    je .case3
    cmp al, 'A'
    je .case4
.case1:
    mov al, 'C'
    jmp .done
.case2:
    mov al, 'G'
    jmp .done
.case3:
    mov al, 'A'
    jmp .done
.case4:
    mov al, 'U'
    jmp .done
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
