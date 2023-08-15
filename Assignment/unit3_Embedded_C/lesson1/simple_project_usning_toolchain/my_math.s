	.file	"my_math.c"
	.text
	.globl	sum
	.def	sum;	.scl	2;	.type	32;	.endef
	.seh_proc	sum
sum:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	16(%rbp), %xmm0
	addss	24(%rbp), %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.globl	sub
	.def	sub;	.scl	2;	.type	32;	.endef
	.seh_proc	sub
sub:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	16(%rbp), %xmm0
	subss	24(%rbp), %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.globl	mul
	.def	mul;	.scl	2;	.type	32;	.endef
	.seh_proc	mul
mul:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	16(%rbp), %xmm0
	mulss	24(%rbp), %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.globl	div
	.def	div;	.scl	2;	.type	32;	.endef
	.seh_proc	div
div:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -4(%rbp)
	pxor	%xmm0, %xmm0
	ucomiss	24(%rbp), %xmm0
	jp	.L11
	pxor	%xmm0, %xmm0
	ucomiss	24(%rbp), %xmm0
	je	.L8
.L11:
	movss	16(%rbp), %xmm0
	divss	24(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
.L8:
	movss	-4(%rbp), %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	mod
	.def	mod;	.scl	2;	.type	32;	.endef
	.seh_proc	mod
mod:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movl	$0, -4(%rbp)
	pxor	%xmm0, %xmm0
	ucomiss	24(%rbp), %xmm0
	jp	.L16
	pxor	%xmm0, %xmm0
	ucomiss	24(%rbp), %xmm0
	je	.L13
.L16:
	movss	16(%rbp), %xmm0
	call	is_integer
	testb	%al, %al
	je	.L13
	movl	24(%rbp), %eax
	movd	%eax, %xmm0
	call	is_integer
	testb	%al, %al
	je	.L13
	movss	16(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	24(%rbp), %xmm0
	cvttss2sil	%xmm0, %ecx
	cltd
	idivl	%ecx
	movl	%edx, -4(%rbp)
.L13:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	powr
	.def	powr;	.scl	2;	.type	32;	.endef
	.seh_proc	powr
powr:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	jmp	.L18
.L19:
	movss	-4(%rbp), %xmm0
	mulss	16(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
.L18:
	movss	24(%rbp), %xmm0
	movss	.LC1(%rip), %xmm2
	movaps	%xmm0, %xmm1
	subss	%xmm2, %xmm1
	movss	%xmm1, 24(%rbp)
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L19
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jne	.L19
	movss	-4(%rbp), %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	squr
	.def	squr;	.scl	2;	.type	32;	.endef
	.seh_proc	squr
squr:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	movl	$100, -8(%rbp)
	jmp	.L24
.L25:
	movss	-4(%rbp), %xmm0
	mulss	%xmm0, %xmm0
	movaps	%xmm0, %xmm1
	subss	16(%rbp), %xmm1
	movss	-4(%rbp), %xmm0
	addss	%xmm0, %xmm0
	divss	%xmm0, %xmm1
	movss	-4(%rbp), %xmm0
	subss	%xmm1, %xmm0
	movss	%xmm0, -4(%rbp)
.L24:
	movl	-8(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -8(%rbp)
	testl	%eax, %eax
	jne	.L25
	movss	-4(%rbp), %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	c_area
	.def	c_area;	.scl	2;	.type	32;	.endef
	.seh_proc	c_area
c_area:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	.LC2(%rip), %xmm1
	movss	16(%rbp), %xmm0
	call	powr
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movsd	.LC3(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	facto
	.def	facto;	.scl	2;	.type	32;	.endef
	.seh_proc	facto
facto:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movl	$1, -4(%rbp)
	movss	16(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	comiss	%xmm1, %xmm0
	jb	.L30
	movss	16(%rbp), %xmm0
	call	is_integer
	testb	%al, %al
	je	.L30
	movl	$1, -8(%rbp)
	jmp	.L32
.L35:
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L32:
	movl	-8(%rbp), %eax
	testq	%rax, %rax
	js	.L33
	pxor	%xmm0, %xmm0
	cvtsi2ssq	%rax, %xmm0
	jmp	.L34
.L33:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2ssq	%rdx, %xmm0
	addss	%xmm0, %xmm0
.L34:
	movss	16(%rbp), %xmm1
	comiss	%xmm0, %xmm1
	jnb	.L35
.L30:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	is_integer
	.def	is_integer;	.scl	2;	.type	32;	.endef
	.seh_proc	is_integer
is_integer:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	16(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movl	%eax, -4(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-4(%rbp), %xmm0
	divss	16(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC1:
	.long	1065353216
	.align 4
.LC2:
	.long	1073741824
	.align 8
.LC3:
	.long	1413754602
	.long	1074340347
	.ident	"GCC: (GNU) 11.2.0"
