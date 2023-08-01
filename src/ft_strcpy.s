global ft_strcpy

segment .text
ft_strcpy:
	; prologue
	push rbp 
	mov rbp,rsp
	; body
	xor rcx,rcx ; set rcx to 0
	mov rax,rdi ; get the first argument (dest)
	mov r10,rsi ; get the second argument (src)
	.loop:
		mov r11b, BYTE [r10+rcx]
		mov BYTE [rax+rcx],r11b ; *(dest+i) = *(src+i)
		cmp BYTE [r10+rcx],0 ; check if the first byte is 0
		jz  .end ; if it is, jump to the end
		inc rcx ; increment rcx
		jmp .loop
	; epilogue
	.end:
		pop rbp
		ret
