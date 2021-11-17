/*
 * UWAGA! W poniższym kodzie należy zawrzeć krótki opis metody rozwiązania
 *        zadania. Będzie on czytany przez sprawdzającego. Przed przystąpieniem
 *        do rozwiązywania zapoznaj się dokładnie z jego treścią. Poniżej należy
 *        wypełnić oświadczenie o samodzielnym wykonaniu zadania.
 *
 * Oświadczam, że zapoznałem(-am) się z regulaminem prowadzenia zajęć
 * i jestem świadomy(-a) konsekwencji niestosowania się do podanych tam zasad.
 *
 * Imię i nazwisko, numer indeksu: Jakub Szajner, 315700
 */

        .text
        .globl  clz
        .type   clz, @function

/*
 * W moim rozwiązaniu używam następującej techniki: zamieniam wszytskie pierwsze zera na jedynki a póznej zliczam te jedynki 
 */

clz:
        movq    %rdi,%r8                        /* wykozystując metode dziel i zwycieżaj ustawiam wszystki pozostałe bity po pierwszej 1 na 1 przesuwając o kolejne potegi 2 liczbe i orując to z posiadaną uroszczoną liczbą */
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
        movq    %rdi,%rax                       /* na końcu zostają same jedynki tam gdzie wczesniej były zera przez negacje tej liczby która na koncu zostaje */
        
        movq    $0x5555555555555555,%r9         /* nastepnie wykonujemy popcounta uproszczonego */
        shr     $1,%rdi                         /* kożystamy z tego że odejmując w pierszym kroku otrzymamy taki sam wynik jak wykonując zwykłe andowanie z maską i dodawanie bo bitowo 11-01=10 <-> 10+01=11 itd. */
        and     %r9,%rdi
        sub     %rdi,%rax
        movq    %rax,%rdi
        movq    $0x3333333333333333,%r9         /* ten krok jest taki sam z normalnym popcountem */
        shr     $2,%rdi
        and     %r9,%rax
        and     %r9,%rdi
        add     %rax,%rdi
        movq    %rdi,%rax
        movq    $0x0f0f0f0f0f0f0f0f,%r9         /* kozystamy z tego że nie wystąpi nam zaden overflow w tych 4 bo z 4 bitów max wartość to 4 czyli 0100 */
        shr     $4,%rdi
        add     %rax,%rdi
        and     %r9,%rdi
        movq    %rdi,%rax                       /* później poprostu dodajemy te wartości pokopli i na samym koncu wyciagamy tylko te bity któe nas interesuja */
        shr     $8,%rdi
        add     %rax,%rdi
        movq    %rdi,%rax
        shr     $16,%rax
        add     %rax,%rdi
        movq    %rdi,%rax
        shr     $32,%rax
        add     %rdi,%rax
        movq    $0x7f,%r9
        and     %r9,%rax
        ret

        .size   clz, .-clz
        