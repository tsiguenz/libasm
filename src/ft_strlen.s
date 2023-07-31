segment	.text
global ft_strlen     ;must be declared for linker (ld)

ft_strlen:	            ;tells linker entry point
	push	rbp 
	mov		rbp,rsp
	mov		rsi, rdi ; arg2=len
	mov		dword [rsi], 42
	pop		rbp
	ret
