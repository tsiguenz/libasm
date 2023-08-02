global ft_strcpy

segment .text

	ft_strcpy:
		mov rax,rdi ; set return value
		jmp .loop

	.loop:
		mov r11b, BYTE [rsi]
		mov BYTE [rdi],r11b ; *(dest+i) = *(src+i)
		cmp BYTE [rsi],0 ; check if the first byte is 0
		jz  .end ; if it is, jump to the end
		inc rdi ; dest++
		inc rsi ; src++
		jmp .loop

	.end:
		ret
