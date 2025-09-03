default rel

section .data
dialogue:	db "One for %, one for me.", 0
you:	    db "you"

; rdi = name
; rsi = 265 byte buffer
section .text
global two_fer
two_fer:
	xor r8, r8					; rsi index
	xor rcx, rcx				; dialogue index
	lea rax, [rel dialogue]
.loop:
	mov dl, byte [rax + rcx]

	cmp dl, 0
	jz .done

	cmp dl, '%'				    ; poor-man's printf
	je .skip_percentage

	mov [rsi + r8], dl			;
	inc rcx
	inc r8

	jmp .loop

.skip_percentage:
	inc rcx						; this skips the '%'

	; check to see if a name was provided
	cmp rdi, 0					
	je .insert_you
.insert:
	cmp byte [rdi], 0
	jz .loop

	mov dl, byte [rdi]
	inc rdi

	mov byte [rsi + r8], dl
	inc r8

	jmp .insert
.insert_you:
	lea rdi, [rel you]
.insert_you_loop:
	cmp byte [rdi], 0
	jz .loop

	mov dl, byte [rdi]
	inc rdi

	mov byte [rsi + r8], dl
	inc r8

	jmp .insert_you_loop
.done:
	mov byte [rsi + r8], 0
	mov rax, rsi
	ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
