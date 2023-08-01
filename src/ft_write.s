global ft_write

segment .text
ft_write:
	; prologue
	push rbp 
	mov rbp,rsp
	; body
	; epilogue
	pop rbp
	ret
