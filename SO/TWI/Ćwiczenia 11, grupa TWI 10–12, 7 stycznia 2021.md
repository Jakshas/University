# Ćwiczenia 11, grupa TWI 10–12, 17 grudnia 2020

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                | 10-1  | 10-2 | 10-3  | 10-4  | 10-5 | 10-6  | 10-7  | 10-8  |
|:---------------------- |:-----:|:----:|:-----:|:-----:|:----:|:-----:|:-----:|:-----:|
| Kamil Banaś            |       |      |       |       |      |       |       |       |
| Marcin Dąbrowski       |   X   |      |   X   |   X   |  X   |   X   |   X   |   X   |
| Kamil Galik            |   X   |      |   X   |   X   |  X   |   X   |   X   |   X   |
| Bartosz Głowacki       |   X   |      | ==X== |   X   |  X   |   X   |   X   |   X   |
| Jakub Kaczmarek        |   X   |      |   X   |   X   |  X   |   X   |   X   | ==X== |
| Karol Machoś           |   X   |      |   X   |   X   |  X   |   X   |   X   |   X   |
| Małgorzata Maciejewska |   X   |   X  |   X   |   X   |      |   X   |       |   X   |
| Antoni Pokusiński      |   X   |      |  X    |   X   |  X   |   X   |       |   X   |
| Mateusz Reis           |       |      |   X   |   X   |      |   X   |   X   |   X   |
| Adam Turowski          |   X   |      |   X   |   X   |      |   X   |       |   X   |
| Aleksander Uniatowicz  |   X   |  X   |   X   |   X   |  X   | ==X== |   X   |   X   |
| Jan Wańkowicz          |   X   |      |   X   |   X   |  X   |   X   |   X   |   X   |
| Krzysztof Wiśniewski   |   X   |      |   X   | ==X== |  X   |   X   |       |   X   |
| Tomasz Woszczyński     | ==X== |  X   |   X   |   X   |  X   |   X   |       |   X   |
| Jakub Zając            |   X   |      |   X   |   X   |      |   X   |       |   X   |
| Paweł Zmarzły          |   X   |  X   |   X   |   X   |  X   |   X   | ==X== |   X   |
| Adam Zyzik             |   X   |      |       |       |      |   X   |   X   |   X   |
:::

## Zadanie 10-1

:::danger
Autor: Tomasz Woszczyński
:::

:::info
Czym różni się **przetwarzanie równoległe** *(ang. parallel)* od **przetwarzania współbieżnego** *(ang. concurrent)*? Czym charakteryzują się **procedury wielobieżne** *(ang. reentrant)*? Podaj przykład procedury w języku C:

1. wielobieżnej, ale nie **wątkowo-bezpiecznej** *(ang. thread-safe)* 
2. na odwrót (wątkowo-bezpiecznej, ale nie wielobieżnej).

Kiedy w jednowątkowym procesie uniksowym może wystąpić współbieżność?
:::

**Przetwarzanie równoległe** *(ang. parallel)* polega na jednoczesnym przetwarzaniu wielu różnych zadań, czy obliczeń (np. przez 2 lub więcej procesory).

**Przetwarzanie współbieżne** *(ang. concurrent)* polega na współistnieniu wielu wątków lub procesów. Uruchomione wątki na tym samym procesorze są wykonywane naprzemiennie, sprawiając wrażenie, że wykonują się równolegle.

