# Ćwiczenia 7, grupa TWI 10-12, 19 listopada 2020

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                |  6-1  |  6-2  |  6-3  |  6-4  | 6-5 |  6-6  |  6-7  |
|:---------------------- |:-----:|:-----:|:-----:|:-----:|:---:|:-----:|:-----:|
| Kamil Banaś            |       |       |       |       |     |       |       |
| Marcin Dąbrowski       |   X   |   X   |   X   |   X   |     |   X   |   X   |
| Kamil Galik            |   X   |   X   |   X   |   X   |  X  |   X   | ==X== |
| Bartosz Głowacki       |   X   |       |       | ==X== |  X  |   X   |   X   |
| Jakub Kaczmarek        |   X   |   X   |   X   |   X   |     |   X   |   X   |
| Karol Machoś           |   X   |   X   |   X   |   X   |     |   X   |   X   |
| Małgorzata Maciejewska |   X   |   X   |       |   X   |     |   X   |   X   |
| Antoni Pokusiński      |   X   |   X   |       |   X   |  X  |   X   |   X   |
| Mateusz Reis           |   X   |   X   |       |       |     |   X   |   X   |
| Rafał Spyra            |       |       |       |       |     |       |       |
| Adam Turowski          |   X   |   X   |   X   |   X   |     |   X   |   X   |
| Aleksander Uniatowicz  |   X   | ==X== |   X   |   X   |  X  |   X   |   X   |
| Jan Wańkowicz          |   X   |   X   |       |   X   |  X  | ==X== |   X   |
| Krzysztof Wiśniewski   | ==X== |   X   |       |   X   |     |   X   |   X   |
| Tomasz Woszczyński     |   X   |   X   |       |   X   |     |       |   X   |
| Jakub Zając            |   X   |   X   |       |   X   |     |   X   |   X   |
| Paweł Zmarzły          |   X   |   X   | ==X== |   X   |  X  |   X   |   X   |
| Adam Zyzik             |   X   |   X   |       |       |     |   X   |   X   |
::: 

## Zadanie 6-1

:::danger
Autor: Krzysztof Wiśniewski
:::
tożsamość-specjalny unikatowy identyfikator przypisywany użytkownikom systemowym. Najczęściej pod postacią identyfikatora liczbowego.

real id - właściwa tożsamość właściciela procesu, używana w sprawdzaniu uprawnień do przesyłania sygnałów.
euid id - tożsamość użytkowa, wykorzystywana najczęściej do sprawdzania dostępności i uprawnień.
saved id - gdy uprzywilejowany proces chce stać się na chwilę nieuprzywilejowanym procesem może podmienić swój euid na suid, a potem z powrotem.


ruid = 1000
euid = 0
suid = 0

a)
setuid(uid_t uid) - ustawia wszystkie 3 real, effective i saved na sprecyzowaną wartość. Zadziała, gdy sprecyzowana wartość id będzie równa real id lub effective id lub gdy pierwotna effective ID będzie ustawiona na super użytkownika.

setuid(2000)
Zatem	ruid = 2000, euid = 2000, suid = 2000

b)
setreuid(uid_t ruid, uid_t euid) - ustawia ruid oraz euid, może dodatkowo ustawić też suid. Ale to zależy od początkowych parametrów i danych. -1 na danym argumencie powoduje, że nie zostanie zmienione jego ID. Jeśli zmieniony zostanie ruid albo euid na coś innego niż było wcześniej w ruid-dzie to nowy euid zostanie przypisany do suid.

setreuid(-1, 2000)
Zatem ruid = 1000, euid = 2000, suid = 2000

c)
seteuid(uid_t euid) - ustawia euid. Może zostać tylko zamienione na to co było w ruid lub suid. Nie dotyczy super użytkownika.

seteuid(2000)
	ruid = 1000, euid = 2000, suid = 0
	
d)
setresuid(uid_t ruid, uid_t euid, uid_t suid) - ustawia wartości ruid, euid i suid na podane. -1 nie zmienia wartości danego ID. Superużytkownik może zmieniać jak chce, a nieuprzywilejowany musi ograniczyć nowe wartości do obecnych ruid-ów, euid-ów i suid-ów

