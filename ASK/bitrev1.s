	.text
    .globl    bitrev
    .type    bitrev, @function

bitrev:
    rolq    $32, %rdi
    movq    %rdi, %rax

    movq     $0xFFFF0000FFFF0000, %r8
    andq    %r8, %rax
    shrq    $16, %rax
    notq    %r8
    andq    %rdi, %r8
    shlq    $16, %rdi
    orq        %rdi, %rax 
    movq    %rax, %rdi

    movq     $0xFF00FF00FF00FF00, %r8
    andq    %r8, %rax
    shrq    $8, %rax
    notq    %r8
    andq    %r8, %rdi
    shlq    $8, %rdi
    orq        %rdi, %rax 
    movq    %rax, %rdi

    movq     $0xF0F0F0F0F0F0F0F0, %r8
    andq    %r8, %rax
    shrq    $4, %rax
    notq    %r8
    andq    %r8, %rdi
    shlq    $4, %rdi
    orq        %rdi, %rax 
    movq    %rax, %rdi

    movq     $0xCCCCCCCCCCCCCCCC, %r8
    andq    %r8, %rax
    shrq    $2, %rax
    notq    %r8
    andq    %r8, %rdi
    shlq    $2, %rdi
    orq        %rdi, %rax 
    movq    %rax, %rdi

    movq     $0xAAAAAAAAAAAAAAAA, %r8
    andq    %r8, %rax
    shrq    $1, %rax
    notq    %r8
    andq    %r8, %rdi
    shlq    $1, %rdi
    orq        %rdi, %rax 
    ret

    .size    bitrev, .-bitrev
	