Te dwie formy przetwarzania różni sposób, w jaki wykonują zadania/obliczenia. Przy przetwarzaniu współbieżnym w miejscu linii przerywanych należy pamiętać o tym, że zmieniany jest kontekst (przez co zmiana między zadaniami nie jest natychmiastowa).
![](https://i.imgur.com/ULr5mCW.png)

**Procedura wielobieżna** *(ang. reentrant)* to procedura, której wykonywanie może zostać przerwane np. przerwaniem, bądź wywołaniem innej funkcji wewnątrz ciała funkcji, a następnie może ona zostać ponownie wywołana, zanim poprzednie wywołanie zostanie zakończone. Po zakończeniu drugiego wywołania, można wrócić do przerwanego wywołania, a wykonywanie go można bezpiecznie kontynuować. Taką procedurę cechują:

1. Nie powinna operować na niestałych zmiennych globalnych i zmiennych `static`, jednak może pracować z takimi danymi (nie jest to zalecane!).
2. Nie może modyfikować swojego kodu - techniki takie jak [*blitting*](https://en.wikipedia.org/wiki/Bit_blit) mogłyby sprawić, że kod nie byłby taki sam przy kolejnym wywołaniu.
3. Nie może wywoływać procedur niewielobieżnych.

**Procedura wątkowo-bezpieczna** *(ang. thread-safe)* to procedura, która gwarantuje brak sytuacji wyścigu, gdy jest uruchamiana przez kilka wątków jednocześnie.

Procedura wielobieżna, ale nie wątkowo-bezpieczna:

```c=
int tmp;

void swap(int* x, int* y)
{
    int s = tmp; // save global variable

    tmp = *x;    // perform normal swap
    *x = *y;
    *y = tmp;     

    // hardware interrupt might invoke isr() here,
    // producing incorrect results in swap

    // restore global variable
    tmp = s;
}

void isr()
{
    int x = 1, y = 2;
    swap(&x, &y);
}
```

W powyższym przykładzie może dojść do sytuacji, w której dwa różne wątki wykonują funkcję `swap`. Jeśli jeden z nich zostanie przerwany po `*y = tmp`, ale przed `tmp = s`, a drugi wykonany, potencjalnie może zmienić on wartość zmiennej `tmp`. W takiej sytuacji powrót do pierwszego wątku mógłby zwracać niepoprawne wyniki.

Procedura wątkowo-bezpieczna, ale nie wielobieżna:

```c=
# include <pthread.h>

int increment_counter ()
{
  static int counter = 0;
  static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

  // only allow one thread to increment at a time
  pthread_mutex_lock(&mutex);

  ++counter;

  // store value before any other threads increment it further
  int result = counter;

  pthread_mutex_unlock(&mutex);

  return result;
}
```

Powyższa procedura może zostać wywołana przez różne wątki, gdyż używa muteksów do zsynchronizowania wszystkich dostępów do współdzielonej zmiennej `counter`. Jednak gdy taka funkcja zostanie użyta przez wielobieżną obsługę przerwań i zostanie wysłane drugie przerwanie, w trakcie gdy muteks jest zablokowany, drugie wywołanie zawiesi się na zawsze. 

Innym przykładem procedury wątkowo-bezpiecznej, ale nie współbieżnej jest `printf`, jako że POSIX wymaga, aby procedury *stdio* były wątkowo-bezpieczne. Nie jest ona jednak wielobieżna, gdyż używa synchronizacji za pomocą *lock*ów. Z drugiej strony, procedurami współbieżnymi, ale nie wątkowo-bezpiecznymi są takie, które korzystają z globalnego bufora, a następnie go przywraca przy wychodzeniu.  

Nieporozumienie wynikające z różnic Wikipedii i StackOverflow i CS:APP: powyżej podane przeze mnie przykłady wywodzą się z Wikipedii i StackOverflow, natomiast w CS:APP funkcje wielobieżne są podzbiorem funkcji wątkowo-bezpiecznych, co przeczy zadaniu (mamy podać przykład funkcji wielobieżnej, ale nie wątkowo-bezpiecznej). W przypadku funkcji wątkowo-bezpiecznej, ale nie wielobieżnej, wszystko jest już w porządku.
![](https://i.imgur.com/poiumMV.png)

Jednowątkowy program może działać współbieżnie, jeśli wykorzysta skoki `setjmp(3)` i `longjmp(3)`. Taką "współbieżność" nazywamy wielozadaniowością kooperacyjną, a najlepszym przykładem są prawdopodobnie korutyny, czyli kilka współprogramów działających w obrębie jednego procesu.

>[name=Paweł]
>Tutaj mój przykład z sigsetmask, który pokazałem przy okazji zad7. Oczywiście są specjalne procedury ustawiające blokowanie sygnałów tylko dla konkretnego wątku.
>![](https://i.imgur.com/xUjlrmp.png)

## Zadanie 10-2

:::danger
Autor: Małgorzata Maciejewska
:::
Zakleszczenie - sytuacja, w której proces czekający na dany zasób trzyma inny zasób, który drugi proces potrzebuje, aby zwolnić zasób, na który czeka pierwszy proces 
>Wątki A i B korzystają z zasobów x i y
> A zaczyna używać x
> A i B chcą y, wygrywa B, A czeka na y blokując x
> B chce x
> mamy deadlock



Uwięzienie - sytuacja, w której 2 lub więcej procesów nieskończenie wiele razy powtarzają fragment programu wymieniając się stanami 
np
>Wątki A i B korzystają z zasobu x
> A chce x
>B chce x
> A widzi, że B chce x, więc nie bierze x
> B widzi, że A chce x, więc nie bierze x
>mamy livelock

Głodzenie - sytuacja, w której wątkowi odmawiany jest dostęp do zasobu, trwa zawsze, bo wszystkich "ważniejszych" wątków jest nieskończenie wiele.
>Wątki A i "ważniejsze" od A B1,B2,...,Bn,... korzystają z zasobu x
>B1,B2,...,Bn,... kolejno biorą x
>A chce x, ale musi czekać
> Jendak B1,B2,...,Bn,... blokują x 
> A jest głodzone

![](https://i.imgur.com/ET2rDcC.jpg)

Warunki konieczne do zakleszczenia:
(http://www.mif.pg.gda.pl/homepages/marcin/PWIR2018_2019/pwir-1.pdf)
1. Wzajemne wykluczanie – istnieje co najmniej jeden zasób, który w danym czasie może być wykorzystywany tylko przez jeden proces
2. Brak wywłaszczania – zasoby nie podlegają wywłaszczeniu, tzn. zasób nie może zostać odebrany zajmującemu go procesowi podczas wykorzystania zasobu
3. Przetrzymywanie zasobu i oczekiwanie na inny
4. Cykl w grafie oczekiwania na zasoby – istnieje zamknięty łańcuch procesów (cykl), w którym każdy proces oczekuje na zasoby przetrzymywane przez proces poprzedzający, np. P1 zajmuje Z1, P2 zajmuje Z2, P1 oczekuje na Z2, P2 oczekuje na Z1

Zapobieganie zakleszczeniom -- co najmniej jeden z warunków koniecznych nie będzie spełniony
Wykrywanie zakleszczeń -- graf zależności (krawędzie wychodzące zależność od zasobu, a krawędzie wchodzące zajęcie zasobu), szukamy na tym grafie cyklu
Usuwanie zakleszczeń -- np. zabicie procesu albo wywłaszczenie zasobu


## Zadanie 10-3

:::danger
Autor: Bartosz Głowacki
:::

![](https://i.imgur.com/3pHvhE9.png)
wartość tally zawsze najpierw jest wczytywana z pamięci i trafia do rejestru
następnie do tego rejestru dodawane jest 1
następnie wartość z powrotem jest wysyłana do pamięci

maksymalnie 100.
stanie się tak jeśli przykładowo najpierw wykona się w całości pierwsze wykonanie total, następnie po jego skończeniu dopiero zacznie się drugie. Wtedy kiedy zacznie się drugie wywołanie to zmienna tally będzie miała wartość 50 a po jego końcu 100.

minimalnie 2
tak może się zdarzyć przykładowo jeśli oba wywołania będą wykonywać się równolegle i sekwencja wykonania będzie taka:
```
1 - wywołanie 1 zaczyna pierwsze wywołanie pętli i pobiera 
    wartość zmiennej tally wtedy tally = 0
2 - następnie wywołanie 2 zaczyna działać i robi 49 obrotów pętli wtedy tally = 49
3 - następnie wywołanie 1 wykonuje operacje dodawania 
    (ale on ma pobraną wersję tally kiedy było ono = 0)
    więc  wykonuje 0 + 1 i do tally wpisuje 1 do pamięci
4 - następnie wywołanie 2 zaczyna 50-ty obrót pętli pobiera 
    wartość tally = 1 z pamięci
5 - następnie wywołanie 1 zaczyna działać i wykonuje się w 
    całości po czym tally = 50
6 - następnie wywołanie 2 wykonuje operacje dodawania ale 
    ze swoim już pobranym tally = 1 
    więc robi 1 + 1 czyli 2
```

**Jak zmieni się przedział możliwych wartości zmiennej «tally», gdy wystartujemy k procesów zamiast dwóch?**
maksymalnie wartość tally wyniesie 50k i statnie się to gdy wywołania total będą się wykonywać po kolei.

minimalnie wartość tally wyniesie znowu 2 i stanie się to w sytuacji:
```
1 - wywołanie 1 zaczyna pierwsze wywołanie pętli i pobiera 
    wartość zmiennej tally wtedy tally = 0
2 - następnie wywołanie 2 zaczyna działać i robi 49 
    obrotów pętli wtedy tally = 49
3 - następnie każde wywołanie od 3 do k wykonuje się w 
    całości po kolei po tym tally = 50*(k-2) + 49
4 - następnie wywołanie 1 wykonuje operacje dodawania 
    (ale on ma pobraną wersję tally kiedy było ono = 0)
    więc  wykonuje 0 + 1 i do tally wpisuje 1
5 - następnie wywołanie 2 zaczyna 50-ty obrót pętli 
    pobiera wartość tally = 1
6 - następnie wywołanie 1 wykonuje się w całości po czym tally = 50
7 - następnie wywołanie 2 wykonuje operacje 
    dodawania 1 + 1 czyli wynik to 2
```

## Zadanie 10-4

:::danger
Autor: Krzysztof Wiśniewski
:::
Funkcje
1.**fork** - utworzenie nowego procesu
2.**exit** - wyjście z procesu
3.**waitpid** - czekanie aż, któryś proces zmieni swój stan
4.**atexit** - jaką funkcję specjalną wywołać w wczasie normalnego wyjścia z procesu
5.**abort** - proces jest przerywane w anormalnym trybie

Odpowiedniki dla wątków

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
```
Rozpoczynamy nowy wątek w obecnym procesie, w którym wywołaliści pthread_create()
 Wywołujemy funkcje zdefiniowaną przez start_routine, do której przekażemy argumenty zdefiniowane przez arg. 
 Żeby wywołać pthread_create() potrzebujemy jeszcze buffer-a w, którym będziemy mogli przechowywać ID nowego wątka, 
 później możemy się do tego wątka poprzez ten buffer odwoływać. To jest właśnie thread. 
 Możemy też określić pewne cechy charakterystyczne danego wątka przy pomocy attr(czy jest Detach, rozmiar stosu, adres stosu, politykę zarządania).
 
 ```c
 void pthread_exit(void *retval);
 ```
  Funkcja ta kończy wątek wołający tę funkcję i ewentualnie przekazuje przez retval informacje o
   zakończeniu wątka, w procesie, który wołał pthread_join(). Ewentualnie bo wątek musiał być joinable.
   
```c
int pthread_join(pthread_t thread, void **retval);
```
   Proces, który wywołał pthread_join() czeka na wątek zdefiniowany przez thread, aby się zakończył
   Ten thread musi mieć zdefiniowane w atrybutach, że jest joinable.
   Jeśli retval nie będzie NULL-em to znaczy, że thread został zakończony przy pomocy pthread_exit() i do miejsca w pamięci wskazywanego przez retval zostanie przypisany exit status thread-a 
	
```c    
int pthread_key_create(pthread_key_t *key, void (*destructor)(void*));
```
Tworzymy klucz przez funkcje pthread_key_create(). Ten klucz będzie widoczny dla wszystkich wątków w procesach w naszym programie. Klucz ten służy do lokalizowania dodatkowych danych dla wątków. Aby uzyskać później ten konkretny dla danego wątka klucz używa się funkcji pthread_setspecific().
Możemy przekazać też do pthread_create() dodatkowo funkcje-destruktor wywoływaną przy wyjściu z wątka, którego będzie dotyczył ten konkrety klucz.

```c
int pthread_cancel(pthread_t thread);
```
Funkcja ta wysyła żądanie anulowanie do wątka zdefiniowanego przez thread. Zależy od atrybutów tego wątka czy zareaguje na to żadanie.

	
wątek **joinable**

Powinna zostać wywołana procedura pthread_join(), aby doczepić wątek i poczekać na jego zakończenie się, a następnie zwolnić używane przez niego zasoby (np. pamięć). 
Odpowiedzialność za “posprzątanie” po przyczepionym wątku spoczywa na programiście.
Jeżeli wątek nie zostanie doczepiony, to stanie się wątkiem zombie - jego zasoby nie zostaną poprawnie przywrócone do systemu, aż do zakończenia działania programu.


wątek **detach**
Działa niezależnie od innych wątków.
Po zakończeniu odczepionego wątku kernel zwraca wszystkie zasoby, których ten używał, z powrotem do systemu. 
Nie można wywołać na nim pthread_join() i czekać na zakończenie działania wątku.


   
   https://www.man7.org/linux/man-pages/man3/pthread_create.3.html
   https://www.man7.org/linux/man-pages/man3/pthread_exit.3.html
   https://man7.org/linux/man-pages/man3/pthread_join.3.html
   https://linux.die.net/man/3/pthread_key_create
   https://man7.org/linux/man-pages/man3/pthread_cancel.3.html

## Zadanie 10-5

:::danger
Autor: Kamil Galik
:::

1.) Jeden z wątków zawoła funkcję fork(2) lub execve(2) lub_exit(2)?

fork() -> dziecko kopiuje przestrzeń adresową rodzica razem z mutexami i dzieje się to w obrębie jednego wątku. Gdyby pozostałe wątki były w trakcie jakiś krytycznych operacji, to skopiowane będą niepełne dane.  
execve() -> Wszystkie wątki poza tym, który wywołał execve zostają zniszczone. Mutexy ani żadne obiekty pthread nie zostają  zachowane.
\_exit() -> Wychodzi z jednego wątku zamiast całego procesu.

2.) Proces  zadeklarował  procedurę  obsługi  sygnału  «SIGINT»,  sterownik  terminala  wysyła  do  procesu«SIGINT» – który wątek obsłuży sygnał?

Wątek, który obłsuży ten sygnał zostanie wybrany arbitralnie.

3.) Określono domyślną dyspozycję sygnału «SIGPIPE», a jeden z wątków spróbuje zapisać do rurypipe(2),której drugi koniec został zamknięty?

Przychodzi sygnał SIGPIPE do wątku, który próbuje próbował zapisać, a defaultowym zachowaniem SIGPIPE jest zakończenie się programu.

4.) Czytamy w wielu wątkach ze pliku zwykłego korzystając z tego samego deskryptora pliku?

Jeśli wiele wątków chciałoby czytać z jednego pliku (mając ten sam deskryptor), mogłoby dojść do nieoczekiwanej sytuacji, w której oba wątki czytałyby to samo, mimo że nie powinny.


## Zadanie 10-6

:::danger
Autor: Aleksander Uniatowicz
:::

```c=
    int threads[nthreads];

    for (int i = 0; i < nthreads; i++){
        pthread_create(&threads[i], NULL, thread, NULL);
    }

    for (int i = 0; i < nthreads; i++){
        pthread_join(threads[i], NULL);
    }
```

## Zadanie 10-7

:::danger
Autor: Paweł Zmarzły
:::

```c=
  while (!quit)
  {
    int nready = Poll(fds, nfds, 500);
    if (nready == 0)
      continue;

    /* TODO: If listening descriptor ready, add new client to the pool. */
    if (fds[0].revents & POLLIN)
    {
      struct sockaddr_storage addr;
      socklen_t addrlen = sizeof(struct sockaddr_storage);
      int clientfd = Accept(listenfd, (SA *)&addr, &addrlen);

      static char hostname[MAXLINE], port[MAXLINE];
      Getnameinfo((SA *)&addr, addrlen, hostname, MAXLINE, port, MAXLINE, 0);
      addclient(clientfd, hostname, port);

      nready--;
    }

    /* TODO: Echo a text line from each ready connected descriptor.
     * Delete a client when end-of-file condition was detected on socket. */
    for (int i = 1; nready > 0; i++)
    {
      // Co z POLLHUP Hang up (output only)?
      if (fds[i].revents & POLLIN)
      {
        int bytes_read = clientread(i);
        if (bytes_read == 0)
        {
          delclient(i);
          i--; // Zostajemy w miejscu, bo tablica się zmniejszyła.
        }
        nready--;
      }
    }
  }

  printf("Server received %ld total bytes.\n", nbytes);
  return EXIT_SUCCESS;
```

select, poll - podobny mechanizm
epoll - szybszy od poll (osobne ustawianie fd i sprawdzanie)

## Zadanie 10-8

:::danger
Autor: Jakub Kaczmarek 
:::

### bug-1.c
```!
$ ./bug-1 1
==================
WARNING: ThreadSanitizer: data race (pid=33132)
  Read of size 8 at 0x55f5fa0ca030 by thread T2:
    #0 thread /home/jakub/stu/SO/so20_lista_10/bug-1.c:12 (bug-1+0x137e)
    #1 <null> <null> (libtsan.so.0+0x2d1af)

  Previous write of size 8 at 0x55f5fa0ca030 by thread T1:
    #0 thread /home/jakub/stu/SO/so20_lista_10/bug-1.c:12 (bug-1+0x1395)
    #1 <null> <null> (libtsan.so.0+0x2d1af)

  Location is global 'cnt' of size 8 at 0x55f5fa0ca030 (bug-1+0x000000004030)

  Thread T2 (tid=33135, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x5ea99)
    #1 Pthread_create libcsapp/posix_thread.c:9 (bug-1+0x1587)
    #2 main /home/jakub/stu/SO/so20_lista_10/bug-1.c:27 (bug-1+0x144b)

  Thread T1 (tid=33134, finished) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x5ea99)
    #1 Pthread_create libcsapp/posix_thread.c:9 (bug-1+0x1587)
    #2 main /home/jakub/stu/SO/so20_lista_10/bug-1.c:26 (bug-1+0x142f)

SUMMARY: ThreadSanitizer: data race /home/jakub/stu/SO/so20_lista_10/bug-1.c:12 in thread
==================
OK cnt=2
ThreadSanitizer: reported 1 warnings
```
### Rozwiązanie
**[_Atomic](https://en.cppreference.com/w/c/language/atomic)** - Tworzy nowy typ atomowy odporny na wyścigi

```c=
/* WARNING: This code is buggy! */
#include "csapp.h"

/* Global shared variable */
static volatile _Atomic long cnt = 0; /* Counter */

/* Thread routine */
static void *thread(void *vargp) {
  long i, niters = *((long *)vargp);

  for (i = 0; i < niters; i++)
    cnt++;

  return NULL;
}

int main(int argc, char **argv) {
  /* Check input argument */
  if (argc != 2)
    app_error("usage: %s <niters>\n", argv[0]);

  long niters = atoi(argv[1]);
  pthread_t tid1, tid2;

  /* Create threads and wait for them to finish */
  Pthread_create(&tid1, NULL, thread, &niters);
  Pthread_create(&tid2, NULL, thread, &niters);
  Pthread_join(tid1, NULL);
  Pthread_join(tid2, NULL);

  /* Check result */
  if (cnt != (2 * niters)) {
    printf("BOOM! cnt=%ld\n", cnt);
    return EXIT_FAILURE;
  }

  printf("OK cnt=%ld\n", cnt);
  return EXIT_SUCCESS;
}
```

### bug-2.c
```!
$ ./bug-2
Hello from thread 0
==================
WARNING: ThreadSanitizer: data race (pid=33213)
  Write of size 4 at 0x7ffcce59064c by main thread:
    #0 main /home/jakub/stu/SO/so20_lista_10/bug-2.c:15 (bug-2+0x13e6)

  Previous read of size 4 at 0x7ffcce59064c by thread T1:
    #0 thread /home/jakub/stu/SO/so20_lista_10/bug-2.c:6 (bug-2+0x1342)
    #1 <null> <null> (libtsan.so.0+0x2d1af)

  Location is stack of main thread.

  Location is global '<null>' at 0x000000000000 ([stack]+0x00000001f64c)

  Thread T1 (tid=33215, finished) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x5ea99)
    #1 Pthread_create libcsapp/posix_thread.c:9 (bug-2+0x14bc)
    #2 main /home/jakub/stu/SO/so20_lista_10/bug-2.c:17 (bug-2+0x13cf)

SUMMARY: ThreadSanitizer: data race /home/jakub/stu/SO/so20_lista_10/bug-2.c:15 in main
==================
Hello from thread 1
Hello from thread 2
Hello from thread 3
ThreadSanitizer: reported 1 warnings
```
### Rozwiązanie
```c=
/* WARNING: This code is buggy! */
#include "csapp.h"
#define N 4

static void *thread(void *vargp) {
  int myid = *((int *)vargp);
  printf("Hello from thread %d\n", myid);
  return NULL;
}

int main(void) {
  pthread_t tid[N];
  int i;
  int numbers[N];
  for (i = 0; i < N; i++){
    numbers[i]=i;
    Pthread_create(&tid[i], NULL, thread, numbers+i);
  }
  for (i = 0; i < N; i++)
    Pthread_join(tid[i], NULL);

  return EXIT_SUCCESS;
}

```