# Ćwiczenia 2, grupa TWi 10-12, 15 października 2020

###### tags: `so20` `ćwiczenia` `twi` 

## Zadanie 2-1

:::danger
Autor: Karol Machoś
:::

Przykładowy output komendy ```ps -eo user,pid,ppid,pgid,tid,pri,stat,wchan,cmd```
```
USER         PID    PPID    PGID     TID PRI STAT WCHAN  CMD
root           1       0       1       1  19 Ss   -      /sbin/init
root           2       0       0       2  19 S    -      [kthreadd]
root           3       2       0       3  39 I<   -      [rcu_gp]
root           4       2       0       4  39 I<   -      [rcu_par_gp]
root           6       2       0       6  39 I<   -      [kworker/0:0H-kblockd]
root           8       2       0       8  39 I<   -      [mm_percpu_wq]
root           9       2       0       9  19 S    -      [ksoftirqd/0]
root          10       2       0      10  19 I    -      [rcu_sched]
root          11       2       0      11 139 S    -      [migration/0]
```
Identyfikator procesu(PID)-unikatowy identyfikator procesu w wielozadaniowym systemie operacyjnym.
Jest to liczba całkowita z określonego w systemie przedziału. Jest on wykorzystywany np. przez powłokę systemu operacyjnego, w momencie wywoływania funkcji operujących na procesach, takich jak np. kill

Identyfikator rodzica(PPID)-PID procesu który jest rodzicem danego procesu. Rodzic to proces który wywołał dany proces.

Identyfikator grupy procesów(PGID)-ID grupy procesów do której należy dany proces

Identyfikator właśćiciela procesu(UID)-nazwa lub ID w postaci liczby całkowitej, wyrażająca właściciela procesu

== Kto jest rodzicem procesu init? ==

W zależności od konwencji, albo przyjmuje się, że init nie ma rodzica (stąd PPID=0), lub, że rodzicem procesu init jest sam kernel o PID'dzie 0

== Które z wyświetlonych zadań są wątkami jądra? ==

Komenda ps -eo user,pid,ppid,pgid,tid,pri,stat,wchan,cmd oznacza wątki jądra za pomocą [<nazwa wątku>]

== Jakie jest znaczenie poszczególnych znaków z kolumny STAT? ==

Zgodnie z podręcznikiem systemowym dla ps:
```
PROCESS STATE CODES
       Here are the different values that the s, stat and state output specifiers (header "STAT" or
       "S") will display to describe the state of a process:

               D    uninterruptible sleep (usually IO)
               I    Idle kernel thread
               R    running or runnable (on run queue)
               S    interruptible sleep (waiting for an event to complete)
               T    stopped by job control signal
               t    stopped by debugger during the tracing
               W    paging (not valid since the 2.6.xx kernel)
               X    dead (should never be seen)
               Z    defunct ("zombie") process, terminated but not reaped by its parent

	For BSD formats and when the stat keyword is used, additional characters may be displayed:

               <    high-priority (not nice to other users)
               N    low-priority (nice to other users)
               L    has pages locked into memory (for real-time and custom IO)
               s    is a session leader
               l    is multi-threaded (using CLONE_THREAD, like NPTL pthreads do)
               +    is in the foreground process group
```

Przykładowy output komendy ```pstree```

```
systemd-+-NetworkManager---2*[{NetworkManager}]
        |-accounts-daemon---2*[{accounts-daemon}]
        |-bluetoothd
        |-colord---2*[{colord}]
        |-dbus-daemon
        |-gdm-+-gdm-session-wor-+-gdm-x-session-+-Xorg---8*[{Xorg}]
        |     |                 |               |-gnome-session-b---3*[{gnome-session-b}]
        |     |                 |               `-2*[{gdm-x-session}]
        |     |                 `-2*[{gdm-session-wor}]
        |     `-2*[{gdm}]
        |-gnome-keyring-d---3*[{gnome-keyring-d}]
        |-lvmetad
        |-polkitd---7*[{polkitd}]
        |-rtkit-daemon---2*[{rtkit-daemon}]
        |-systemd-+-(sd-pam)
        |         |-at-spi-bus-laun-+-dbus-daemon
        |         |                 `-3*[{at-spi-bus-laun}]
        |         |-at-spi2-registr---2*[{at-spi2-registr}]
        |         |-dbus-daemon
        |         |-dconf-service---2*[{dconf-service}]
        |         |-konsole-+-bash---zadanie1.sh-+-pstree
        |         |         |                    `-tail
        |         |         `-8*[{konsole}]
        |         |-pulseaudio-+-gsettings-helpe---3*[{gsettings-helpe}]
        |         |            `-2*[{pulseaudio}]
        |         |-teams-+-teams-+-teams---12*[{teams}]
        |         |       |       |-teams---17*[{teams}]
        |         |       |       |-teams---10*[{teams}]
        |         |       |       `-teams---39*[{teams}]
        |         |       |-teams---9*[{teams}]
        |         |       `-33*[{teams}]
        |         `-xdg-permission----2*[{xdg-permission-}]
        |-systemd-journal
        |-systemd-logind
        |-systemd-timesyn---{systemd-timesyn}
        |-systemd-udevd
        |-udisksd---4*[{udisksd}]
        |-upowerd---2*[{upowerd}]
        |-vcsFPService---6*[{vcsFPService}]
        `-wpa_supplicant
