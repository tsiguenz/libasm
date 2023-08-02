global ft_strlen

segment .text

	ft_strlen:
		xor rcx,rcx ; set rcx to 0
		jmp .loop

	.loop:
		cmp BYTE [rdi+rcx],0 ; check if the first byte is 0
		jz  .end ; if it is, jump to the end
		inc rcx ; increment rcx
		jmp .loop

	.end:
		mov rax,rcx ; set rcx to rax
		ret
