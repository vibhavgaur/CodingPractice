	.file	"1-13.c"
	.text
	.section	.rodata
.LC0:
	.string	"We have an uppercase letter"
.LC1:
	.string	"Not an uppercase alphabet"
	.text
	.globl	lower
	.type	lower, @function
lower:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$64, -4(%rbp)
	jg	.L2
	cmpl	$90, -4(%rbp)
	jg	.L3
.L2:
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	-4(%rbp), %eax
	addl	$32, %eax
	jmp	.L4
.L3:
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	-4(%rbp), %eax
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	lower, .-lower
	.section	.rodata
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$97, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L7:
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	lower
	movl	%eax, %edi
	call	putchar@PLT
.L6:
	call	getchar@PLT
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L7
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
