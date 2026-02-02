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
    and dl, 0x5F                ; Turn value into a uppercase letter
    ; if dl < 'A' && dl > 'Z'
    cmp dl, 'A'
    jb .continue
    cmp dl, 'Z'
    ja .continue                ; We now know that we are dealing with characters in the range A-Z
    sub dl, 'A'
    bt ecx, edx                 ; if ecx[edx] = 1 already then
    jc .is_set                  ;   return 0
    bts ecx, edx                ; else
.continue:
    add rdi, 1                  ; advance to the next char
    jmp .loop
.is_set:
    xor eax, eax
.done:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
