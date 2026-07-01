	.file	"Bit_map_C_code_other.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rsi
	movl	$0, -84(%rbp)
	movl	$1347428384, -31(%rbp)
	movw	$-118, -27(%rbp)
	movb	$-118, -25(%rbp)
	movl	$5, -60(%rbp)
	movl	$7, -56(%rbp)
	movl	-56(%rbp), %eax
	sall	$2, %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -48(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r8
	movl	$0, %r9d
	movslq	%eax, %rdx
	movq	%rdx, %rcx
	movl	$0, %ebx
	cltq
	movl	$16, %edx
	subq	$1, %rdx
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	movq	%rax, %rcx
	andq	$-4096, %rcx
	movq	%rsp, %rdx
	subq	%rcx, %rdx
.L2:
	cmpq	%rdx, %rsp
	je	.L3
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L2
.L3:
	movq	%rax, %rdx
	andl	$4095, %edx
	subq	%rdx, %rsp
	movq	%rax, %rdx
	andl	$4095, %edx
	testq	%rdx, %rdx
	je	.L4
	andl	$4095, %eax
	subq	$8, %rax
	addq	%rsp, %rax
	orq	$0, (%rax)
.L4:
	movq	%rsp, %rax
	addq	$0, %rax
	movq	%rax, -40(%rbp)
	movl	$0, -80(%rbp)
	movl	-60(%rbp), %eax
	addl	%eax, %eax
	addl	$7, %eax
	leal	7(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$3, %eax
	movl	%eax, -52(%rbp)
	movl	$0, -76(%rbp)
	jmp	.L5
.L11:
	movl	$0, -72(%rbp)
	movl	$128, -68(%rbp)
	movl	$0, -64(%rbp)
	jmp	.L6
.L10:
	cmpl	$0, -64(%rbp)
	jne	.L7
	movq	-40(%rbp), %rdx
	movl	-84(%rbp), %eax
	cltq
	movb	$0, (%rdx,%rax)
	movl	-84(%rbp), %edx
	movl	-52(%rbp), %eax
	addl	%edx, %eax
	movq	-40(%rbp), %rdx
	cltq
	movb	$0, (%rdx,%rax)
	addl	$1, -84(%rbp)
	movl	$192, -64(%rbp)
.L7:
	cmpl	$0, -68(%rbp)
	jne	.L8
	addl	$1, -80(%rbp)
	movl	$128, -68(%rbp)
.L8:
	movl	-80(%rbp), %eax
	cltq
	movzbl	-31(%rbp,%rax), %eax
	movsbl	%al, %eax
	andl	-68(%rbp), %eax
	testl	%eax, %eax
	je	.L9
	movl	-84(%rbp), %eax
	subl	$1, %eax
	movq	-40(%rbp), %rdx
	cltq
	movzbl	(%rdx,%rax), %edx
	movl	-64(%rbp), %eax
	movl	%eax, %ecx
	movl	-84(%rbp), %eax
	subl	$1, %eax
	orl	%edx, %ecx
	movq	-40(%rbp), %rdx
	cltq
	movb	%cl, (%rdx,%rax)
	movl	-84(%rbp), %edx
	movl	-52(%rbp), %eax
	addl	%edx, %eax
	subl	$1, %eax
	movq	-40(%rbp), %rdx
	cltq
	movzbl	(%rdx,%rax), %edx
	movl	-64(%rbp), %eax
	movl	%eax, %edi
	movl	-84(%rbp), %ecx
	movl	-52(%rbp), %eax
	addl	%ecx, %eax
	subl	$1, %eax
	movl	%edx, %ecx
	orl	%edi, %ecx
	movq	-40(%rbp), %rdx
	cltq
	movb	%cl, (%rdx,%rax)
.L9:
	sarl	$2, -64(%rbp)
	sarl	-68(%rbp)
	addl	$1, -72(%rbp)
.L6:
	movl	-72(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L10
	movl	-52(%rbp), %eax
	addl	%eax, -84(%rbp)
	addl	$1, -80(%rbp)
	addl	$1, -76(%rbp)
.L5:
	movl	-76(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jl	.L11
	movq	%rsi, %rsp
	movl	$0, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
