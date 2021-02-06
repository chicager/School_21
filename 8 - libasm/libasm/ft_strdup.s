section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	push rdi
	call _ft_strlen
	inc rax
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je error
	pop rdi
	mov rsi, rdi				; rsi - second argument reg
	mov rdi, rax
	call _ft_strcpy
	ret
	
error:
	ret