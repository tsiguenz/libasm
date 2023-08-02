global ft_write

segment .text

ft_write:
	mov rax,1
	int 0x80
	mov rax,42
	ret
