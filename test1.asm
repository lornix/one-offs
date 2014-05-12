;
	extern printf

	global main

	section .text

main:
	mov	rdi,15
	mov	rsi,msg1
	call	printf

	int3

	ret

section	.data

msg1:
	db 'value: %d',10,0

