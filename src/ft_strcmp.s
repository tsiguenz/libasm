global ft_strcmp

segment .text

	ft_strcmp:
		push rbp
		mov rbp,rsp
		xor rax,rax
		xor r8b,r8b
		xor r9b,r9b
		jmp .loop

	.loop:
		mov r8b,BYTE [rdi]
		mov r9b,BYTE [rsi]
		sub r8b,r9b
		jnz  .set_ret
		cmp BYTE [rdi],0
		jz  .end
		inc rdi
		inc rsi
		jmp .loop

	.set_ret:
		movsx rax, r8b
		jmp .end

	.end:
		leave
		ret
