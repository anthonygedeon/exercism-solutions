;; NOTES:
;; What does rel do?
;; What does default rel do?
;; [rel ?] what does that mean?
section .data
dialogue:	db "One for %, one for me.", 0
you:	    db "you"

section .text
global two_fer
two_fer:
	xor r8, r8					; buffer index
	xor rcx, rcx				; dialogue index
	cmp rdi, 0                  ; check to see if a name was provided
	lea rax, [rel dialogue]
	je .is_null
	jmp .loop
.is_null:
	lea rdi, [rel you]
.loop:
	mov dl, byte [rax + rcx]

	cmp dl, 0
	jz .done

	cmp dl, '%'				    ; poor-man's printf
	je .skip_percentage
.insert_byte:
	mov [rsi + r8], dl			; insert characters into the buffer
	inc rcx
	inc r8
	jmp .loop
.skip_percentage:
	inc rcx						; this skips the '%'
	call insert_name		    ; start inserting whatever is in $rdi
	jmp .loop
.done:
	mov byte [rsi + r8], 0
	mov rax, rsi
	ret

;; Insert the name into the buffer that rsi currently points to
insert_name:
	cmp byte [rdi], 0
	jz .done

	mov dl, byte [rdi]
	inc rdi

	mov byte [rsi + r8], dl
	inc r8

	jmp insert_name
.done:
	ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
