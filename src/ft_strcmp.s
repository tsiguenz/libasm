global ft_strcmp

segment .text
ft_strcmp:
	push rbp 
	mov rbp,rsp
	xor rcx,rcx
	xor rax,rax
	xor r8,r8
	xor r9,r9
	mov r10,rdi
	mov r11,rsi
	.loop:
		mov r8b,BYTE [r10+rcx]
		mov r9b,BYTE [r11+rcx]
		sub r8b,r9b
		jnz  .set_ret
		cmp BYTE [r10+rcx],0
		jz  .end
		inc rcx
		jmp .loop
	.set_ret:
		movsx rax, r8b
	.end:
		pop rbp
		ret
