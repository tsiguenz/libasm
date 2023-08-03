global ft_read

extern __errno_location

segment .text

ft_read:
	mov rax,0
	syscall
	cmp rax,0
	js handle_error
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
