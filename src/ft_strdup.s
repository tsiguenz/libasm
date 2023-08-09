global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

segment .text

	ft_strdup:
		push rbp
		mov rbp,rsp
		push rdi
		call ft_strlen wrt ..plt
		inc rax
		mov rdi,rax
		call malloc wrt ..plt
		cmp rax, 0
		jz handle_error
		mov rdi,rax
		pop rsi
		call ft_strcpy wrt ..plt
		jmp end
	
	handle_error:
		mov rax,0
		jmp end
	
	end:
		leave
		ret
