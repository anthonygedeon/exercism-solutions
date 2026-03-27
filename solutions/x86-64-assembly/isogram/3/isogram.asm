section .text
global is_isogram
is_isogram:
    xor rdx, rdx                ; this will be our position of the bitmap
    xor rcx, rcx                ; bitmap will hold a 26-bit value that will act as our hashmap
    mov eax, 1                  ; our return value
.loop:
    cmp byte [rdi], 0           ; *rdi == '\0'
    jz .done
    mov dl, byte [rdi]          ; we can't mutate the argument so we must copy the byte over
    add rdi, 1                  ; advance to the next char
    and dl, 0x5F                ; Turn value into a uppercase letter
    ; if dl < 'A' && dl > 'Z'
    sub dl, 'A'
    cmp dl, 26                  ; dl - 26 (if dl = 0 then 0 - 26 = -26 and CF = 1)
    jae .loop                   ; if CF == 1 then loop
    bts ecx, edx                ; if (ecx[edx] == 1) then ecx[edx] = 1 else
    jc .is_set                  ;   return 0
    jmp .loop
.is_set:
    xor eax, eax
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
