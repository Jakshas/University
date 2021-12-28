# Ćwiczenia 3, grupa TWI 10-12, 22 października 2020

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie X w odpowiedniej kolumnie! Jeśli pożądasz zreferować dane zadanie (co najwyżej jedno!) w trakcie dyskusji oznacz je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
|          Lista-zadanie | 2-1 | 2-2 |  2-3  |  2-4  |  2-5  |  2-6  |  2-7  |
| ----------------------:|:---:|:---:|:-----:|:-----:|:-----:|:-----:|:-----:|
|            Kamil Banaś |     |     |       |       |       |       |       |
|       Marcin Dąbrowski |  X  |  X  |   X   |   X   |       |   X   |   X   |
|            Kamil Galik |  X  |  X  | ==X== |   X   |   X   |       |       |
|       Bartosz Głowacki |  X  |  X  |   X   |   X   |       |       |       |
|        Jakub Kaczmarek |     |     |       |       |       |       |       |
|           Karol Machoś |  X  |  X  |   X   |   X   |       |   X   |       |
| Małgorzata Maciejewska |  ==X==  |  X  |   X   |   X   |   X   |    X   |       |
|      Antoni Pokusiński |  X  |  X  |   X   |   X   |   X   |   X   |       |
|           Mateusz Reis |  X  |  X  |       |   X   |   X   |   X   |       |
|            Rafał Spyra |  X  |  X  |   X   |       |       |       |       |
|          Adam Turowski |  X  |  X  |   X   |   X   |       |       | ==X== |
|  Aleksander Uniatowicz |  X  |  X  |   X   |   X   |   X   | ==X== |   X   |
|          Jan Wańkowicz |  X  |  X  |   X   | ==X== |   X   |   X   |       |
|   Krzysztof Wiśniewski |  X  |  X  |   X   |   X   |       |   X   |       |
|     Tomasz Woszczyński |  X  |  X  |   X   |   X   |   X   |   X   |       |
|            Jakub Zając |  X  |  X  |   X   |   X   | ==X== |       |       |
|          Paweł Zmarzły |  X  |  X  |   X   |   X   | ==X== |   X   |   X   |
|             Adam Zyzik |     |     |       |       |   X    |   X    |       |
:::

Alternatywne rozwiązania zadań proszę umieszczać pomiędzy znacznikami „spoiler”, np. tak:
:::spoiler
tekst alternatywnego rozwiązania
:::

Uwagi i pytania proszę umieszczać wraz z podpisem za pomocą znacznika „>”, np. tak:
> [name=Jan Niezbędny] Czy to jest ważne?

## Zadanie 2-1

:::danger
Autor: Małgorzata Maciejewska
:::
https://sgp1.digitaloceanspaces.com/proletarian-library/books/5b0c7356751347504e2f6ce19e42d218.pdf

stany procesu -- executing, ready, suspended, stopped, zombie

running - ready, executing, proces albo się wykonuje, albo jest gotowy do wykonania

interuptible -- przerywalny -- zawieszony proces czeka na jakąś operację (np I/O), osiągalność pewnych zasobów lub sygnał od innego procesu

uninterruptible -- zawieszony proces czeka na warunki hardweru i nie obsuguje żadnych sygnałów

stopped -- zatrzymany -- może być wzwnowony tyko przez akcję innego procesu (np. debugowanie)

zombie -- prces, który został unicestwiony, ale z jakiejś przyczyny ciągle ma swoje zadania w strukturze zadań w tablicy zadań

Akcje wyzwalające zmianę stanów -- sygnał, zdarzenie, scheduling, unicestwienie (sygnał)

Różnica między snem nieprzyrywanym a przeywanym jest taka, że nieprzerywany nie obsługuje żadnych sygnałów.

Proces nie może zablokować lub zignorować SIGKILL.

