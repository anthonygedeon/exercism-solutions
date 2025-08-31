section .text
global to_rna
to_rna:
    xchg rdi, rsi
    mov rax, rdi
    cld
.loop:
    lodsb                       ; al = *rsi++
    cmp al, 0                   ; does al == '\0'?
    jz .done

    call match_complement       ; map the DNA -> RNA
    stosb                       ; *rsi++ = al

    jmp .loop
.done:
    mov byte [rdi], 0           ; terminate the string now
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
