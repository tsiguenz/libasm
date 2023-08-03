global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

segment .text

ft_strdup:
	mov r8,rdi
	call ft_strlen
	inc rax ; nothing change when I delete this
	mov rdi,rax
	call malloc wrt ..plt
	cmp rax, 0
	je handle_error
	mov rdi,rax
	mov rsi,r8
	call ft_strcpy
	jmp end

handle_error:
	mov rax,0
	jmp end

end:
	ret