setresuid(-1, 2000, 3000)
ruid = 1000, euid = 2000, suid = 3000  

ruid = 0, euid = 1000, ruid = 1000 nie jest uprzywilejowanym procesem. Uprzywilejowany użytkownik to taki z euid = 0.
Ten proces może za to stać się uprzywilejowany jeśli wywołałby np. setuid(0)

	
  


## Zadanie 6-2

:::danger
Autor: Aleksander Uniatowicz
:::

R - można odczytać zawartość katalogu (nazwy plików, nie ich zawartość czy metadane)
W - można modyfikować zawartość katalogu (na przykład rename)
X - można odczytać metadane zawartości (zadziała stat), można przetrawersować się przez katalog jeżeli znamy nazwę pliku z jego zawartości i chcemy do niego dotrzeć

set-gid - wszystkie nowo utworzone pliki będą dziedziczyły guid katalogu, a nie użytkownika tworzącego taki plik
sticky - plik może usunąć lub zmienić mu nazwę tylko właściciel katalogu lub właściciel pliku który jest w tym katalogu

``` c=
bool my_access(struct stat *sb, int mode) {
    uid_t uid = geteuid();
    if(uid == 0)
        if(mode&1)
            return sb->st_mode&1 || sb->st_mode>>3&1 || sb->st_mode>>6 
        return 1;r                                                   
    if(uid == sb->st_uid)
    {
        return sb->st_mode>>6 & mode == mode;
    }
    
    int gNo = getgroups(0, NULL);
    gid_t list[gNo];
    getgroups(gNo, list);
    for(int i = 0; i<gNo; i++){
        if(sb->st_gid == list[i]){
            return sb->st_mode>>3 & mode == mode;
        }
    }
    return sb->st_mode & mode == mode;
}
```


## Zadanie 6-3

:::danger
Autor: Paweł Zmarzły
:::

Tożsamość `ruid=1000 euid=0 resuid=0`.

