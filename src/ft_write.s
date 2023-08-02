global ft_write

extern ft_strlen

segment .text

ft_write:
	mov rax,1
	syscall
	mov rdi, rsi
	call ft_strlen
	ret
