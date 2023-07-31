global ft_strlen

segment .text
ft_strlen:
	; prologue
	push rbp 
	mov rbp,rsp
	; body
	xor rcx,rcx ; set rcx to 0
	mov r10,rdi ; get the first argument
	.loop:
		cmp byte [r10+rcx],0 ; check if the first byte is 0
		jz  .end ; if it is, jump to the end
		inc rcx ; increment rcx
		jnz .loop ; if it isn't, jump to the loop
	.end:
		mov rax,rcx ; set rcx to rax
	; epilogue
	pop rbp
	ret
