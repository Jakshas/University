# Ćwiczenia 10, grupa TWi 10-12, 10 grudnia 2020

###### tags: `so20` `ćwiczenia` `twi`


## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                | 9-1 | 9-2 | 9-3 |  9-4  |  9-5  |  9-6  |  9-7  |
|:---------------------- |:---:|:---:|:---:|:-----:|:-----:|:-----:|:-----:|
| Kamil Banaś            |     |     |     |       |       |       |       |
| Marcin Dąbrowski       |  X  |  X  |  X  |   X   | ==X== |   X   |       |
| Kamil Galik            |  X  |  X  |==X==|   X   |   X   |   X   |   X   |
| Bartosz Głowacki       |     |     |     |       |       |   X   |   X   |
| Jakub Kaczmarek        |  X  |     |  X  |   X   |   X   |   X   |       |
| Karol Machoś           |  X  |  X  |  X  |   X   |   X   |   X   |       |
| Małgorzata Maciejewska |  X  | X   |     |       |   X   |   X   |   X   |
| Antoni Pokusiński      |  X  |  X  |  X  |       |   X   |   X   |   X   |
| Mateusz Reis           |     |  X  |     |       |   X   |   X   |   X   |
| Adam Turowski          |  X  |  X  |  X  |       |   X   |   X   |       |
| Aleksander Uniatowicz  |  X  |  X  |  X  | ==X== |   X   |   X   |   X   |
| Jan Wańkowicz          |  X  |  X  |     |       |   X   |   X   |   X   |
| Krzysztof Wiśniewski   |==X==|  X  | X   |       |  X    |  X    |       |
| Tomasz Woszczyński     |  X  |  X  |  X  |   X   |   X   |   X   |   X   |
| Jakub Zając            |     |     |     |       |   X   | ==X== |   X   |
| Paweł Zmarzły          |  X  |  X  |  X  |   X   |   X   |   X   | ==X== |
| Adam Zyzik             |     |     |     |       |       |       |       |
:::

## Zadanie 9-1

:::danger
Autor: Krzysztof Wiśniewski
:::
**Datagram** – podstawowa jednostka przekazu powiązana z siecią komutacyjną pakietów. Zwykle są zbudowane z sekcji nagłówka i ładunku. Umożliwia bezpołączeniową komunikację sieciową.

