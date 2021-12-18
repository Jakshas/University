# Ćwiczenia 6, grupa TWI 10-12, 12 listopada 2020

###### tags: `so20` `ćwiczenia`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**
![](https://i.imgur.com/8ThkWho.png)

:::danger
|          Lista-zadanie |  5-1  | 5-2 |  5-3  |  5-4  |  5-5  |  5-6  |  5-7  | 5-8 |  5-9  |
| ----------------------:|:-----:|:---:|:-----:|:-----:|:-----:|:-----:|:-----:|:---:|:-----:|
|            Kamil Banaś |       |     |       |       |       |       |       |     |       |
|       Marcin Dąbrowski |   X   |     |       |   X   |   X   |   X   |   X   |  X  |   X   |
|            Kamil Galik | ==X== |     |   X   |       |   X   |       |   X   |  X  |   X   |
|       Bartosz Głowacki |   X   |     |   X   |       |   X   |       |   X   |  X  | ==X== |
|        Jakub Kaczmarek |   X   |     |       |   X   |   X   |   X   |   X   |  X  |   X   |
|           Karol Machoś |   X   |     |       |   X   |   X   |   X   |   X   |  X  |   X   |
| Małgorzata Maciejewska |   X   |  X  |   X   |   X   |   X   | ==X== |       |     |   X   |
|      Antoni Pokusiński |   X   |     |   X   |   X   | ==X== |   X   |   X   |  X  |   X   |
|           Mateusz Reis |       |     |       |       |   X   |   X   |   X   |     |       |
|            Rafał Spyra |   X   |     |   X   |       |       |       |       |     |       |
|          Adam Turowski |   X   |     |       |       |       |   X   |   X   |  X  |   X   |
|  Aleksander Uniatowicz |   X   |     | ==X== |   X   |   X   |   X   |   X   |  X  |   X   |
|          Jan Wańkowicz |   X   |     |   X   |       |   X   |   X   | ==X== |  X  |   X   |
|   Krzysztof Wiśniewski |   X   |     |       |       |       |   X   |   X   |  X  |   X   |
|     Tomasz Woszczyński |   X   |     |       |       |   X   |   X   |   X   |  X  |   X   |
|            Jakub Zając |   X   |     |       |   X   |   X   |   X   |   X   |     |       |
|          Paweł Zmarzły |   X   |     |   X   | ==X== |   X   |   X   |   X   |  X  |   X   |
|             Adam Zyzik |       |     |       |   X   |   X   |   X   |   X   |     |       |
:::

## Zadanie 5-1

:::danger
Autor: Kamil Galik
:::

**Punkt montowania** - Folder w obecnie używanym systemie plików, do którego przyczepiony jest inny system plików.

Wyświetlić listę zamontowanych plików można za pomocą komenty **mount**.

Atrybuty montażowe:
noatime - zaprzestanie aktualizacji informacji czasowych dla plików zamontowanych 
Przydatne w momencie gdy chcemy zoptymalizować odczyty i zapisy, a nie potrzebujemy danych o czasie dostępu.

noexec - zablokowanie bezpośredniego uruchamiania plików/programów z zamontowanego systemu plików
Podłączenie pendrive z nieznanego źródła. Kwestia bezpieczeństwa.

sync - Wszystkie operacje wejścia / wyjścia do systemu plików powinny być wykonywane synchronicznie.
W przypadku podłączenia nośnika USB często wykonujemy wiele małych zapisów lub odczytów, do czego lepiej nadaje się wejście/wyjście synchroniczne. System nie zużywa czasu na obśługiwanie inengo procesu w miedzyczasie.


## Zadanie 5-2

:::danger
Autor: Małgorzata Maciejewska
:::
![](https://i.imgur.com/3ChJzgU.jpg)
**Dodawanie pliku:** Trzeba przejrzeć cały katalog, żeby sprawdzić, czy jest dany plik w tym katalogu. Jeśli nie ma miejsca, wykonywane jest kompaktowanie.
**Usuwanie pliku:** Przegląda się cały katolog, żeby wiedzieć, czy jest plik. Po usunięciu pliku miejsce, gdzie był ten plik staje się nieużytkiem, pliki nie od razu są przesuwane, przestawiany jest wskaźnik przy poprzednim pliku (entry size).
**Nieużytek** to nieużywany fragment reprezentacji katalogu - rozmiar wpisu, po którym występuje nieużytek jest większy niż nazwa pliku. 
**Kompaktowanie** to operacaja, która zmniejsza rozmiar katalogu - usuwane są nieużytki, "uklepujemy" katalog. Opłąca się ją robić, gdy wiadomo, że w danym katalogu jest dużo nieużytków, czyli zystamy na tej operacji dużo miejsca.


## Zadanie 5-3

:::danger
Autor: Aleksander Uniatowicz
:::


*ścieżka bezwzględna* - zaczynająca się od /
*i-node* - struktura przechowująca metadane pliku

plik nie istnieje, ale jest skompresowany odpowiednik `/usr/share/man/man1/ls.1.gz`

```linux
  File: /usr/share/man/man1/ls.1.gz
  Size: 3190            Blocks: 8          IO Block: 4096   regular file
Device: fd01h/64769d    Inode: 7080697     Links: 1
Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 2020-11-11 22:18:55.713054734 +0100
Modify: 2019-09-05 12:38:40.000000000 +0200
Change: 2020-04-25 15:21:00.018038662 +0200
 Birth: -

```

```linux
7080697 -rw-r--r-- 1 root root 3190 wrz  5  2019 /usr/share/man/man1/ls.1.gz
```


Algorytm trawersuje od i-node'a 2, bo to numer /

i-node zawiera wskaźniki na bloki danych (i bloki pośrednie zależnie od wielkości pliku)



Dowiązania są częścią systemu plików, a system zamontowany, może mieć inny sposób trzymania ich, dowiązanie jest do i-node, który nie jest dzielony między systemami plików

W dwóch systemach plików możemy mieć dwa pliki o tym samym i-node.

Przykład:
> Nie możemy tworzyć dowiązań do innych zamomtowanych systemów plików aby licznik zawierał informacje   o dowiązaniach w obrębie systemu plików i nie doszło do sytuacji gdy po utworzeniu dowiązania i       odłączeniu systemu plików   dane z niego nie zostaną nigdy usunięte nawet po zniszczeniu wszystkich   lokalnych dowiązań (licznik nadal byłby większy od 1).



## Zadanie 5-4

:::danger
Autor: Paweł Zmarzły 
:::

```c=
void tty_curpos(int fd, int *x, int *y)
{
  // termios, old termios
  struct termios ts, ots;

  // ts = tcgetattr()
  tcgetattr(fd, &ts);
  // ots = ts
  memcpy(&ots, &ts, sizeof(struct termios));
  // Wyłączamy ECHO, ICANON i CREAD.
  // ECHO - pokazuj użytkownikowi wprowadzane znaki.
  // ICANON - obsługa znaków specjalnych.
  // CREAD - odbieraj nowe dane (zdaniem dokumentacji FreeBSD bezużyteczne).
  ts.c_lflag &= ~(ECHO | ICANON | CREAD);
  // TCSADRAIN - zmiany nie dotyczą danych w buforze.
  // TCSAFLUSH - zmiany nie dotyczą bufora, niezatwierdzone wejście
  //             jest usuwane.
  tcsetattr(fd, TCSADRAIN, &ts);

  /* How many characters in the input queue. */
  int m = 0;
  // FIONREAD == TIOCINQ - Get the number of bytes in the input buffer.
  ioctl(fd, TIOCINQ, &m);

  /* Read them all. */
  // Wczytujemy zawartość bufora wejścia w jądrze (czyszcząc go).
  char discarded[m];
  m = Read(fd, discarded, m);

  // CPR Cursor Position Report (również Device Status Report).
  // Sterownik terminala wypisze aplikacji `ESC[n;mR`, gdzie
  // n - rząd, m - kolumna. Zapisujemy to w buf.
  Write(fd, CPR(), sizeof(CPR()));
  char buf[20];
  int n = Read(fd, buf, 19);
  buf[n] = '\0';

  // Włączamy ICANON i wypełniamy z powrotem bufor wejścia.
  ts.c_lflag |= ICANON;
  tcsetattr(fd, TCSADRAIN, &ts);
  for (int i = 0; i < m; i++)
    // TIOCSTI - Insert the given byte in the input queue. (Faking input)
    ioctl(fd, TIOCSTI, discarded + i);

  // Przywracamy stary stan termios (ECHO, CREAD).
  tcsetattr(fd, TCSADRAIN, &ots);
  // Czytamy CPR.
  sscanf(buf, "\033[%d;%dR", x, y);
}
```

## Zadanie 5-5

:::danger
Autor: Antoni Pokusiński
:::


```
File: holes.bin
  Size: 33550336        Blocks: 1112       IO Block: 4096   regular file
Device: 10306h/66310d   Inode: 4994782     Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/  antoni)   Gid: ( 1000/  antoni)
Access: 2020-11-12 00:51:48.182841662 +0100
Modify: 2020-11-12 00:51:48.210841541 +0100
Change: 2020-11-12 00:51:48.210841541 +0100
 Birth: -
 ```
 
 Okazuje się, że faktyczna objętość pliku - 1112*512 = 569 344 - jest znacznie mniejsza od tej zawartej w strukturze ```stat``` ( > 33 mln). Dzieje się tak, ponieważ dziury (bloki z samymi '\0') nie wymagają alokacji na dysku.
 
 **Czemu liczba używanych bloków (1112) jest większa od liczby faktycznie używanych bloków zgłaszanych przez «mkholes» (138) ?**
 Rzeczywisty romiar bloku to 512 B (```stat --format=%B holes.bin```), podczas gdy w programie założyliśmy, że rozmiar bloku to 4096 B (```#define BLKSZ 4096 ```)
 

## Zadanie 5-6

:::danger
Autor: Tomasz Woszczyński
:::

**Numer urządzenia** to para liczb `major:minor`. `major` identyfikuje sterownik powiązany z urządzeniem, a `minor` to numer używany przez sterownik (sterownik może kontrolować wiele urządzeń, dzięki czemu `minor` pozwala je rozróżnić). Aby wypisać wszystkie urządzenia blokowe, można użyć polecenia `lsblk`, który wyświetli coś takiego:
```
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
loop0    7:0    0 355.4M  1 loop /snap/pycharm-community/214
loop1    7:1    0  97.7M  1 loop /snap/core/10126
loop2    7:2    0  97.8M  1 loop /snap/core/10185
loop3    7:3    0 354.6M  1 loop /snap/pycharm-community/211
loop4    7:4    0  52.7M  1 loop /snap/john-the-ripper/297
sda      8:0    0 111.8G  0 disk 
├─sda1   8:1    0   450M  0 part 
├─sda2   8:2    0    99M  0 part 
├─sda3   8:3    0    16M  0 part 
├─sda4   8:4    0 110.5G  0 part 
└─sda5   8:5    0   802M  0 part 
sdb      8:16   0 238.5G  0 disk 
├─sdb1   8:17   0    16M  0 part 
├─sdb2   8:18   0 101.8G  0 part 
├─sdb3   8:19   0   513M  0 part /boot/efi
├─sdb4   8:20   0 120.3G  0 part /
└─sdb5   8:21   0  15.9G  0 part [SWAP]
```

Aby sprawdzić, czy zadanie jest dobrze rozwiązane, przygotowałem katalog `permission_bits` zawierający pliki podobne do tych z zadania, są to kolejno `executable.py`, `file1.txt`, `link`, `local` oraz `tmp` z ustawionymi odpowiednimi bitami. `local` oraz `tmp` to katalogi. Bity zostały ustawione następującymi poleceniami:
```
$ chmod o+t tmp
$ chmod g+s local
$ chmod u+s executable.py
$ link -s file1.txt link
```
Wydruk polecenia `ls -al` jest następujący:
```
drwxr-xr-x 4 two two 4096 Nov 12 00:58 .
drwxr-xr-x 5 two two 4096 Nov 12 00:50 ..
-rwsr-xr-x 1 two two    0 Nov 12 00:42 executable.py
-rw-r--r-- 1 two two    0 Nov 12 00:36 file1.txt
lrwxrwxrwx 1 two two    9 Nov 12 00:36 link -> file1.txt
drwxr-sr-x 2 two two 4096 Nov 12 00:37 local
drwxr-xr-t 2 two two 4096 Nov 12 00:37 tmp
```

Wydruk programu `listdir` jest następujący:
```
-rwsr-xr-x   1        two        two     0  Thu Nov 12 00:42:00 2020    executable.py
drwxr-sr-x   2        two        two  4096  Thu Nov 12 00:37:48 2020    local
drwxr-xr-t   2        two        two  4096  Thu Nov 12 00:37:48 2020    tmp
drwxr-xr-x   5        two        two  4096  Thu Nov 12 00:50:59 2020    ..
lrwxrwxrwx   1        two        two     9  Thu Nov 12 00:36:51 2020    link -> file1.txt
-rw-r--r--   1        two        two     0  Thu Nov 12 00:36:18 2020    file1.txt
drwxr-xr-x   4        two        two  4096  Thu Nov 12 00:58:04 2020    .
```

Uzupełniony kod:
```c=
#include "csapp.h"

#define DIRBUFSZ 256

static void print_mode(mode_t m) {
    char t;

    if (S_ISDIR(m))
        t = 'd';
    else if (S_ISCHR(m))
        t = 'c';
    else if (S_ISBLK(m))
        t = 'b';
    else if (S_ISREG(m))
        t = '-';
    else if (S_ISFIFO(m))
        t = 'f';
    else if (S_ISLNK(m))
        t = 'l';
    else if (S_ISSOCK(m))
        t = 's';
    else
        t = '?';

    char ur = (m & S_IRUSR) ? 'r' : '-';
    char uw = (m & S_IWUSR) ? 'w' : '-';
    char ux = (m & S_IXUSR) ? 'x' : '-';
    char gr = (m & S_IRGRP) ? 'r' : '-';
    char gw = (m & S_IWGRP) ? 'w' : '-';
    char gx = (m & S_IXGRP) ? 'x' : '-';
    char or = (m & S_IROTH) ? 'r' : '-';
    char ow = (m & S_IWOTH) ? 'w' : '-';
    char ox = (m & S_IXOTH) ? 'x' : '-';

    /* TODO: Fix code to report set-uid/set-gid/sticky bit as 'ls' does. */
    // 'setuid' bit can be identified easily when there is 's' in place of
    // 'x' of the executable bit. The 's' implies that te executable bit is
    // set, otherwise it would be set to 'S'. 'setgid' bit is similar to 
    // 'setuid' bit, but in this case 's' is present in group sector (there
    // are three sectors: owner, group, other, before them there is one bit
    // saying if it is regular file). The 'sticky' bit is meant to forbid
    // modifying files in that directory by users who are not owners. It is
    // identifiable by a 't' in the place of 'x', also 'T' applies that the
    // executable bit is not present.

    // If m has set 'setuid'/'setgid'/'sticky', check if m is executable,
    // then set the bit accordingly, otherwise permissions are not changed.
    ux = (m & S_ISUID) ? ((m & S_IXUSR) ? 's' : 'S') : ux;
    gx = (m & S_ISGID) ? ((m & S_IXGRP) ? 's' : 'S') : gx;
    ox = (m & S_ISVTX) ? ((m & S_IXOTH) ? 't' : 'T') : ox;

    printf("%c%c%c%c%c%c%c%c%c%c", t, ur, uw, ux, gr, gw, gx, or, ow, ox);
}

static void print_uid(uid_t uid) {
    struct passwd *pw = getpwuid(uid);
    if (pw)
        printf(" %10s", pw->pw_name);
    else
        printf(" %10d", uid);
}

static void print_gid(gid_t gid) {
    struct group *gr = getgrgid(gid);
    if (gr)
        printf(" %10s", gr->gr_name);
    else
        printf(" %10d", gid);
}

static void file_info(int dirfd, const char *name) {
    struct stat sb[1];

    /* TODO: Read file metadata. */
    // int fstatat(int dirfd, const char *pathname, 
    //             struct stat *statbuf, int flags);
    // AT_SYMLINK_NOFOLLOW flag means that if pathname (name) is a symbolic
    // link, it should not be dereferenced.
    fstatat(dirfd, name, sb, AT_SYMLINK_NOFOLLOW);

    print_mode(sb->st_mode);
    printf("%4ld", sb->st_nlink);
    print_uid(sb->st_uid);
    print_gid(sb->st_gid);
    
    /* TODO: For devices: print major/minor pair; for other files: size. */
    // Device ID consists of two parts: major ID (class of the device) and
    // minor ID (specific instance of a device in that class).
    // unsigned int major(dev_t dev);
    // unsigned int minor(dev_t dev);
    // S_ISCHR returns non-zero if the file is a character special file
    // (a device like a terminal) and S_ISBLK returns non-zero if the file
    // is a block special file (a device like a disk).
    if (S_ISCHR(sb->st_mode) || S_ISBLK(sb->st_mode))
        printf("%2u, %2u", major(sb->st_rdev), minor(sb->st_rdev));
    else
        printf("%6lu", (size_t)sb->st_size);

    char *now = ctime(&sb->st_mtime);
    now[strlen(now) - 1] = '\0';
    printf("%26s", now);

    printf("    %s", name);

    if (S_ISLNK(sb->st_mode)) {
    /* TODO: Read where symlink points to and print '-> destination' string. */
        const size_t bufsize = 255;
        char path[bufsize + 1];

        // readlinkat(2) places the contents of the symbolic link name in the
        // buffer buf, which has size bufsize, but it does not append null byte
        // to buf, thus we have to do it.
        const ssize_t len = readlinkat(dirfd, name, path, bufsize);
        path[len] = '\0';
        printf(" -> %s", path);
    }

    putchar('\n');
}

int main(int argc, char *argv[]) {
    if (!argv[1])
        argv[1] = ".";

    int dirfd = Open(argv[1], O_RDONLY | O_DIRECTORY, 0);
    char buf[DIRBUFSZ];
    int n;

    while ((n = Getdents(dirfd, (void *)buf, DIRBUFSZ))) {
        struct linux_dirent *d;
        /* TODO: Iterate over directory entries and call file_info on them. */
        // int getdents(unsigned int fd, struct linux_dirent *dirp
        //              unsigned int count);
        // getdents(2) returns directory entries, it reads several linux_dirent
        // structures from the directory reffered to by the open file descriptor
        // fd into the buffer pointed to by dirp. The argument count specifies
        // the size of that buffer.
        const void* end = buf + n;
        void* it = buf;
        while (it < end) {
            d = (struct linux_dirent*)it;
            file_info(dirfd, d->d_name);
            it += d->d_reclen; // d_reclen is length of this linux_dirent
        }
    }

    Close(dirfd);
    return EXIT_SUCCESS;
}
```

## Zadanie 5-7

:::danger
Autor: Jan Wańkowicz
:::

```c=
static void Sort(int parent_fd) {
	int nelem = ReadNum(parent_fd);

	if (nelem < 2) {
		WriteNum(parent_fd, ReadNum(parent_fd));
		Close(parent_fd);
		return;
	}

	int left_nelem = nelem/2 , right_nelem = nelem - nelem/2;

	sockpair_t left = MakeSocketPair();
	if(Fork())
		Close(left.child_fd);
	else
	{
		Close(left.parent_fd);
		Close(parent_fd);
		Sort(left.child_fd);
		exit(0);
	}
	sockpair_t right = MakeSocketPair();
	if(Fork())
		Close(right.child_fd);
	else
	{
		Close(right.parent_fd);
		Close(parent_fd);
		Sort(right.child_fd);
		exit(0);
	}
	SendElem(parent_fd,left.parent_fd,left_nelem);
	SendElem(parent_fd,right.parent_fd,right_nelem);
	Merge(left.parent_fd,right.parent_fd,parent_fd);
	Close(parent_fd);
	Close(left.parent_fd);
	Close(right.parent_fd);
	/* Wait for both children. */
	Wait(NULL);
	Wait(NULL);
}
```

![](https://i.imgur.com/JahgnXp.png)

