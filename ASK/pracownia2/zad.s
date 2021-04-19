        .text
        .globl  addsb
        .type   addsb, @function

/*
 * W moim rozwiązaniu używam następującej techniki: zamiany wszytskich 
 */

addsb:
        movq    %rdi,%r8
        shr     $1,%r8
        or      %r8,%rdi        
        movq    %rdi,%r8
        shr     $2,%r8
        or      %r8,%rdi
        movq    %rdi,%r8
        shr     $4,%r8
        or      %r8,%rdi
        movq    %rdi,%r8
        shr     $8,%r8
        or      %r8,%rdi
        movq    %rdi,%r8
        shr     $16,%r8
        or      %r8,%rdi
        movq    %rdi,%r8
        shr     $32,%r8
        or      %r8,%rdi
        not     %rdi
        movq    %rdi,%rax
        
        movq    $0x5555555555555555,%r9
        shr     $1,%rdi
        and     %r9,%rdi
        sub     %rdi,%rax
        movq    %rax,%rdi
        movq    $0x3333333333333333,%r9
        shr     $2,%rdi
        and     %r9,%rax
        and     %r9,%rdi
        add     %rax,%rdi
        movq    %rdi,%rax
        movq    $0x0f0f0f0f0f0f0f0f,%r9
        shr     $4,%rdi
        add     %rax,%rdi
        and     %r9,%rdi
        movq    %rdi,%rax
        movq    $0x00ff00ff00ff00ff,%r9
        shr     $8,%rdi
        add     %rax,%rdi
        and     %r9,%rdi
        movq    %rdi,%rax
        movq    $0x0000ffff0000ffff,%r9
        shr     $16,%rax
        add     %rax,%rdi
        and     %r9,%rdi
        movq    %rdi,%rax
        movq    $0x00000000ffffffff,%r9
        shr     $32,%rax
        and     %r9,%rax

        ret

        .size   addsb, .-addsb
