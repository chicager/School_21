section .text
	global _ft_list_size

_ft_list_size:
	mov	rax, 0			; i = 0

loop:
	cmp	rdi, 0			; if lst == NULL
	je end				; then return
	mov	rdi, [rdi+8]	; lst = lst->next
	inc	rax				; i++
	jmp	loop			; loop till NULL

end:
	ret