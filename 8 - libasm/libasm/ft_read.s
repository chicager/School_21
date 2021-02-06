section	.text
	global _ft_read
	extern ___error

_ft_read:
	xor	rax, rax
	mov	rax, 0x02000003
	syscall
	jc error
	ret

error:
	push rax
	call ___error
	pop	rbx				; just a 64bit reg
	mov	[rax], rbx
	mov	rax, -1
	ret