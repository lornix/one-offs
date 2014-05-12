; ================================
; | adventures in 64bit assembly |
; ================================
;
	bits	64
	;default rel
;
section	.text
;
SC_sbrk:	equ	12
;
global	_start
;
_start:
;
	lea	rax,[_start]
	push	rax
	lea	rbx,[addrcode]
	call	tohex
;
	mov	eax,SC_sbrk
	mov	edi,0
	syscall
	push	rax
	lea	rbx,[addrdata]
	call	tohex
;
;	mov	rax,0x12345678
	pop	rax
	pop	rbx
	sub	rax,rbx
	lea	rbx,[addrgetp]
	call	tohex
;
	mov	eax,1		;write
	mov	edi,1		;fd=1, stdout
	lea	rsi,[msgstart]
	mov	edx,msgend-msgstart
	syscall
;
	mov	rax,60		;exit
	mov	rdi,0
	syscall
	hlt
;
tohex:
	add	rbx,7
.tohex1:
	push	rax
	and	al,0x0f
	or	al,0x30
	cmp	al,0x3a
	jl	.isnum
	add	al,7
.isnum:
	mov	[rbx],al
	dec	rbx
	pop	rax
	shr	rax,4
	and	rax,rax
	jnz	.tohex1
	ret
;
section	.data
;
msgstart:
	db	'Hello, World!',10
	db	'      &main: '
addrcode:
	db	'00000000',10
	db	'       sbrk: '
addrdata:
	db	'00000000',10
	db	'getpagesize: '
addrgetp:
	db	'00000000',10
msgend:
;
zzzend:	equ	$

