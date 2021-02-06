section .text
	global _ft_strcmp

_ft_strcmp:
	mov rax, 0
	mov r10, 0					; just a 64bit reg

while:
	movzx rbx, byte[rdi+r10]	; rbx = str[i] (movzx - copy with zero extended)
	movzx rcx, byte[rsi+r10]
	cmp rbx, rcx
	jg	maximal					; jg - go there if more than
	jl	minimal					; jl - go there if less than
	cmp byte[rdi+r10], 0
	je	end						; je - go there if equal
	inc r10
	jmp while
	
minimal:
	mov	rax, -1
	ret

maximal:
	mov rax, 1
	ret

end:
	mov rax, 0
	ret
	