section .text
	global _ft_strlen

_ft_strlen:
	mov	rax, -1				; i = -1

loop:	
	inc	rax					; i++
	mov	cl, byte [rdi+rax]	; cl = str[i] (rdi - first argument reg, cl = 8bit part of rcx (index reg))
	cmp	cl, 0				; if cl == \0
    jne	loop				; go to loop if not equal
	ret