Ignorownie -- informacja o wystąpieniu sygnału jest tracona 
Blokowanie -- fakt wystąpienia sygnału jest odnotowywany i sygnał może być obsułużony po odblokowaniu.
![](https://i.imgur.com/JMIWPbk.jpg)


## Zadanie 2-2

:::danger
Autor: Karol Machoś
:::

![](https://i.imgur.com/sULJkhf.png)
### Tworzenie procesu - Linux

Na początku następuje przepisanie większości zawartości opisującej proces, z rodzica do dziecka. Następnie przypisywany jest **PID**. Wypełniane są pola w **task_struct**, wskazujące na poprzedni i następny proces. Następuje alokacja pamięci dla danych dziecka, segmentów itp. Segment **.text** może być skopiowany$^*$ do pamięci lub współdzielony przez więcej procesów. Proces może zostać uruchomiony. Zostaje utworzona przestrzeń adresowa procesu. Nic jednak nie zostaje załadowane do tablicy stron, przez co następuje **page fault**, który doprowadza do załadowania kodu z pliku wykonywalnego. Na zakończenie, na stos, kopiowane są argumenty, środowisko. Dochodzi do zresetowania sygnłów oraz wypełnienia rejestrów zerami. 

**fork()** - tworzenie kopii rodzica różniącej się jedynie PID, PPID, deskryptorami (np. plików)

**execve()** - tworzenie nowej przestrzeni adresowej, przekazanie argumentów i środowiska, zresetowanie sygnałów i rejestrów, załadowanie kodu z dysku

*Kopiowanie jest kosztowne, więc system korzysta z **kopiowania przy zapisie**. Polega to na tym, że początkowo wejścia w tablicy stron dziecka są takie same jak u rodzica. Jedyną różnicą jest to, że są one w trybie read-only. W momencie próby zapisu dochodzi do **protection fault**, co sprawia, że nowa strona zostaje zaalokowana w trybie read/write. 

### Tworzenie procesu - Windows NT

Wywołany zostaje **Win32 CreateProcess**. Następnie zostaje wyszukana ścieżka do pliku wykonywalnego. Wywoływane jest **NtCreateUserProcess**, które przechodzi w tryb jądra. Otwarty zostaje obraz programu, który pozwala na zmapowanie programu do pamięci wirtualnej nowego procesu. Zostaje zaalokowany i zainicjalizowany obiekt procesu. Następuje stworzenie pamięci adresowej procesu. Tworzona jest **handle table**, mapowana jest dzielona strona użytkownika. Alokowana jest pamięć wirtualna, przekazywane są parametry i środowisko. Proces otrzymuje **ID**. Inicjalizowany jest wątek, który następnie otrzymuje swoje ID. Proces zostaje dodany do globalnej listy procesów. Następuje powrót do trybu użytkownika. Proces zostaje zarejestrowany w csrss.exe. Wyświetlany jest kursor z klapsydrą (oczekiwnaie).

## Zadanie 2-3

:::danger
Autor: Kamil Galik
:::

(Z APUE 8.3) przy forku wspólne są:
- open files
- Real user ID, real group ID, effective user ID, and effective group ID
- Supplementary group IDs
- Process group ID
- Session ID
- Controlling terminal
- The set-user-ID and set-group-ID flags
- Current working directory
- Root directory
- File mode creation mask
- Signal mask and dispositions
- The close-on-exec flag for any open file descriptors
- Environment
- Attached shared memory segments
- Memory mappings
- Resource limits

(Z APUE 8.10) przy exec dziedziczone są:
- Controlling terminal
- Time left until alarm clock
- Current working directory
- Root directory
- File mode creation mask
- File locks
- Process signal mask
- Pending signals
- Resource limits
- Nice value (on XSI-conformant systems; see Section 8.16)
- Values for tms_utime, tms_stime, tms_cutime, and tms_cstime

Bufory stdio opróżniamy, aby nie wystąpiła sytuacja wypisania bufora dwa razy, ponieważ jest ono kopiowane podczas fork.

Ustawiamy mechanizm obsługi sygnałów na domyślny, ponieważ przy użyciu execve funkcje będące signal handlerami są niewidoczne w pamięci.


## Zadanie 2-4

:::danger
Autor: Jan Wańkowicz
:::

**Który sygnał jest wysyłany domyślnie?**

Program kill wysyła sygnały domyślnie wysyłany jest sygnał SIGTERM, który powoduje bezpieczne zamknięcie procesu. 

**Sygnały oczekujące -**   sygnał  jest  nazywany  oczekującym,  jeżeli  został już wygenerowany, ale nie został jeszcze dostarczony. Każdy wątek procesu ma swoją niezależną maskę sygnałów, określającą zbiór sygnałów obecnie blokowanych  przez wątek.

**Co opisują pozostałe pola pliku «status» dotyczące sygnałów?**

**SigQ:** Pole  zawiera  dwie  liczby  oddzielone  ukośnikiem,  które odnoszą się do skolejkowanych sygnałów do  realnego  identyfikatora  użytkownika  tego  procesu. Pierwsza   jest   liczbą  aktualnie  skolejkowanych  sygnałów  do  tego  realnego identyfikatora użytkownika, a druga jest limitem  zasobów  liczby  skolejkowanych sygnałów do tego procesu 

**SigPnd, ShdPnd:** Maska bitowa sygnałów oczekujących na wątek i na proces 

**SigBlk, SigIgn, SigCgt:** Maski oznaczające zablokowane, zignorowane i przechwycone sygnały

**Który sygnał zostanie dostarczony jako pierwszy po wybudzeniu procesu?**

Sygnały zostaja dostarczone zgodnie z kolejnościa, w jakiej wystepuja w masce. Kolejnosc ta mozna wyswietlic przy pomocy komendy `kill -l`.

## Zadanie 2-5

:::danger
Autor: Paweł Zmarzły
:::

```c=
#include "csapp.h"

static pid_t spawn(void (*fn)(void))
{
  pid_t pid = Fork();
  if (pid == 0)
  {
    fn();
    printf("(%d) I'm done!\n", getpid());
    exit(EXIT_SUCCESS);
  }
  return pid;
}

static void grandchild(void)
{
  printf("(%d) Waiting for signal!\n", getpid());
  /* TODO: Something is missing here! */
  pause();
  printf("(%d) Got the signal!\n", getpid());
}

static void child(void)
{
  pid_t pid;
  /* TODO: Spawn a child! */
  setpgrp();
  pid = spawn(grandchild);
  printf("(%d) Grandchild (%d) spawned!\n", getpid(), pid);
}

/* Runs command "ps -o pid,ppid,pgrp,stat,cmd" using execve(2). */
static void ps(void)
{
  /* TODO: Something is missing here! */
  char *argv[] = {"ps", "-o", "pid,ppid,pgrp,stat,cmd", NULL};
  // execvp - sprawdza PATH, używa envp = environ
  execvp(argv[0], argv);
}

int main(void)
{
  /* TODO: Make yourself a reaper. */
#ifdef LINUX
  Prctl(PR_SET_CHILD_SUBREAPER, 1);
#endif
  printf("(%d) I'm a reaper now!\n", getpid());

  pid_t pid, pgrp;
  int status;

  /* TODO: Start child and grandchild, then kill child!
   * Remember that you need to kill all subprocesses before quit. */
  printf("(%d) Spawning child\n", getpid());
  pid = spawn(child);
  waitpid(pid, &status, 0);
  printf("(%d) Child quit with %d\n", getpid(), status);
  pgrp = -pid;

  printf("(%d) Spawning ps\n", getpid());
  pid = spawn(ps);
  waitpid(pid, &status, 0);
  printf("(%d) ps quit with %d\n", getpid(), status);

  printf("(%d) Killing grandchild\n", getpid());
  kill(pgrp, SIGINT);
  waitpid(pgrp, &status, 0);
  printf("(%d) Granchild quit with %d\n", getpid(), status);

  return EXIT_SUCCESS;
}
```

```
(13458) I'm a reaper now!
(13458) Spawning child
(13459) Grandchild (13460) spawned!
(13459) I'm done!
(13460) Waiting for signal!
(13458) Child quit with 0
(13458) Spawning ps
    PID    PPID    PGRP STAT CMD
   8015    5527    8015 Ss   /usr/bin/zsh
  13458    8015   13458 S+   ./reaper
  13460   13458   13459 S    ./reaper
  13461   13458   13458 R+   ps -o pid,ppid,pgrp,stat,cmd
(13458) ps quit with 0
(13458) Killing grandchild
(13458) Granchild quit with 2
```

## Zadanie 2-6

:::danger
Autor: Aleksander Uniatowicz
:::

```c=
static void play(pid_t next, const sigset_t *set)
{

   for (;;)
   {
      printf("(%d) Waiting for a ball!\n", getpid());
      /* TODO: Something is missing here! */
      sigsuspend(set);

      usleep((300 + random() % 400) * 1000);
      Kill(next, SIGUSR1);
      printf("(%d) Passing ball to (%d)!\n", getpid(), next);
   }
int main(int argc, char *argv[])
{
   if (argc != 2)
      app_error("Usage: %s [CHILDREN]", argv[0]);

   int children = atoi(argv[1]);

   if (children < 4 || children > 20)
      app_error("Give number of children in range from 4 to 20!");

   /* Register signal handler for SIGUSR1 */
   sigset_t mask;
   sigfillset(&mask);
   sigdelset(&mask, SIGINT);

   sigprocmask(SIG_SETMASK, &mask, NULL);

   struct sigaction action = {.sa_sigaction = signal_handler};

   Sigaction(SIGINT, &action, NULL);
   Sigaction(SIGUSR1, &action, NULL);
   int parent_pid = getpid();
   printf("parend pid: %d\n", parent_pid);
   int pids[21];
   /* TODO: Start all processes and make them wait for the ball! */

   sigset_t mask2;
   sigfillset(&mask2);

   sigdelset(&mask2, SIGINT);
   sigdelset(&mask2, SIGUSR1);

   for (int i = 0; i < children; i++)
   {

      pid_t pid = fork();
      if (!pid)
      {
         play(i ? pids[i - 1] : parent_pid, &mask2);
      }
      else
      {
         pids[i] = pid;
      }
   }

   Kill(pids[children - 1], SIGUSR1);

   play(pids[children - 1], &mask2);

   return EXIT_SUCCESS;
}



```


## Zadanie 2-7

:::danger
Autor: Adam Turowski
:::

![](https://i.imgur.com/OVXsEv4.png)

**Procedury wielobieżne** - takie, które mogą być przerwane podczas wykonywania, a później bezpiecznie wznowione.

```c=
static void sigsegv_handler(int signum, siginfo_t *info, void *data) {
  ucontext_t *uc = data;

  /* TODO: You need to get value of instruction pointer register from `uc`.
   * Print all useful data from `info` and quit in such a way that a shell
   * reports program has been terminated with SIGSEGV. */

  greg_t rip_addr = uc->uc_mcontext.gregs[17];
  void* access_addr = info->si_addr;
  int err_code = info->si_code;

  if(access_addr > ADDR_START && access_addr < ADDR_END) {
    void* page_addr = (void*)((long)access_addr - ((long)access_addr % PAGE_SIZE));

    if(err_code == 1) {
      safe_printf("Fault at rip=%lx accessing %lx! Map missing page at %lx.\n", (long)rip_addr, (long)access_addr, (long)page_addr);
      mmap_page(page_addr, PROT_WRITE);
    } else if(err_code == 2) {
      safe_printf("Fault at rip=%lx accessing %lx! Make page at %lx writable.\n", (long)rip_addr, (long)access_addr, (long)page_addr);
      mprotect_page(page_addr, PROT_WRITE);
    }
  } else {
    safe_printf("Fault at rip=%lx accessing %lx! Address not mapped - terminating!\n", (long)rip_addr, (long)access_addr);
    exit(11);
  }
}
```

![](https://i.imgur.com/Sr0a7Qt.png)
