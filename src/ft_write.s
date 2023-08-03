global ft_write

extern __errno_location

segment .text

ft_write:
	mov rax,1
	syscall
	cmp rax,0
	js handle_error
	jmp set_return_value

set_return_value:
	mov rax, rdx
	jmp end

handle_error:
	mov r8,rax
	neg r8
	call __errno_location wrt ..plt
	mov [rax],r8
	mov rax,-1
	jmp end

end:
	ret
