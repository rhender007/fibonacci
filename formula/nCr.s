#Rob Henderson Cs211 Rutgers University TA:Binh Pham
.globl nCr
	.type	nCr, @function
nCr:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)#to top of stack
	#pushl   %eax
	call	Factorial
	cmpl	$0,%eax
	jne	.L11 #if equal
	je	.L12 #if not equal

.L11:
	movl	%eax, -24(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	Factorial
	cmpl	$0, %eax
	jne	.L2
.L12:
	movl	$0, -24(%ebp)
	#movl	12(%ebp), %eax
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	jmp	.L13
		
	
.L2:
	movl	%eax, -20(%ebp)
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, (%esp)
	call	Factorial
	movl	%eax, -16(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	-16(%ebp)
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	-20(%ebp)
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	jmp .L13

.L13:
	leave
	ret

.globl Factorial
	.type Factorial, @function
Factorial:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jg	.L4
	movl	$1, %eax
	#movl	$0, %eax
	jmp	.L5
.L4:
	movl	8(%ebp), %eax
	subl	$1, %eax #eax = eax-1
	movl	%eax, (%esp) #eax to top of stack to call Factorial
	call	Factorial
	movl	8(%ebp), %edx
	imull	%edx, %eax #multiply; need to check for overflow right after here

	#movl	%eax, 8(%ebp)
	#movl	8(%ebp), %eax
	jO .L10#if overflow, we need to signify it

	#else, just return the val
	#movl	%eax, 8(%ebp)
	#movl	8(%ebp), %eax
	#movl	
	jmp .L5
	

.L10:
	#movl	$0, 8(%ebp)
	#movl	8(%ebp), %eax
	movl	$0, %eax
	jmp .L5
.L5:
	leave
	ret
	#.size	Factorial, .-Factorial






