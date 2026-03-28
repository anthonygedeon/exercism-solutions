section .text
global is_isogram
is_isogram:
    mov eax, 1                  ; our return value

.while_loop:
    cmp byte [rdi], 0        ; while (*rdi != '\0')
    jz  .while_loop_done

    mov r9, 1                 ; int i = 1
.for_loop:
    lea r8, [rdi + r9]
    cmp byte [r8], 0         ; for (int i = 1; *(rdi + rcx) != '0')
    jz  .for_loop_done

    call tolower                ; tolower(rdi)
    mov bl, al

    mov rcx, rdi
    mov rdi, r8
    call tolower                ; tolower(rbx)
    mov rdi, rcx

    cmp bl, 'a'
    jl .check

    cmp bl, 'z'
    jg .check

    cmp al, bl    ; if (tolower(dl) == tolower(rdi[i]))
    je .identical

.check:
    inc r9                     ; i++
    jmp .for_loop

.identical:
    xor eax, eax
    jmp .done          ; break

.for_loop_done:
    add rdi, 1
    jmp .while_loop

.while_loop_done:
    mov eax, 1
.done:
    ret

tolower:
    mov al, byte [rdi]

    ;; if *rbx >= 'A' && *rbx <= 'Z' && *rbx == 0
    cmp al, 0
    je .done

    cmp al, 'A'
    jge .is_uppercase1
.and:
    cmp al, 'Z'
    jle .is_uppercase2

    jmp .done

.is_uppercase1:
    jmp .and
.is_uppercase2:
    or al, 0x20
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
