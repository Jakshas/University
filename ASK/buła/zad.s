        .text
        .globl  addsb
        .type   addsb, @function

/*
 * W moim rozwiązaniu używam następującej techniki: zamiany wszytskich 
 */

addsb:
        movq %rdx, %r10
        movq %rdi,%rax
        mulq %rsi
        mov %rax, %rdi
        mov %rcx, %rax
        mulq %r10
        sub %rax, %rdi
        mov %rdi, %rax
        ret

        .size   addsb, .-addsb
