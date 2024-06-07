	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_p_w                    ## -- Begin function p_w
	.p2align	4, 0x90
_p_w:                                   ## @p_w
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	$1000, -12(%rbp)        ## imm = 0x3E8
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -12(%rbp)
	jl	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-12(%rbp), %ecx
	addl	$-1, %ecx
	movl	%ecx, -12(%rbp)
	movl	$400, %edi              ## imm = 0x190
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_usleep
	jmp	LBB0_1
LBB0_3:
	xorl	%eax, %eax
                                        ## kill: def $rax killed $eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_p_h                    ## -- Begin function p_h
	.p2align	4, 0x90
_p_h:                                   ## @p_h
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	$1000, -12(%rbp)        ## imm = 0x3E8
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -12(%rbp)
	jl	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-12(%rbp), %ecx
	addl	$-1, %ecx
	movl	%ecx, -12(%rbp)
	movl	$400, %edi              ## imm = 0x190
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_usleep
	jmp	LBB1_1
LBB1_3:
	xorl	%eax, %eax
                                        ## kill: def $rax killed $eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -8(%rbp)
	movl	$0, -116(%rbp)
	leaq	-136(%rbp), %rdi
	movq	%rcx, %rsi
	leaq	_p_h(%rip), %rdx
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB2_2
## %bb.1:
	movl	$1, %edi
	callq	_exit
LBB2_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	-128(%rbp), %rdi
	movq	%rcx, %rsi
	leaq	_p_w(%rip), %rdx
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB2_4
## %bb.3:
	movl	$1, %edi
	callq	_exit
LBB2_4:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-128(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB2_6
## %bb.5:
	movl	$1, %edi
	callq	_exit
LBB2_6:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-136(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB2_8
## %bb.7:
	movl	$1, %edi
	callq	_exit
LBB2_8:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB2_10
## %bb.9:
	xorl	%eax, %eax
	addq	$144, %rsp
	popq	%rbp
	retq
LBB2_10:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"t ==> 1\n"

L_.str.1:                               ## @.str.1
	.asciz	"t ==> 2\n"

.subsections_via_symbols