```
== Które z wypisanych procesów w hierarchii są wątkami?==
Tutaj podobnie jak w przypadku ps, wątki są oznaczone za pomocą [{<nazwa wątku>}]

## Zadanie 2-2

:::danger
Autor: Aleksander Uniatowicz
:::

proc zawiera "pliki" symulowane przez kernel, z informacjami o procesie 


### argument programu i zmienne środowiskowe

są to zmienne przekazywane do programu, różnią się sposobem przekazywania, argumenty podajemy jawnie, a argumenty niejawnie

są one w plikach 
/proc/*\*pid\**/cmdline
/proc/*\*pid\**/environ

Uid -- user id,
Gid -- group id,
Groups -- lista grup rodziców,
VmPeak -- najwyższe użycie pamięci wirtualnej
VmSize -- aktualne użycie pamięci wirtualnej,
VmRSS -- pamięc w ramie wykorzystywana przez proces ,
Threads -- liczba wątków
voluntary_ctxt_switches -- liczba context switchy zarządanych przez program (np. syscall) 
nonvoluntary_ctxt_switches -- liczba context switchy spowodowanych końcem czasu przeznaczonego dla procesu

## Zadanie 2-3

:::danger
Autor: Tomasz Woszczyński
:::

Aby znaleźć pid, używamy `ps ax | grep X` - flagi `ax` odpowiadają kolejno za szukanie w procesach innych użytkowników oraz pośród procesów działających poza terminalem. Następnie potokiem przekazujemy `stdout` do `grep`, w którym szukamy X-serwer. Na wyjściu uzyskałem:
```
1158 tty1     Sl+    0:00 /usr/lib/xorg/Xorg vt1 -displayfd 3 -auth /run/user/118/gdm/Xauthority -background none -noreset -keeptty -verbose 3
1957 tty2     Rl+   20:02 /usr/lib/xorg/Xorg vt2 -displayfd 3 -auth /run/user/1000/gdm/Xauthority -background none -noreset -keeptty -verbose 3
```

Za pomocą `sudo pmap 1158` lub `sudo pmap 1957` uzyskujemy zawartość przestrzeni adresowej procesu o danym pid. [Tutaj jest przykładowy wydruk tego polecenia](https://pastebin.com/raw/n9gq8jfq). 

Stos (stack) jest na samym dole, możemy jednak wywołać `sudo less /proc/1957/maps`, aby uzyskać dokładny przedział adresów przeznaczony na stos (podobnie działa flaga `-X`, jednak dostajemy tylko początek stosu): 
```
7ffd05252000-7ffd05273000 rw-p 00000000 00:00 0                          [stack]
```

Sterta (heap) podobnie nie jest pokazywana w `pmap`, lecz można ją znaleźć w `/proc/[pid]/maps` (najlepiej w `less` wyszukać pattern `?heap`):
```
55e2b66fd000-55e2b8a1a000 rw-p 00000000 00:00 0                          [heap]
```

**Segmenty programu** to spójne bloki pamięci o jednolitym przeznaczeniu i atrybutach z punktu widzenia procesu ładowania i uruchamiania programu. Jeden segment może zawierać wiele sekcji (linker odpowiada za sekcje, loader za segmenty). **Segment kodu** to obszar pamięci zawierający kod maszynowy programu. Segmenty programu są zmapowane do `Xorg`:
```
Address           Kbytes     RSS   Dirty Mode  Mapping
000055e2b56a4000     244     168       0 r---- Xorg
000055e2b56e1000    1588    1576       0 r-x-- Xorg
000055e2b586e000     484     192       0 r---- Xorg
000055e2b58e7000      12      12      12 r---- Xorg
000055e2b58ea000      48      48      48 rw--- Xorg
```
Na podstawie `Mode` możemy wyznaczyć segment text (`r-x--` czyli readable and executable). Pola oznaczone  `r----` to prawdopodobnie sekcje `.rodata`, a `rw---` to sterta.

**Pamięć anonimowa** to pamięć niebędąca powiązana z żadnym plikiem ani obiektem. Powszechnym anonimowym mapowaniem jest stos i sterta wspomniane powyżej. Jest ona oznaczona jako `[anon]`.

**Pliki odwzorowane w pamięć** *(ang. memory-mapped file)* to segment pamięci wirtualnej mający bezpośrednie mapowanie co do bajta z jakimś plikiem lub zasobem. Dzięki temu unika się stosowania funkcji systemowych na plikach takich jak `read()` lub `write()`, gdyż proces adresuje plik bezpośrednio. Plik może być traktowany jak ciągły obszar w pamięci procesu, dostępny poprzez bezpośrednie operacje pobrania i podstawienia wartości. Wszystkie modyfikacje dokonane w pamięci są później zapisywane na dysku. Znaleźć je można w `Mapping` jako pliki `*.so`.

Poza tymi sekcjami znajdują się również te:
```
7ffd053ae000-7ffd053b1000 r--p 00000000 00:00 0                          [vvar]
7ffd053b1000-7ffd053b3000 r-xp 00000000 00:00 0                          [vdso]
```
`vvar` zawiera zmienne systemowe takie jak `gettimeofday`, dzięki czemu `syscall` działa znacznie szybciej. `vdso` to biblioteka współdzielona   udostępniana przez jądro żeby przyspieszyć wykonywanie pewnym syscalli, które niekoniecznie muszą działać w przestrzeni jądra.

Poszczególne kolumny wydruku `pmap [pid] -x` oznaczają:
* Address - adres początku
* Kbytes - rozmiar
* RSS - fizyczny rozmiar używanej pamięci
* Dirty - dirty strony w KB
* Mode - uprawnienia rwx (czytanie, pisanie, wykonywanie)
* Mapping - plik na jaki zmapowana jest pamięć lub `[anon]/[stack]`

## Zadanie 2-4

:::danger
Autor: Aleksander Uniatowicz
:::

![](https://i.imgur.com/VxHcn8A.png)

- zasoby plikopodobne
-- pliki zarządzanie przez kernel, służące do obsługi np. urządzeń 
- plik zwykły
-- plik na dysku 

- katalog
-- katalog

- urządzenie
-- "plik" będący punktem komunikacji między userem, a urządzeniem

- gniazda
--  "plik" służący do komunikacji między procesami 

- potok ak'a fifo
-- pozwala połączyć wyjście jednego procesu, z wejściem drugiego

## Zadanie 2-5

:::danger
Autor: Paweł Zmarzły
:::

Na moim systemie mam wiele poleceń `time`, o różnych formatach wyjścia i funkcjonalnościach:

- polecenie wbudowane w `zsh` `time`,
- polecenie wbudowane w `bash` `time`,
- program `/bin/time` (najwięcej funkcjonalności, ma też flagę `-v`).

Będę używał tego z `bash`.

user + sys < real, gdy w tle inne procesy pracowały, lub proces czekał - np. na gotowość terminala na dalszy odbiór danych (bufory).

user + sys > real, gdy proces działa wielowątkowo (np. `ffmpeg -i test.mp4 test.avi`). Wtedy `top` i `htop` pokazują kilkaset procent użycia czasu CPU.

Nałóżmy `ulimit` na potomków obecnego procesu: `ulimit -t 1`.

Uruchamiając `time find /usr`, `find` zostaje zabity, gdy `user` + `sys` = 1s.

Uruchamiając `/bin/time find /usr`, widzimy, że `find` zostaje zabity sygnałem 9 (SIGKILL), a `time` przeżywa.

## Zadanie 2-6

:::danger
Autor: Marcin Dąbrowski
:::

```cpp=
static void do_read(int fd) {
  pid_t pid;
  pid = Fork();
  if(pid == 0){
    Read(fd,buf,16);
    printf("%d: %ld\n",pid, Lseek(fd,0,SEEK_CUR));
  }
  else{
  	Read(fd,buf,16);
  	printf("%d: %ld\n",pid,Lseek(fd,0,SEEK_CUR));
  }
  exit(0);
}

