section .text
	global _ft_list_push_front
	extern _malloc

_ft_list_push_front:
	push rdi			; store list_start
	push rsi			; store data
	mov	rdi, 16			; 1st = 16
	call _malloc		; malloc(16)
	pop	rsi			
	pop	rdi			
	cmp	rax, 0			; if ret == NULL
	je end				; then return
	mov	[rax], rsi		; lst = data
	mov	rcx, [rdi]		; rcx - counter reg
	mov	[rax+8], rcx	; lst->next = list_start
	mov	[rdi], rax		; list_start = lst

end:
	ret