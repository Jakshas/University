        .text
        .globl  addsb
        .type   addsb, @function

/*
 * W moim rozwiązaniu używam następującej techniki: Używam wskazówki by dwa razy wyliczyć mod 17
 */

addsb:
        movq    %rdi,%rsi
        movq    $0x0f0f0f0f0f0f0f0f,%r11
        shr     $4,%rsi
        and     %r11,%rsi
        and     %r11,%rdi
        movq    %rsi,%r8
        movq    %rdi,%r9
        shr     $8,%r8
        shr     $8,%r9                        
        add     %r8,%rsi
        add     %r9,%rdi
        movq    $0x00ff00ff00ff00ff,%r11
        and     %r11,%rsi
        and     %r11,%rdi
        movq    %rsi,%r8
        movq    %rdi,%r9
        shr     $16,%r8
        shr     $16,%r9
        add     %r8,%rsi
        add     %r9,%rdi
        movq    $0x0000ffff0000ffff,%r11
        and     %r11,%rsi
        and     %r11,%rdi
        movq    %rsi,%r8
        movq    %rdi,%r9
        shr     $32,%r8
        shr     $32,%r9
        add     %r8,%rsi
        add     %r9,%rdi
        movq    $0x00000000ffffffff,%r11
        and     %r11,%rsi
        and     %r11,%rdi
        movq    %rdi, %rax
        ret
      
        cmp     %rdi,%rsi
	sbb     %rdi, %rsi
                mov     %rsi,%rax
        ret  
        mov     %rsi, %rax
	shr     $4, %rax
	and     $0xf, %rax
	and     $0xf, %rsi
	sub     %esi, %eax			
        
        sbb     %r11d, %r11d
	and     $0x11, %r11d
	add     %r11d, %eax	
        ret

        .size   addsb, .-addsb