static void do_close(int fd) {
  int child_status;
  pid_t pid;
  pid = Fork();
  if(pid == 0){
	printf("%d: Closing file %d\n",pid,fd);
	Close(fd);
	exit(0);
  }
  else {
  	Waitpid(pid,&child_status,0);
  	printf("%d: Child status: %d\n",pid,child_status);
  	printf("%d: Cursor position: %ld\n",pid, Lseek(fd,0,SEEK_CUR));
  	Read(fd,buf,16);
  	printf("%d: Reading from file %d: %s\n",pid,fd,buf);  
	exit(0);
  }
}
```

```bash=
./fileref read
```
#### Wynik:
```
4606: 16
0: 32
```

Dochodzi do kopiowania przez referencję, ponieważ dziecko ma dostęp do tego samego pliku co rodzic.

Możemy zauważyć, że oba procesy korzystają z tego samego kursora, ponieważ końcowa pozycja kursora wynosi $32$, a w obu procesach odczytujemy $16$ znaków. Gdyby procesy nie korzystały ze wspólnego kursora, i nie byłoby żadnej innej synchronizacji wyjścia, to dochodziłoby do nadpisywania wyjścia jednego procesu przez wyjście innego. Aktualna pozycja kursora znajduje się w strukturze *file description*, która znajduje się w jądrze.

```bash=
./fileref close
```
#### Wynik:
```
0: Closing file 3
5029: Child status: 0
5029: Cursor position: 0
5029: Reading from file 3: Write programs t
```

Mimo tego, że dziecko zamknęło plik, zanim rodzic zaczął z niego czytać, to nie wystąpił żaden błąd. Oznacza to, że plik rodzica nie został zamknięty. Wynika to z faktu, że każdy proces posiada swój własny *file descriptor*. Jest to liczba całkowita, która pozwala na komunikację z plikiem. Właśnie dlatego zamknięcie pliku w procesie-dziecku nie powoduje zamknięcia go w rodzicu. 







## Zadanie 2-7

:::danger
Autor: Aleksander Uniatowicz
:::

```c=
#include "csapp.h"

