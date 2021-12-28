	.text
    .globl    bitrev
    .type    bitrev, @function


bitrev:
		rolq 	$32,%rdi

		movq	%rdi,%r11
		movq	$0x0000FFFF0000FFFF,%r9
		andq 	%r9,%r11
		shlq 	$16,%r11
		notq	%r9
		andq 	%r9,%rdi
		shrq 	$16,%rdi
		orq 	%r11,%rdi

		movq	%rdi,%r11
		movq	$0x00FF00FF00FF00FF,%r9
		andq 	%r9,%r11
		shlq 	$8,%r11
		notq	%r9
		andq 	%r9,%rdi
		shrq 	$8,%rdi
		orq 	%r11,%rdi

		movq	%rdi,%r11
		movq	$0x0F0F0F0F0F0F0F0F,%r9
		andq 	%r9,%r11
		shlq 	$4,%r11
		notq	%r9
		andq 	%r9,%rdi
		shrq 	$4,%rdi
		orq 	%r11,%rdi

		movq	%rdi,%r11
		movq	$0x3333333333333333,%r9
		andq 	%r9,%r11
		shlq 	$2,%r11
		notq	%r9
		andq 	%r9,%rdi
		shrq 	$2,%rdi
		orq 	%r11,%rdi

		movq	%rdi,%r11
		movq	$0x5555555555555555,%r9
		andq 	%r9,%r11
		shlq 	$1,%r11
		notq	%r9
		andq 	%r9,%rdi
		shrq 	$1,%rdi
		orq 	%r11,%rdi
		movq 	%rdi,%rax
	ret

	.size    bitrev, .-bitrev
	