**Połączeniowe** - W celu korzystania z komunikacji połączeniowej programy muszą nawiązać połączenie, zanim za jego pośrednictwem będą mogły przesyłać dane. Służy do tego tzw. three way handshake.
![](https://i.imgur.com/H162ntg.png)

**Segment TCP**
![](https://i.imgur.com/ghiqlBt.png)

- IP("Infrastruktura- Poczta, Kable, Drogi, Maszty itp.")- Podstawowy protokół sieciowy. Określa sposób adresowania i pozwala na zawodne dostarczanie pakietów między hostami.

- TCP("Dzwonienie przez telefon")-Protokół do komunikacji między procesami. Wymaga nawiązania połączenia z konkretnym serwerem, jednakże zapewnia on dostarczenie pakietu, lub informacje o braku dostarczenia, dzięki oczekiwaniu na potwierdzenie odebrania pakietu. Ponadto dzięki numerowaniu pakietów z sekwencji, możliwe jest zachowanie ich kolejności oraz usuwanie duplikatów po stronie odbiorcy. TCP u swoich podstaw, do samego przesylu danych, rowniez wykorzystuje IP.
- UDP("Wysyłanie listu")-Prosty protokół transportowy do komunikacji między procesami. Aplikacja wysyła wiadomość do gniazda UDP, które pozniej zostaje zawarte w datagramie UDP, który pozniej staje się częścią datagramu IP. Protokół UDP nie daje żadnej gwarancji, że wiadomość zostanie dostarczona, kolejność pakietów zostanie zachowana, albo wszystkie pakiety dojdą w tym samym czasie. Jednakże w przeciwieństwie do TCP nie wymaga dłuższego połączenia z danym serwerem. Dane mogą być wysyłane lub odbierane na tym samym gniezdzie, do wielu clientow lub od wielu clientow na raz.

### Half duplex vs full duplex
- **Half duplex** - Komunikacja w obie strony, ale tylko w jedną strone na raz (Pozwala na zaoszczędzenie bandwithu)(UDP=może działać w obu trybach). **WALKIE-TALKIE**
- **Full duplex** - Komunikacja w dwie strony w tym samym czasie.  (Oszczędność czasu)(TCP=full-duplex). **TELEFON**

### Jak TCP radzi sobie z zagubieniem segmentu lub zamianą kolejności wysłanych segmentów po stronie odbierającego?
Każdy z segmentów ma przydzielony swoj numer. W razie zamiany kolejności segmentów w trakcie przesyłania, protokół umożliwia po stronie odbierającego, właśnie wykorzystując przydzielone segmentom numery, przywrócić ich oryginalną kolejność. W razie zagubienia segmentu, gdy nadawca nie dostanie potwierdzenia odbioru w określonym czasie, segment zostaje nadany ponownie. W razie gdy jednak zagubiony segment jednak dotrze do odbiorcy, razem z jego powtórzeniem, dzięki numerowi segmentu, odbiorca jest w stanie zidentyfikować duplikaty i pozbyć się ich.
### Skąd TCP wie kiedy połączenie zostało zerwane?
Protokół TCP w momencie nie otrzymania w pewnym czasie od odbiorcy potwierdzenia odebrania nadanych danych, ponownie je nadaje i oczekuje dłuższy czas. W momencie gdy całkowity czas nadawania danych przekroczy pewną wartość (typowo 4-10 minut) protokół się poddaje i uznaje, że doszło do zerwania połączenia.
### Jaki problem rozwiązuje flow-control w TCP?
Flow-control służy określeniu przez odbiorcę, ile dokładnie bajtów danych jest w stanie odebrać jeszcze aktualnie od nadawcy. Pozwala to uniknąć sytuacji w której odbiorca dostaje za dużo danych na raz i nie jest w stanie ich wszystkich obsłużyć, przez co dochodzi do nieodebrania nadprogramowych danych.
## Zadanie 9-2

:::danger
Autor: Karol Machoś
:::

![](https://i.imgur.com/rHRiyrm.png)
![](https://i.imgur.com/NPdGncJ.png)

**klient-serwer** - podstawowy model komunikacji sieciowej, zakładający instnienie jednostki odpowiedzialnej za otrzymywanie i przetwarzanie żądań, oraz jednostki wysyłającej te żądania.

**gniazdo strumieniowe** - umożliwia niezawodny przesył uporządkowanych  danych. Posiada dobrze zdefiniowane mechanizmy nawiązywania i kończenia połączenia oraz zgłaszania błędów. Najczęściej implementowane przez TCP.

- **socket** - utworzenie gniazda
- **bind** - <u>związanie gniazda z parą numeru IP i portu</u>
- **listen** - informuje kernel, że powinien on akceptować na danym gnieździe nadchodzące prośby o połączenie.
- **accept** - w tym wypadku, z racji na pustą kolejkę połączeń, oczekiwanie na nawiązanie połączenia przez klienta z serwerem. Gdyby kolejka nie była pusta to zostałoby zaakceptowane pierwsze połączenie oczekujące w niej.
- **connect** - klient nawiązuje połączenie z serwerem. Jeżeli wcześniej nie został utworzony port, który następnie został związany z IP i portem serwera, to jądro tworzy **port efemeryczny** Nie wymagane jest użycie bind ponieważ kernel sam dobierze port ephemeralny oraz odpowiedni adres IP.
- **read**, **write** - przesyłanie danych i odbieranie
- **close** - zamknięcie gniazda i rozpoczęcie procedury zakończenia połączenia TCP. Wywołane najpierw po stronie klienta, informuje serwer, że wszystkie dane zostały już wysłane i odebrane, i serwer również może zamknąć swoje gniazdo.

### Port efemeryczny
Tymczasowy port IP wykorzystywany przez klienta TCP w trakcie wysyłania i odbierania danych, między nim a serwerem.

### Drugi argument listen():
```int listen(int sockfd, int backlog);```

Określa on ile maksymalnie połączeń kernel po stronie serwera powinien zakolejkować na tym gnieździe (ile klientów będzie mogło połaczyć sie z danym gniazdem na raz).

### Z jakim numerem portu jest związane gniazdo przekazywane do i zwracane z **accept()**?
Z numerem portu połączenia, które jest pierwsze w kolejce aktualnie oczekujących połączeń.

### Zamykanie połaczenia
![](https://i.imgur.com/4L8puwH.png)
Klient używając **close()** zamyka swoje gniazdo i przesyła do serwera segment **FIN** (znak EOF). Serwer otrzymuje **FIN** co interpetuje jako sygnał do zakończenia polecenia. Serwer również wywołuje po swojej stronie **close()** zamykając swoje gniazdo i przesyła do klienta **FIN**. Po tym gdy klient i serwer prześlą sobie potwierdzenia (**ACK**) otrzymania od siebie **FIN**, połączenie zostaje uznane za zamknięte.

## Zadanie 9-3

:::danger
Autor: Kamil Galik
:::

![](https://i.imgur.com/8wJcFmf.png)

Gniazdo datagramowe - gniazdo bezpołączeniowe. Każdy pakiet jest indywidualnie kierowany do danego adresu. Nie ma gwarancji przesłania, ani zachowania kolejności.

Nie ustalamy żadnego  połączenia klienta z serwerem, więc możemy od razu po bind() rozpocząć pracę. 

Po stronie  serwera read/write jest niewystarczające, bo  nie pozwala ustalić adresu docelowego socketa z którego otrzymujemy dany/do którego wysyłamy dane.

```c=
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                 struct sockaddr *src_addr, socklen_t *addrlen);
				 
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen);
```
Użycie connect:
- Kernel sprawdza aynchroniczne blędy (unreachable destination)
- Zapisuje IP i port procesu przekazanego do connect()
- Mamy powiązanie z konkretnym socketem clienta, przez co możemy używać read/write bezpośrednio 

## Zadanie 9-4

:::danger
Autor: Aleksander Uniatowicz
:::



**Kiedy read(2) i write(2) na gniazdach strumieniowych zwracają short counts?**
+ write
  ![](https://i.imgur.com/cacFqdH.png)
+ write i read: SO_RCVTIMEO, SO_SNDTIMEO - opcje pozwalające ustawić timeout dla funkcji I/O socketa. Jeśli zostanie on przekroczony to zostanie zwrócony shorcount lub errno.
+ ![](https://i.imgur.com/xhsd4Rw.png)

Jeżeli spróbujemy zapisać do bufora więcej niż jest dostępne wolnego miejsca lub zostanie przekroczony czas ustawiony w SO-RCVTIMEO i SO_SNDTIMEO. *socket(7)*

 

**Skąd wiemy, że odebrany datagram nie został obcięty?**

Datagramy IP, TCP i UDP mają długość podaną w nagłówku. Możemy też sprawdzać sumę kontrolną.

**Z jakich przyczyn należy być przygotowanym na to, że operacje na gniazdach
zwrócą «EINTR»?**

Sygnał może zostać dostarczony w trakcie wykonywania wywołania systemowego. W szczególności wywołanie systemowe może być wykonywane tak długo, jak oczekujemy na działanie klienta, potencjalnie nieskończenie długo przy accept. Jeżeli takie wywołanie zostanie przerwane, to zależnie od systemu operacyjnego i ustawionych przez nas opcji, wywołanie może zostać niezwłocznie wywołane ponownie, a wtedy nie wróci z błędem lub zwróci -1, a errno zostanie ustawione na EINTR.

**Dlaczego w kodzie funkcji «open_listenfd» użyto wywołania setsockopt(2)
z opcją «SO_REUSEADDR»? Co by się stało gdyby programista o tym zapomniał?**

Ta opcja pozwala na ponowne użycie adresu przez inny proces bez oczekiwania na jego zwolnienie, zależnie od implementacji, nawet kilkudziesięciu sekund. Dzięki temu możemy po zakończeniu porcesu na przykład w celu zmiany jego ustawień natychmiast powiązać gniazdo sieciowe z wcześniej użytym adresem.

**Co się stanie, jeśli klient spróbuje zapisać do gniazda powiązanego z połączeniem, które serwer zdążył już zamknąć?**
https://stackoverflow.com/questions/15406097/writing-on-a-tcp-socket-closed-by-the-peer
https://www.softlab.ntua.gr/facilities/documentation/unix/unix-socket-faq/unix-socket-faq-2.html

## Zadanie 9-5

:::danger
Autor: Marcin Dąbrowski
:::

```
struct addrinfo {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    socklen_t ai_addrlen;
    struct sockaddr *ai_addr;
    char *ai_canonname;
    struct addrinfo *ai_next;
};
```

```c=
#include "csapp.h"

int main(int argc, char **argv) {
  struct addrinfo *p, *listp, hints;
  char buf[MAXLINE];
  char buf2[MAXLINE]; // bufor dla dodatkowego argumentu
  int rc, flags;

  if (argc != 2 && argc != 3)
    app_error("usage: %s <domain name>\n", argv[0]);
  
  /* Get a list of addrinfo records */
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC; // przyjmuje zarówno IPv4, jak i IPv6
  hints.ai_socktype = SOCK_STREAM; // SOCK_DGRAM aby obsługiwać tftp
  /* Connections only */
  char* service = NULL;
  if(argc == 3) service = argv[2];

  if ((rc = getaddrinfo(argv[1], service, &hints, &listp)) != 0)
    gai_error(rc, "getaddrinfo");

  /* Walk the list and display each IP address */
  flags = NI_NUMERICHOST | NI_NUMERICSERV; /* Display address string instead of domain name */
  for (p = listp; p; p = p->ai_next) {
    Getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, buf2, MAXLINE, flags);
    if(p->ai_family == AF_INET) 
      printf("%s", buf); //IPv4 
    else 
      printf("[%s]", buf); //IPv6
    if(service != NULL)
      printf(":%s", buf2);        
    printf("\n");
  }

  /* Clean up */
  freeaddrinfo(listp);

  return EXIT_SUCCESS;
}
```


## Zadanie 9-6

:::danger
Autor: Jakub Zając 
:::

```c=
#include "csapp.h"
#include "rio.h"

#define LISTENQ 1

static size_t nread = 0;

static sigjmp_buf env;

static void sigint_handler(int sig)
{
    siglongjmp(env, sig);
}

static void echo(int connfd)
{
    size_t n;
    char buf[MAXLINE];
    rio_t rio;
    
    rio_readinitb(&rio, connfd);
    
    while ((n = Rio_readlineb(&rio, buf, MAXLINE)))
    {
         Rio_writen(connfd, buf, n);
         nread += n;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        app_error("usage: %s <port>\n", argv[0]);
        
    Signal(SIGINT, sigint_handler);
    
    int listenfd = Open_listenfd(argv[1], LISTENQ);
    /* TODO: Print bytes received after SIGINT has been received. */
    int n = sigsetjmp(env, 1);
    if (n)
    {
        safe_printf("Bytes read: %ld\n", nread);
        
        Close(listenfd);
        return 0;
    }
    while (1)
    {
        socklen_t clientlen = sizeof(struct sockaddr_storage);
        struct sockaddr_storage clientaddr;   /* Enough space for any address */
        char client_hostname[MAXLINE], client_port[MAXLINE];
       
       int connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
       
        Getnameinfo((SA *)&clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
        
        printf("Connected to %s:%s\\n", client_hostname, client_port);
        
        echo(connfd);
        Close(connfd);
    }
}

```

## Zadanie 9-7

:::danger
Autor: Paweł Zmarzły
:::

```c=
/* TODO: Need to define context to be used with sigsetjmp & siglongjmp. */
static sigjmp_buf context;

static client_t *client = NULL;
static sig_atomic_t nclients = 0;
static size_t nread = 0; /* number of bytest received on all connections */

// ...

static void sigchld_handler(int sig)
{
  pid_t pid;
  /* TODO: Delete clients as they die. */
  while (1)
  {
    pid = waitpid(-1, NULL, WNOHANG);
    if (pid <= 0)
      break;
    safe_printf("[%d] Disconnected!\n", pid);
    delclient(pid);
  }
}

static void sigint_handler(int sig)
{
  safe_printf("Server received quit request!\n");
  /* TODO: Change control flow so that it does not return to main loop. */
  siglongjmp(context, 1);
}

// ...

int main(int argc, char **argv)
{
  if (argc != 2)
    app_error("usage: %s <port>\n", argv[0]);

  sigset_t sig_mask;
  sigemptyset(&sig_mask);
  sigaddset(&sig_mask, SIGCHLD);

  Signal(SIGCHLD, sigchld_handler);
  Signal(SIGINT, sigint_handler);

  client =
      Mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);

  int listenfd = Open_listenfd(argv[1], LISTENQ);

  /* TODO: Wait for all clients to quit and print a message with nread. */
  int n = sigsetjmp(context, 1);
  if (n)
  {
    while (nclients > 0)
      pause();
    printf("Server received %lu bytes\n", nread);
    exit(0);
  }

  while (1)
  {
    socklen_t clientlen = sizeof(struct sockaddr_storage);
    struct sockaddr_storage clientaddr; /* Enough space for any address */
    int connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);

    static char client_hostname[MAXLINE], client_port[MAXLINE];
    Getnameinfo((SA *)&clientaddr, clientlen, client_hostname, MAXLINE,
                client_port, MAXLINE, 0);

    sigset_t mask;
    Sigprocmask(SIG_BLOCK, &sig_mask, &mask);

    /* TODO: Start client in subprocess, close unused file descriptors. */
    client_t *c = addclient();
    pid_t pid = Fork();
    if (pid == 0)
    {
      printf("[%d] Connected to %s:%s\n", getpid(), client_hostname, client_port);
      Signal(SIGINT, SIG_IGN);
      echo(c, connfd);
      exit(0);
    }

    c->pid = pid;
    Close(connfd);
    Sigprocmask(SIG_SETMASK, &mask, NULL);
  }
}
```