```c=
/* su.c - switch user
 *
 * Copyright 2013 CE Strake <strake888@gmail.com>
 *
 * See http://refspecs.linuxfoundation.org/LSB_4.1.0/LSB-Core-generic/LSB-Core-generic/su.html
 * TODO: log su attempts
 * TODO: suid support
 * Supports undocumented compatibility options: -m synonym for -p, - for -l

USE_SU(NEWTOY(su, "^lmpu:g:c:s:[!lmp]", TOYFLAG_BIN|TOYFLAG_ROOTONLY))

config SU
  bool "su"
  default y
  depends on TOYBOX_SHADOW
  help
    usage: su [-lp] [-u UID] [-g GID,...] [-s SHELL] [-c CMD] [USER [COMMAND...]]

    Switch user, prompting for password of new user when not run as root.

    With one argument, switch to USER and run user's shell from /etc/passwd.
    With no arguments, USER is root. If COMMAND line provided after USER,
    exec() it as new USER (bypassing shell). If -u or -g specified, first
    argument (if any) isn't USER (it's COMMAND).

    first argument is USER name to switch to (which must exist).
    Non-root users are prompted for new user's password.

    -s	Shell to use (default is user's shell from /etc/passwd)
    -c	Command line to pass to -s shell (ala sh -c "CMD")
    -l	Reset environment as if new login.
    -u	Switch to UID instead of USER
    -g	Switch to GID (only root allowed, can be comma separated list)
    -p	Preserve environment (except for $PATH and $IFS)
*/

#define FOR_su

// #include "toys.h"

// Wstawiam zamienniki:

#define _POSIX_C_SOURCE 199309L
#include <unistd.h>
#include <termios.h>
#include <signal.h>

#define GLOBALS(x) \
    struct         \
    {              \
        x          \
    } TT;
#define LOG_NOTICE 1
#define FLAG(x) 1
#define FLAG_l 1
#define _PATH_DEFPATH "/"
struct
{
    int optc;
    char *optargs;
    int optflags;
    int exitval;
} toys;
char toybuf[1024];
char m, p, l;

struct passwd
{
    char *pw_name;
    int pw_uid;
    int pw_gid;
    // powłoka użytkownika
    char *pw_shell;
};

struct spwd
{
    // skrót kryptograficzny hasła
    char *sp_pwdp;
};

void generic_signal(int signo)
{
    (void)signo;
}

// Koniec

// Kopia z innych plików

void xsetuser(struct passwd *pwd)
{
    if (initgroups(pwd->pw_name, pwd->pw_gid) || setgid(pwd->pw_uid) || setuid(pwd->pw_uid))
        perror_exit("xsetuser '%s'", pwd->pw_name);
}

struct passwd *xgetpwnam(char *name)
{
    struct passwd *up = getpwnam(name);

    if (!up)
        perror_exit("user '%s'", name);
    return up;
}

int read_password(char *buf, int buflen, char *mesg)
{
    struct termios oldtermio;
    struct sigaction sa, oldsa;
    // tty_fd sprawdza fd0, fd1, fd2, /dev/tty
    int i, tty = tty_fd(), ret = 1;

    // NOP signal handler to return from the read. Use sigaction() instead
    // of xsignal() because we want to restore the old handler afterwards.
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = generic_signal;
    sigaction(SIGINT, &sa, &oldsa);

    // Usuwamy niewczytane jeszcze bajty.
    tcflush(tty, TCIFLUSH);
    // Ustawiamy raw mode przez cfmakeraw(3). https://linux.die.net/man/3/cfmakeraw
    xset_terminal(tty, 1, 0, &oldtermio);
    dprintf(tty, "%s", mesg);

    for (i = 0; i < buflen - 1; i++)
    {
        // 4 - EOT End Of Transmission (Ctrl+D)
        // 3 - ETX End Of Text
        // Ctrl+D przerywa tylko, gdy jest w pustej linii (ale czemu w przeciwnym
        // wypadku bierzemy go jako fragment hasła?).
        if ((ret = read(tty, buf + i, 1)) < 0 || (!ret && !i) || *buf == 4 || buf[i] == 3)
        {
            i = 0;
            ret = 1;

            break;
        }
        else if (!ret || buf[i] == '\n' || buf[i] == '\r')
        {
            ret = 0;

            break;
        }
        // 8 - Backspace
        // 127 - Delete
        else if (buf[i] == 8 || buf[i] == 127)
            // Usuwamy 1 (samo Backspace/Delete), lub 2 znaki.
            i -= 2 - !i;
    }

    // Restore terminal/signal state, terminate string
    sigaction(SIGINT, &oldsa, 0);
    tcsetattr(0, TCSANOW, &oldtermio);
    buf[i] = 0;
    xputc('\n');

    return ret;
}

// Koniec

GLOBALS(
    char *s;
    char *c;)

void su_main()
{
    char *name, *passhash = 0, **argu, **argv;
    struct passwd *up;
    struct spwd *shp;

    // Użytkownik może poprosić o login shell przez -.
    // Np. `su - pzmarzly` wykona (`sh -l` jako pzmarzly).
    if (*toys.optargs && !strcmp("-", *toys.optargs))
    {
        toys.optflags |= FLAG_l;
        toys.optargs++;
    }

    // Pobieranie nazwy użytkownika.
    if (*toys.optargs)
        name = *(toys.optargs++);
    else
        name = "root";

    loggit(LOG_NOTICE, "%s->%s", getusername(getuid()), name);

    // Szukamy wpisu w /etc/shadow.
    if (!(shp = getspnam(name)))
        // Nie ma wpisu.
        perror_exit("no '%s'", name);
    if (getuid())
    {
        if (*shp->sp_pwdp != '$')
            // Hash hasła zwracanego przez crypt zaczyna się na $.
            // Puste sp_pwdp - login bez hasła (nieobsługiwane przez tę wersję)
            // !, !!, * - niedozwolony login. https://unix.stackexchange.com/questions/252016
            goto deny;
        if (read_password(toybuf, sizeof(toybuf), "Password: "))
            // Użytkownik anulował akcję, lub nie da się pobrać wejścia.
            goto deny;
        // Obliczamy skrót (zmodyfikowany DES).
        passhash = crypt(toybuf, shp->sp_pwdp);
        // Czyścimy bufor z czystym tekstem. Niekoniecznie dobrze.
        // Użyj memset_s. https://en.cppreference.com/w/c/string/byte/memset
        memset(toybuf, 0, sizeof(toybuf));
        if (!passhash || strcmp(passhash, shp->sp_pwdp))
            // Błędne hasło.
            goto deny;
    }
    // Zamykamy deskryptory plików.
    closelog();

    // Szukamy wpisu w /etc/passwd.
    xsetuser(up = xgetpwnam(name));

    if (FLAG(m) || FLAG(p))
    {
        // Pozostaw środowisko, poza nieintuicyjnym IFS i groźnym PATH.
        // Choć równie groźne jest np. PYTHONSTARTUP.
        unsetenv("IFS");
        setenv("PATH", _PATH_DEFPATH, 1);
    }
    else
        // Domyślne środowisko.
        reset_env(up, FLAG(l));

    argv = argu = xmalloc(sizeof(char *) * (toys.optc + 4));
    *(argv++) = TT.s ? TT.s : up->pw_shell;
    loggit(LOG_NOTICE, "run %s", *argu);

    // Przygotowujemy flagi dla sh.
    if (FLAG(l))
        *(argv++) = "-l";
    if (FLAG(c))
    {
        *(argv++) = "-c";
        *(argv++) = TT.c;
    }
    while ((*(argv++) = *(toys.optargs++)))
        ;
    xexec(argu);

deny:
    syslog(LOG_NOTICE, "No.");
    puts("No.");
    toys.exitval = 1;
}
```

