# Ćwiczenia 4, grupa TWI 10-12, 29 października 2020

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie X w odpowiedniej kolumnie! Jeśli pożądasz zreferować dane zadanie (co najwyżej jedno!) w trakcie dyskusji oznacz je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
|          Lista-zadanie | 3-1 |  3-2  | 3-3 |  3-4  |  3-5  |  3-6  |  3-7  |
| ----------------------:|:---:|:-----:|:---:|:-----:|:-----:|:-----:|:-----:|
|            Kamil Banaś |     |       |     |       |       |       |       |
|       Marcin Dąbrowski |  X  |   X   |     |   X   |   X   |   X   |   X   |
|            Kamil Galik |  X  |   X   |     |       |   X   |   X   |   X   |
|       Bartosz Głowacki |  X  |   X   |     |       |   X   |       |       |
|        Jakub Kaczmarek |  X  |   X   |     |   X   |   X   |   X   |   X   |
|           Karol Machoś |  X  |   X   |     |   X   |   X   |   X   | ==X== |
| Małgorzata Maciejewska |  X  |   X   |  X  |   X   |   X   |   X   |       |
|      Antoni Pokusiński |  X  |   X   |  X  | ==X== |   X   |   X   |        |
|           Mateusz Reis |  X  |   X   |     |       |   X   |       |   X   |
|            Rafał Spyra |  X  |   X   |  X  |       |       |       |       |
|          Adam Turowski |  X  |   X   |     |   X   |   X   |   X   |   X   |
|  Aleksander Uniatowicz |  X  |   X   |  X  |   X   | ==X== |   X   |   X   |
|          Jan Wańkowicz |  X  |   X   |     |       |   X   |   X   |   X   |
|   Krzysztof Wiśniewski |  X  |   X   |     |   X   |   X   |   X   |       |
|     Tomasz Woszczyński |  X  |       |  X  |       |   X   |       |       |
|            Jakub Zając |  X  |   X   |     |   X   |   X   | ==X== |   X   |
|          Paweł Zmarzły |  X  | ==X== |     |   X   |   X   |   X   |   X   |
|             Adam Zyzik |     |   X   |     |   X   |   X   |   X    |       |
:::

## Zadanie 3-1

:::danger
Autor: Kamil Galik
:::

Argumentacja przeciw fork():
- Z biegiem czasu działanie fork stało się zbyt skomplikowane. Nowe API tworzenia procesów dodawały do fork nowe specjalne sposoby (których POSIX wymienia 25) kopiowania stanu rodzica do dziecka.
- Fork nie komponuje się z implementacjami pewnych konceptów SO. Przykładowo buforowanie wejścia/wyjścia, przy którym musimy jawnie wyczyścić bufory przed dokonaniem forka.
- Nieudolność pracy forka z programami wielowątkowymi. Możliwy deadlock w momencie gdy jeden z wątków wykona forka i spróbuje zaalokować pamięć, którą alokuje inny wątek procesu rodzica.
- Fork zmusza programistę do zadbania o bezpieczeństwo oprogramowania. Jest odporny na randomizację przestrzeni adresowej, dzieli otwarte deskryptory plików i może czytać w odziedziczonej pamięci.
- Fork jest strasznie wolny. Mechanizm kopiowania przy zapisie, sprawia, że jego prędkość jest jakkolwiek akceptowalna. Nowsze aplikacje (np. bazowane na Node.js) zużywają wiele czasu na wykonywanie forków.