#include <pthread.h>
pthread_mutex_t lock;

static int ndselect(int n)
{
   /* TODO: A loop is missing here that spawns processes and waits for them! */
   pid_t pids[8];
   for (int i = 0; i < n; i++)
   {
      pids[i] = Fork();
      if (pids[i] == 0)
      {
         return i;
      }
   }
   for (int i = 0; i < 8; i++)
   {
      waitpid(pids[i], NULL, 0);

   }
   exit(0);
}

static int conflict(int x1, int y1, int x2, int y2)
{
   return x1 == x2 || y1 == y2 || x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2;
}

static void print_line_sep(int size)
{
   for (int i = 0; i < size; ++i)
      printf("+---");
   printf("+\n");
}

static void print_board(int size, int board[size])
{
   pthread_mutex_lock(&lock);

   for (int i = 0; i < size; ++i)
   {
      print_line_sep(size);
      for (int j = 0; j < size; ++j)
         printf("|%s", board[i] == j ? " Q " : "   ");
      printf("|\n");
   }
   print_line_sep(size);
   printf("\n");

   pthread_mutex_unlock(&lock);
}

int main(int argc, char **argv)
{
   if (argc != 2)
      app_error("Usage: %s [SIZE]", argv[0]);

   int size = atoi(argv[1]);

   if (size < 2 || size > 9)
      app_error("Give board size in range from 4 to 9!");

   if (pthread_mutex_init(&lock, NULL) != 0)
   {
      app_error("mutex error");
   }
   int board[size];

   /* TODO: A loop is missing here that initializes recursive algorithm. */
   for (int i = 0; i < size; i++)
   {
      int pos = ndselect(size);
      if (pos == -1)
         exit(0);
      board[i] = pos;
      for (int j = 0; j < i; j++)
      {
         if (conflict(j, board[j], i, board[i]))
            exit(0);
      }
   }

   print_board(size, board);

   return 0;
}
```