Ciekawostka: [`-bash`](https://askubuntu.com/q/702647).

## Zadanie 6-4

:::danger
Autor: Bartosz Głowacki
:::

**Na podstawie §38.2 i §38.3 wyjaśnij czemu programy uprzywilejowane należy projektować w taki sposób, by operowały z najmniejszym możliwym zestawem upoważnień (ang.the least privilege).**
 - Wiele programów jest podatnych na ataki (między innymi przez nadpisanie stosu), więc posiadanie przez program niepotrzebnych uprawnień może zwiększać ryzyko szkodliwego ataku.
 - Trudno jest przewidzieć wszystko łatwiej popełnić niebezpieczny błąd kiedy ma się dużo uprawnień
 - Przy wywołaniu execve lub przy wykonywaniu powłoki lub interpretera należy upewnić się że proces ma dokładnie takie uprawnienia jak trzeba ponieważ nie chcemy dać programowi użytkownika uprawnień jakich nie powinien on mieć. Szczególnie w powłokach i interpreterach niemożliwe jest wyeliminowanie wszystkich luk cytując **38.3** "nawet jeśli wykonywana powłoka nie pozwala na dostęp interaktywny. W konsekwencji istnieje ryzyko, że użytkownik może być w stanie wykonywać dowolne polecenia powłoki pod efektywnym identyfikatorem użytkownika procesu".
 - Trzeba też pamiętać o usuwaniu uprawnień przez zamykanie deskryptorów plików przy uruchamianiu innych procesów, cytując **38.3** "Uprzywilejowany program może otworzyć plik, do którego normalne procesy nie mają dostępu. Wynikowy deskryptor otwartego pliku reprezentuje uprzywilejowany zasób"

**Zreferuj wytyczne dotyczące projektowania takich programów**

 - należy mieć uprawnienia tylko jeśli jest to na prawdę wymagane. (Najbezpieczniejszą praktyką jest natychmiastowe pozbycie się uprawnień podczas uruchamiania programu, a następnie tymczasowe odzyskanie ich w razie potrzeby w późniejszych punktach programu) Przykład z książki:
![](https://i.imgur.com/FKGCvck.png)

 - po skończeniu wszstkich operacji które wymagają większych uprawnień należy usunąć procesowi nieodwracalnie uprawnienia. (Trwałe usuwanie uprawnień odbywa się poprzez zresetowanie wszystkich identyfikatorów użytkowników (grup) procesów do tej samej wartości, co rzeczywisty identyfikator (grupy).)
 
 - przed wywołaniem execv należy ustawić odpowiednie uprawnienia, upewnić się, że wszystkie identyfikatory użytkowników (grup) procesów są resetowane do tej samej wartości, co rzeczywisty identyfikator użytkownika (grupy), tak aby nowy program nie startował z uprawnieniami jakich mieć nie powinien, a także żeby nie mógł ich odzyskać

 - zamykać wszystkie deskryptory plików przed funckją execv

**Zapoznaj się z §39.1 i wytłumacz czemu standardowy zestaw funkcji systemu uniksowego do implementacji programów uprzywilejowanych jest niewystarczający.**

Każdy proces może wykonywać te operacje do jakich ma uprawnienia jego effective user ID. Super user (root) ma uprawnienia do wszystkich operacji. Jeśli chcemy by jakiś proces wykonał operacje do której ma uprawnienia tylko root to dając mu uprawnienia roota dajemy mu od razu wszystkie uprawnienia i jest to niezgodne z zasadą aby każdy proces miał najmniejsze możliwe wymagania.

**Jak starają się to naprawić zdolności (ang.capabilities)?**

Uprawnienia super usera są dzielone na pojedyńcze zdolności i danemu procesowi można przyznać tylko potrzebne zdolności zamiast dawać mu od razu uprawnienia do wszystkiego.

**Dla nieuprzywilejowanego procesu posiadającegozdolności «CAP_DAC_READ_SEARCH» i «CAP_KILL» jądro pomija sprawdzanie upoważnień do wykonywaniapewnych akcji – wymień je.**

CAP_DAC_READ_SEARCH - Pomijanie sprawdzania uprawnień do odczytu plików oraz odczytu katalogu i uruchamiania programów.

CAP_KILL - Pomijanie sprawdzania uprawnień do wysyłania sygnałów.


**Kiedy proces użytkownika może wysłać sygnał do innego procesu?**
Aby proces miał uprawnienia do wysyłania sygnału, musi być albo uprzywilejowany (CAP_KILL) lub rzeczywisty lub efektywny identyfikator użytkownika procesu wysyłającego musi być równy rzeczywistemu lub zapisanemu (saved set-user-ID) użytkownika docelowego procesu. W przypadku SIGCONT wystarczy gdy oba procesy są w tej samej sesji.

## Zadanie 6-5

:::danger
Autor: Antoni Pokusiński
:::
Gdy wywołujemy ```fork()```, nowo utworzony proces jest dokładną kopią rodzica, tak więc w szczególności współdzieli z nim ten sam bufor I/O. Jeśli w momencie wywołania ```fork()``` bufor jest niepusty, to zostanie on wykorzystany dwukrotnie, przykładowo:
```
printf("hello world");
fork();
```
wypisze *hello worldhello world*.

Jeśli więc istnieje możliwość takiego konfliktu, należy włączyć brak buforowania np. za pomocą ```setbuf()```, albo korzystać z ```write()```(co jednak będzie nieefektywne), albo pamiętać o opróżnianu bufora poprzez ```flush```  oraz dodawania znaku końca linii w przypadku buforowania liniami.

**Strategie buforowania:**
* pliki terminala - buforowanie liniami (dopóki nie napotkamy '\n', albo końca bufora)
* pliki dyskowe - buforowanie pełne (dopóki bufor nie jest zapełniony)
* *stderr* - niebuforowane; w przypadku obsługi błędów, chcemy je widzieć od razu

----------------------
Dla przypomnienia, funkcje w procedurach obsługi sygnału:
* **niedozwolone**: printf, sprintf, malloc, exit, funkcje z stdio...
* **bezpieczne** : write, , sleep, wait, waitpid,  kill, _exit, **tcflush**

Aby poprawnie opróżnić wszystkie bufory przed zamknięciem programu, powinniśmy w procedurze obsługi sygnały *SIGINT* użyć ```tcflush()```, dzięki czemu nie utracimy danych z buforów.
## Zadanie 6-6

:::danger
Autor: Jan Wańkowicz
:::

```c=
#include "csapp.h"

static noreturn void usage(int argc, char *argv[]) {
  fprintf(stderr, "Usage: %s [-t times] [-l length] -s "
          "[write|fwrite|fwrite-line|fwrite-full|writev]\n", argv[0]);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  int length = -1, times = -1;
  bool dosync = false;
  int opt;

  while ((opt = getopt(argc, argv, "l:t:s")) != -1) {
    if (opt == 'l')
      length = atoi(optarg);
    else if (opt == 't')
      times = atoi(optarg);
    else if (opt == 's')
      dosync = true;
    else 
      usage(argc, argv);
  }

  if (optind >= argc || length <= 0 || times <= 0)
    usage(argc, argv);

  char *choice = argv[optind];

  char *line = malloc(length + 1);
  memset(line, '*', length);
  line[length] = '\n';

  if (strcmp(choice, "write") == 0) {
    for (int j = 0; j < times; j++)
      for (int k = 0; k < length; k++)
        write(STDOUT_FILENO, line + k, length + 1 - k); 
  }

  if (strncmp(choice, "fwrite", 6) == 0) {
    size_t size;
    int mode;
    void *buf = NULL; 

    if (strcmp(choice, "fwrite-line") == 0) {
      mode = _IOLBF;
      size = length + 1;
    } else if (strcmp(choice, "fwrite-full") == 0) {
      mode = _IOFBF;
      size = getpagesize();
    } else {
      mode = _IONBF;
      size = 0;
    }

    /* TODO: Attach new buffer to stdout stream. */
    
    setvbuf(stdout,buf,mode,size);

    for (int j = 0; j < times; j++)
      for (int k = 0; k < length; k++)
        fwrite(line + k, 1, length+1-k, stdout); 
    fflush(stdout);

    free(buf);
  }

  if (strcmp(choice, "writev") == 0) {
    int n = sysconf(_SC_IOV_MAX);
    struct iovec iov[n];
    
    /* TODO: Write file by filling in iov array and issuing writev. */
    
    for (int j = 0; j < times; j++)
      for (int k = 0; k < length; k++)
		{
        	    iov[ (j*length + k) % n ].iov_base = line + k;
		    iov[ (j*length + k) % n ].iov_len = length + 1 - k;
		    if((j*length + k) % n == n - 1)
				writev(STDOUT_FILENO, iov, n);
		}
		
		if((length * times) % n)
			writev(STDOUT_FILENO, iov, (length * times) % n);
  }

  free(line);

  if (dosync && !isatty(STDOUT_FILENO))
    fsync(STDOUT_FILENO);

  return 0;
}
```

## Zadanie 6-7

:::danger
Autor: Kamil Galik
:::

```c=
static const char *uidname(uid_t uid) {
  struct passwd * pwuid = getpwuid(uid); //Odczytanie struktury passwd, która zawiera m.in. nazwę uzytkownika o danym uid
  return pwuid->pw_name;
}

static const char *gidname(gid_t gid) {
  struct group * grgid = getgrgid(gid); //Odczytanie struktury group, która zawiera m.in. nazwę grupy o danym gid
  return grgid->gr_name;
}

static int getid(uid_t *uid_p, gid_t *gid_p, gid_t **gids_p) {
  gid_t *gids = NULL;
  int ngid = 2;
  int groups;

  *uid_p = getuid();
  *gid_p = getgid();

  groups = getgroups(0,gids); //Odczytujemy ilość grup dodatkowych
  ngid = groups;
  gids = Realloc(gids,sizeof(gid_t) *ngid); //reallokujemy rozmiar gids, tak aby pokrywał potrzebną ilośc grup
  groups = getgroups(ngid,gids); //zapisujemy grupy do tablicy gids
  
  *gids_p = gids; //przestawiamy wskaźkin na gids i zwracamy ilość grup
  return groups;
}

int main(void) {
  uid_t uid;
  gid_t *gids, gid;
  int groups = getid(&uid, &gid, &gids);

  printf("uid=%d(%s) gid=%d(%s) ", uid, uidname(uid), gid, gidname(gid));
  printf("groups=%d(%s)", gids[0], gidname(gids[0]));
  for (int i = 1; i < groups; i++)
    printf(",%d(%s)", gids[i], gidname(gids[i]));
  putchar('\n');

  free(gids);

  return 0;
}

```