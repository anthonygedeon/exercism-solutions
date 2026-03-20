default rel

section .data
    black  db "black", 0
    brown  db "brown", 0
    red    db "red", 0
    orange db "orange", 0
    yellow db "yellow", 0
    green  db "green", 0
    blue   db "blue", 0
    violet db "violet", 0
    grey   db "grey", 0
    white  db "white", 0

    color_array dq black, brown, red, orange, yellow, green, blue, violet, grey, white, 0

section .text
global color_code
color_code:
    xor rax, rax
    xor rcx, rcx
    xor r10, r10
    lea r11, [color_array] ; get pointer of current string
.loop:
    mov rcx, [r11 + r10 * 8]
    cmp rcx, 0
    je .done
    call is_same
    cmp rax, 1
    je .done
    add r10, 1
    jmp .loop
.done:
    mov rax, r10
    ret

is_same:
    xor r8, r8
.loop:
    mov al, byte [rdi + r8]
    mov dl, byte [rcx + r8] ; Assuming 2nd arg is rsi per System V ABI

    cmp   al, dl
    jne   .false            ; If chars don't match, return 0

    test  al, al            ; Check for null terminator (end of string)
    jz    .true             ; If both were null and matched, return 1

    inc  r8
    jmp   .loop
.false:
    xor rax, rax            ; Return 0
    ret
.true:
    mov rax, 1              ; Return 1
    ret

global colors
colors:
    lea rax, [color_array]
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