![](https://i.imgur.com/vkYSCRS.png)

- Fork utrudnia skalowalność systemu, której jednym z aspektów jest unikanie niepotrzebnego współdzielenia zasobów. Współdzielenie zawsze zachodzi między rodzicem i dzieckiem, co utrudnia implementację jądra m. in. możliwość szufladkowania zasobów.
- Częste użycie mechanizmu kopiowania przy odczycie stwarza zapotrzebowanie na używanie mechanizmu overcommit. Zakłada on, że wywołując fork mamy wystarczającą ilość pamięci, by móc skopiować dowolną stronę pamięci przy próbie zapisu do niej przez dziecko. Gdyby brakło pamięci, uruchamia się mechanizm zamykający procesy, aby zwolnić pamięć.

Jak posix_spawn() naprawia błędy:
- jest to połączenie fork i exec, więc nie musimy implementować działania kodu dziecka i rodzica w postaci jednej binarce, ale wciąż jesteśmy w stanie przekazać pewne parametry rodzica do nowego procesu.
- można przekazać funkcji argumenty: ścieżka pliku do załadowania, wskaźnik, do którego zostanie zapisanie PID, argumenty i środowisko, atrybuty wpływające na etap między fork i exec, które modyfikują działanie i zasoby dostępne dla procesu.
- użycie clone() zamiast fork, do kopiowania rodzica, co daje większą możliwość określenia, które zasoby będą współdzielone z rodzicem.

Procedura posix_spawn() korzysta z clone() z flagami 
- CLONE_VM, która sprawia, że zamiast kopiować całą przestrzeń adresową jest ona wspólna dla obu procesów, a to ogranicza błędy braku pamięci spowodowane memory overcommit
- CLONE_VFORK, która zatrzymuje działanie procesu-rodzica aż do zwolnienia zasobów pamięci wirtualnej.

## Zadanie 3-2

:::danger
Autor: Paweł Zmarzły
:::

Proces osierocony (rodzic zmarł, on nadal żyje) zostaje przepięty do `init`a (PID 1), lub innego żniwiarza.

```bash
strace -e trace=signal bash # właściwie bash by wystarczył
sleep 1000 &
ps ax -o pid,ppid,command | grep sleep
kill -KILL 0
ps ax -o pid,ppid,command | grep sleep
```

U mnie nowym rodzicem zostaje PID 2142.

```bash
$ cat /proc/2142/cmdline 
/lib/systemd/systemd --user
```

Przy SIGHUP podobnie, ale SIGHUP zostaje rozesłany przez `bash`a, więc zabije sleepa:

`info bash` -> "The shell exits by default upon receipt of a SIGHUP. Before exiting, an interactive shell resends the SIGHUP to all jobs, running or stopped. Stopped jobs are sent SIGCONT to ensure that they receive the SIGHUP."

## Zadanie 3-3

:::danger
Autor: Rafał Spyra
:::
```bash
stty -a
speed 38400 baud; rows 24; columns 80; line = 0;
intr = ^C; quit = ^\; erase = ^?; kill = ^U; eof = ^D; eol = <undef>;
eol2 = <undef>; swtch = <undef>; start = ^Q; stop = ^S; susp = ^Z; rprnt = ^R;
werase = ^W; lnext = ^V; discard = ^O; min = 1; time = 0;
-parenb -parodd -cmspar cs8 -hupcl -cstopb cread -clocal -crtscts
-ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr icrnl ixon -ixoff
-iuclc -ixany -imaxbel iutf8
opost -olcuc -ocrnl onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 vt0 ff0
isig icanon iexten echo echoe echok -echonl -noflsh -xcase -tostop -echoprt
echoctl echoke -flusho -extproc
```



## Zadanie 3-4

:::danger
Autor: Antoni Pokusiński
:::
Polecenie```cat -``` pobiera dane z *stdinput*, po czym od razu je wypisuje. Uruchomienie tego procesu w *background* oznacza, że nic nie może się znaleźć w *stdin* i do procesu zostaje wysłany ```SIGSTOP```

**Wbudowane polecenie powłoki**: polecenie interpretowane i wykonywane w samej powłoce, zamiast ładowania programu wykonywalnego.

```cat /etc/shells &``` wypisze zawartość pliku, po czym nastąpi zakończenie programu. Polecenie ```stty tostop``` wysyła sygnał *SIGTTOU* do procesów drugoplanowych, przez co zostaje dla nich zablokowane wypisywanie do terminala, więc nie zobaczymy nic po ponownym uruchomieniu  ```cat /etc/shells &```.

Wywołanie ```pid_t waitpid(pid_t pid, int *wstatus, int options)``` zapisuje do *wstatus* dane o zmianie stanu dziecka. Za pomocą makr ```WIFEXITED()```,```WIFSTOPPED()```,```WIFCONTINUED()``` można dostać informacje o tym, czy dziecko zakończyło się w zwykły sposób, zostało zatrzymane sygnałem, czy też otrzymało ```SIGCONT``` i kontynuuje działanie.

*(APUE 9.7)* 
Aby wybrać grupę pierwszoplanową (*foreground group*), możemy użyć funkcji 
```int tcsetpgrp(int fd, pid_t pgrpid);```. Ustawiając argument```pgrpid``` na odpowiednią wartość, zmieniamy grupę pierwszoplanową.

## Zadanie 3-5

:::danger
Autor: Aleksander Uniatowicz
:::


```c=
_JB_RBX = 0
_JB_RBP = 1
_JB_R12 = 2
_JB_R13 = 3
_JB_R14 = 4
_JB_R15 = 5
_JB_RSP = 6
_JB_RIP = 7

        .text

        .globl Setjmp
        .type Setjmp,@function
Setjmp:
	movq    (%rsp),  %r11 #// przenosimy aktualny adres powrotu  do r11, aby go potem zapisać jako adres powrotu
	movq    %rbx,    (_JB_RBX * 8)(%rdi) #// przenosimy rejestry do jmp_buf
	movq    %rbp,    (_JB_RBP * 8)(%rdi)
	movq    %r12,    (_JB_R12 * 8)(%rdi)
	movq    %r13,    (_JB_R13 * 8)(%rdi)
	movq    %r14,    (_JB_R14 * 8)(%rdi)
	movq    %r15,    (_JB_R15 * 8)(%rdi)
	movq    %rsp,    (_JB_RSP * 8)(%rdi)
	movq    %r11,    (_JB_RIP * 8)(%rdi)
	xorl	%eax,    %eax # zwracamy 0
	ret
        .size Setjmp, . - Setjmp
        
        .globl Longjmp
        .type Longjmp,@function
Longjmp:
	movq    (_JB_RBX * 8)(%rdi), %rbx #// przywracamy rejestry z jmp_buf 
	movq    (_JB_RBP * 8)(%rdi), %rbp
	movq    (_JB_R12 * 8)(%rdi), %r12
	movq    (_JB_R13 * 8)(%rdi), %r13
	movq    (_JB_R14 * 8)(%rdi), %r14
	movq    (_JB_R15 * 8)(%rdi), %r15
	movq    (_JB_RSP * 8)(%rdi), %rsp
	movq    (_JB_RIP * 8)(%rdi), %r11 
	movl	%esi, %eax   #// przenosimy 2gi argument do rax, i jeżeli jest 0. to zmieniamy na 1
	testl	%eax, %eax
	jnz	1f
	incl	%eax
1:	movq	%r11, (%rsp) #// przenosimy z r11 do rsp (bo tam wrzuciliśmy go kila lini wcześniej)
	ret
        .size Longjmp, . - Longjmp
```

https://stackoverflow.com/questions/11285365/why-does-setjmp3-not-save-all-registers-on-amd64

nie zapisjemy wszystkiego, bo zapisujemy tylko callee-saved registers, jak wiemy, program powinien być przygotowany, że setjmp() może popsuć rejestry caller-saved. 

wrzuca na stos, bo ret, z niego ściąga, i skacze w tamto miejsce

## Zadanie 3-6
:::warning
Autor: Jakub Zając
:::
:::info
Uzupełnij program *«game»* tj. prostą grę w szybkie obliczanie sumy dwóch liczb. Zadaniem procedury *«readnum»* jest wczytać od użytkownika liczbę. Jeśli w międzyczasie przyjdzie sygnał, to procedura ma natychmiast wrócić podając numer sygnału, który przerwał jej działanie. W przeciwnym przypadku zwraca zero i przekazuje wczytaną liczbę przez pamięć pod wskaźnikiem *«num_p»*. Twoja implementacja procedury *«readnum»* musi wczytać całą linię w jednym kroku! Należy wykorzystać procedury [*siglongjmp(3)*](https://man7.org/linux/man-pages/man3/siglongjmp.3.html), [*sigsetjmp(3)*](https://man7.org/linux/man-pages/man3/sigsetjmp.3.html) i [*alarm(2)*](https://man7.org/linux/man-pages/man2/alarm.2.html). Kiedy Twój program będzie zachowywać się poprawnie zamień procedury **nielokalnych skoków** na [*longjmp(3)*](https://man7.org/linux/man-pages/man3/longjmp.3.html) i [*setjmp(3)*](https://man7.org/linux/man-pages/man3/setjmp.3.html). Czemu program przestał działać?
:::danger
***UWAGA!*** W FreeBSD i macOS zamiast *«longjmp»* i *«setjmp»* należy użyć odpowiednio *«_longjmp»* i *«_setjmp»*.
:::


```c=
static void signal_handler(int signo)
{
     siglongjmp(env, signo);
}

static int readnum(int *num_p)
{
    char line[MAXLINE];
    int n;

    alarm(1);
    n = sigsetjmp(env);

    if(n)
    {
        *num_p = 0;
        return n;
    }
    
    Read(STDIN_FILENO, line, MAXLINE);
    *num_p = atoi(line);
    
    return 0;
}
```

Problem pojawia się przy *«longjmp»* i *«setjmp»* ponieważ w standardzie nie jest określone czy te funkcje zachowują maskę bitów.

## Zadanie 3-7

:::danger
Autor: Karol Machoś
:::

### Uzupełniony kod zadania:

```c=
#include "queue.h"
#include "csapp.h"

#define CORO_STKSIZE 4096
#define CORO_STKALIGN 16 /* As required by SysV ABI ! */

#ifndef EOF
#define EOF (-1)
#endif

#ifndef NOTHING
#define NOTHING (-2)
#endif

typedef struct coro {
  TAILQ_ENTRY(coro) co_link;
  const char *co_name;
  void *co_stack;
  Jmpbuf co_ctx;
} coro_t;

static TAILQ_HEAD(, coro) runqueue = TAILQ_HEAD_INITIALIZER(runqueue);
static coro_t *running;
static Jmpbuf dispatcher;

/* Initialize coroutine stucture with stack. */
static void coro_init(coro_t *co, const char *name) {
  memset(co, 0, sizeof(coro_t));
  co->co_name = name;
  /* Allocates a fresh stack for the coroutine! */
  if (posix_memalign(&co->co_stack, CORO_STKALIGN, CORO_STKSIZE) < 0)
    unix_error("posix_memalign error");
}

/* Detach a stack from coroutine structure. */
static void coro_destroy(coro_t *co) {
  free(co->co_stack);
}

/*
 * Switch between subsequent coroutines.
 *
 * Dead coroutines, i.e. ones that returned EOF, get removed from the run queue.
 * Feed next coroutine (value returned from coro_yield) with the result from
 * previous one (parameter passed to coro_yield).
 * Return to dispatcher if there're no more coroutines to run.
 */
static noreturn void coro_switch(int v) {
  coro_t *curr = running;
  /* TODO: Use description above to implement the body. */
  if(v==EOF)
  {
    TAILQ_REMOVE(&runqueue,curr,co_link);
    if(TAILQ_EMPTY(&runqueue))
    {
      Longjmp(dispatcher,NOTHING);
    }
  }
  if(TAILQ_NEXT(curr,co_link)==NULL)
  {
    running=TAILQ_FIRST(&runqueue);
    Longjmp(TAILQ_FIRST(&runqueue)->co_ctx,v);
  }
  running=TAILQ_NEXT(curr,co_link);
  Longjmp(running->co_ctx,v);
}

/* Save caller context and switch back to next coroutine. */
static int coro_yield(int v) {
  int nv = Setjmp(running->co_ctx);
  if (nv == 0)
    coro_switch(v);
  return nv;
}

/* Configure coroutine context to be executed. */
static void coro_add(coro_t *co, void (*fn)(int)) {
  int v = Setjmp(co->co_ctx);
  if (v) {
    /* This will get executed when coroutine is entered first time. */
    fn(v);
    /* Coroutine must pass EOF to be removed from runqueue! */
    coro_switch(EOF);
  }
  /* Coroutine will be running on its private stack! */
  co->co_ctx->rsp = co->co_stack + CORO_STKSIZE;
  TAILQ_INSERT_TAIL(&runqueue, co, co_link);
}

/* Take first coroutine and feed it with passed value. */
static int coro_run(int v) {
  running = TAILQ_FIRST(&runqueue);
  int nv = Setjmp(dispatcher);
  if (nv == 0)
    Longjmp(running->co_ctx, v);
  return nv;
}

/*
 * Actual coroutines that perform some useful work.
 */

static void func_1(int _) {
  int words = 0;
  char prev_ch = ' ';
  char ch;

  while (Read(0, &ch, 1) > 0) {
    if (isspace(ch)) {
      if (isspace(prev_ch))
        continue;
      words++;
    }
    coro_yield(ch);
    prev_ch = ch;
  }

  if (!isspace(ch))
    words++;

  dprintf(STDERR_FILENO, "\nfunc_1: words = %d\n", words);
}

static void func_2(int ch) {
  int removed = 0;

  while (ch != EOF) {
    if (!isalpha(ch)) {
      removed++;
      ch = NOTHING;
    }
    ch = coro_yield(ch);
  }
 
  dprintf(STDERR_FILENO, "func_2: removed = %d\n", removed);
}

static void func_3(int ch) {
  int printed = 0;

  while (ch != EOF) {
    if (ch != NOTHING) {
      printed++;
      if (islower(ch))
        ch = toupper(ch);
      else if (isupper(ch))
        ch = tolower(ch);
      Write(STDOUT_FILENO, &ch, 1);
    }
    ch = coro_yield(NOTHING);
  }

  dprintf(STDERR_FILENO, "func_3: printed = %d\n", printed);
}

int main(void) {
  coro_t co[3];

  coro_init(&co[0], "func_1");
  coro_init(&co[1], "func_2");
  coro_init(&co[2], "func_3");
  coro_add(&co[0], func_1);
  coro_add(&co[1], func_2);
  coro_add(&co[2], func_3);
  coro_run(NOTHING);
  coro_destroy(&co[0]);
  coro_destroy(&co[1]);
  coro_destroy(&co[2]);

  dprintf(STDERR_FILENO, "Bye, bye!\n");

  return EXIT_SUCCESS;
}
```

