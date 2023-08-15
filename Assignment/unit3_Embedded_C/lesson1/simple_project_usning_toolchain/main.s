	.file	"main.c"
	.text
	.def	scanf;	.scl	3;	.type	32;	.endef
	.seh_proc	scanf
scanf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Enter two numbers : \12\0"
.LC1:
	.ascii "%f\0"
.LC2:
	.ascii "%f + %f = %f\12\0"
.LC3:
	.ascii "%f %% %f = %d\12\0"
.LC4:
	.ascii "%f^%f = %f\12\0"
.LC5:
	.ascii "%f! = %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	leaq	-8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movss	-8(%rbp), %xmm0
	movl	-4(%rbp), %eax
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	sum
	pxor	%xmm2, %xmm2
	cvtss2sd	%xmm0, %xmm2
	movss	-8(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movss	-4(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm2, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm2
	movq	%rax, %rcx
	movq	%xmm1, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	movq	%xmm0, %rax
	movq	%rax, %r8
	movq	%r8, %xmm0
	movapd	%xmm2, %xmm3
	movq	%rcx, %r9
	movapd	%xmm1, %xmm2
	movq	%rdx, %r8
	movapd	%xmm0, %xmm1
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movss	-8(%rbp), %xmm0
	movl	-4(%rbp), %eax
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	mod
	movss	-8(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movss	-4(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm1, %rdx
	movq	%rdx, %rcx
	movq	%rcx, %xmm1
	movq	%rdx, %rcx
	movq	%xmm0, %rdx
	movq	%rdx, %r8
	movq	%r8, %xmm0
	movl	%eax, %r9d
	movapd	%xmm1, %xmm2
	movq	%rcx, %r8
	movapd	%xmm0, %xmm1
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movss	-8(%rbp), %xmm0
	movl	-4(%rbp), %eax
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	powr
	pxor	%xmm2, %xmm2
	cvtss2sd	%xmm0, %xmm2
	movss	-8(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movss	-4(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm2, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm2
	movq	%rax, %rcx
	movq	%xmm1, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	movq	%xmm0, %rax
	movq	%rax, %r8
	movq	%r8, %xmm0
	movapd	%xmm2, %xmm3
	movq	%rcx, %r9
	movapd	%xmm1, %xmm2
	movq	%rdx, %r8
	movapd	%xmm0, %xmm1
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-4(%rbp), %eax
	movd	%eax, %xmm0
	call	facto
	movss	-4(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rdx
	movq	%rdx, %rcx
	movq	%rcx, %xmm0
	movl	%eax, %r8d
	movapd	%xmm0, %xmm1
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-8(%rbp), %eax
	movd	%eax, %xmm0
	call	facto
	movss	-8(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rdx
	movq	%rdx, %rcx
	movq	%rcx, %xmm0
	movl	%eax, %r8d
	movapd	%xmm0, %xmm1
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 11.2.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	sum;	.scl	2;	.type	32;	.endef
	.def	mod;	.scl	2;	.type	32;	.endef
	.def	powr;	.scl	2;	.type	32;	.endef
	.def	facto;	.scl	2;	.type	32;	.endef
