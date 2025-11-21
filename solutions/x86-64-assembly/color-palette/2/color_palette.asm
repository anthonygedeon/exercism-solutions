default rel
; Everything that comes after a semicolon (;) is a comment

; Define the constants 'RED', 'GREEN' and 'BLUE'
; They must be accessible from other source files

; Define the variable 'base_color' with the default value of 0xFFFFFF00
; It must be accessible from other source files


section .rodata
global RED, GREEN, BLUE

RED   dd 0xFF000000
GREEN dd 0x00FF0000
BLUE  dd 0x0000FF00

section .data
    global base_color
    base_color dd 0xFFFFFF00


section .text
; You should implement functions in the .text section

; the global directive makes a function visible to the test files
global get_color_value
get_color_value:
    ; This function takes the address for a color as parameter
    ; It must return the 32-bit value associated with the color
    mov eax, dword [rdi]
    ret

global add_base_color
add_base_color:
    ; This function takes the address for a color as parameter
    ; It saves the 32-bit value associated with this color in the variable 'base_color'
    ; This variable must be accessible from other source files
    ; This function has no return value
    call get_color_value
    mov dword [base_color], eax
    ret

extern combining_function
global make_color_combination
make_color_combination:
    ; rdi = pointer to combined_color
    ; rsi = pointer to secondary color (&GREEN)

    mov r8, rdi

    mov edi, dword [base_color] ; copy the actual color
    mov esi, dword [rsi]        ; repeat the process

    call combining_function     ; arg1 = base_color arg2 = secondary_color
    mov dword [r8], eax                ; result will be in rax

    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

