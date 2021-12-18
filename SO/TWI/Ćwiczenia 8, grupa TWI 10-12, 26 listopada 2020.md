# Ćwiczenia 8, grupa TWI 10-12, 26 listopada 2020

###### tags: `so20` `ćwiczenia` `twi`

1

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                | 7-1 |  7-2  |  7-3  |  7-4  | 7-5 |  7-6  |  7-7  | 7-8 |
|:---------------------- |:---:|:-----:|:-----:|:-----:|:---:|:-----:|:-----:|:---:|
| Kamil Banaś            |     |       |       |       |     |       |       |     |
| Marcin Dąbrowski       |  X  |   X   |   X   |   X   |  X  |       |   X   |     |
| Kamil Galik            |  X  | ==X== |   X   |   X   |  X  |   X   |   X   |     |
| Bartosz Głowacki       |  X  |   X   | ==X== |   X   |  X  |       |   X   |     |
| Jakub Kaczmarek        |  X  |   X   |   X   |   X   |  X  |       |   X   |     |
| Karol Machoś           |  X  |   X   |   X   |   X   |  X  |   X   |   X   |     |
| Małgorzata Maciejewska |  X  |   X   |   X   | ==X== |  X  |       |   X   |  X  |
| Antoni Pokusiński      |  X  |   X   |   X   |   X   |  X  |       |   X   |     |
| Mateusz Reis           |     |   X   |   X   |   X   |  X  |       |   X   |     |
| Adam Turowski          |  X  |   X   |   X   |   X   |  X  |       |   X   |     |
| Aleksander Uniatowicz  |  X  |   X   |   X   |   X   |  X  |   X   | ==X== |  X  |
| Jan Wańkowicz          |  X  |   X   |   X   |   X   |  X  |       |   X   |     |
| Krzysztof Wiśniewski   |  X  |   X   |   X   |   X   |     |       |   X   |     |
| Tomasz Woszczyński     |  X  |   X   |   X   |   X   |  X  |       |   X   |  X  |
| Jakub Zając            |  X  |   X   |   X   |   X   |  X  |       |   X   |     |
| Paweł Zmarzły          |  X  |   X   |   X   |   X   |  X  | ==X== |   X   |  X  |
| Adam Zyzik             |     |       |       |       |     |       |   X   |     |
:::

## Zadanie 7-1

:::danger
Autor: Jakub Zając
:::


**Stronicowanie na żądanie** (demand paging) jest metodą zarządzania pamięcią wirtualną, w której system operacyjny ładuje strony do pamięci z dysku tylko wtedy, gdy robiony jest do nich dostęp (i nie ma ich jeszcze w pamięci fizycznej). 

Gdyby system korzystający ze strategii stronicowania na żądanie pozwoliłby na modyfikację uruchominych plików wykonywalnych istniałaby możliwość zmodyfikowania fragmentu pliku, który znajdował się na stronie niezaładowanej jeszcze do pamięci. Przez co uruchomiony plik, robiąc dostęp do tej strony mógłby wykonać zmodyfikowany kod z niezdefiniowanym skutkiem.



## Zadanie 7-2

:::danger
Autor: Kamil Galik
:::

**odwzorowania plików w pamięć** - Pewien region pliku zostaje zmapowany bezpośrednio do pamięci wirtualnej provesu, który wywołał mmap. Na zmapowanym pliku można wykonywać operacje, odwołując się do pozycji jego konkretnych bajtów w pamięci. Dane do pamięci są wczytywane prosto z pliku.

**odwzorowania pamięci anonimowej** - Pamięć anonimowa nie ma odpowiadającego sobie pliku, wczytane strony są inicjalizowane jako zera. (Alokacja pamięci)

**odwzorowanine prywatne** - Zaprojektowane zostało tak, by zmiany w mapowaniu były widoczne tylko dla procesów, które je wywowałały. Gdy wiele procesów dzieli dane mapowanie to wszystkie mogą z niego czytać, natomiast próba zapisu spowoduje, że jądro skopiuje jego zawartość i wydzieli temu procesowi na wyłączność. Zmiany te nie są też przenoszone do odwzorowanego pliku (jeżeli to było odwzorowanine pliku w pamięć).

**odwzorowanine dzielone** - Każdy proces widzi zmiany wywoływane przez inne procesy oraz zmiany przechodzą na plik (jeżeli to było odwzorowanine pliku w pamięć).

Odwzorowanie prywatne plików blokowych ma niewiele sensu, bo zmiany wykonane na odwzorowanej pamięci nie zapisują się w zmapowanych plikach.

## Zadanie 7-3

:::danger
Autor: Bartosz Głowacki
:::

**Na podstawie opisu do tabeli 49 –1 podaj scenariusze użycia prywatnych i dzielonych odwzorowań plików w pamięć albo pamięci anonimowej.**

![](https://i.imgur.com/yD4jCT4.png)

* **prywatne odwzorowanie pliku w pamięć** - Zawartość mapowania jest inicjowana z obszaru plików. Wiele procesów mapujących ten sam plik początkowo współdzieli te same fizyczne strony pamięci, ale stosowana jest technika kopiowania przy zapisie, dzięki czemu zmiany mapowania dokonane przez jeden proces są niewidoczne dla innych procesów. Głównym zastosowaniem tego typu mapowania jest zainicjowanie obszaru pamięci z zawartości pliku. Niektóre typowe przykłady to inicjowanie segmentów *text* i *data* z odpowiednich części binarnego pliku wykonywalnego lub pliku biblioteki współdzielonej.

* **prywatne mapowanie anonimowe** - Każde wywołanie mmap() w celu utworzenia prywatnego anonimowego mapowania daje nowe mapowanie. Głównym celem mapowań prywatnych anonimowych jest przydzielenie nowej (zapełnionej zerami) pamięci dla procesu (np. Malloc () wykorzystuje w tym celu mmap () podczas przydzielania dużych bloków pamięci).
* **publiczne odwzorowanie pliku w pamięć** - wszystkie procesy mapujące ten sam obszar pliku współużytkują te same fizyczne strony pamięci, które są inicjowane z fragmentu pliku. Modyfikacje zawartości mapowania są przenoszone do pliku. Ten typ mapowania służy dwóm celom. Po pierwsze, zezwala na operacje wejścia / wyjścia pliku. Rozumiemy przez to, że plik jest ładowany do regionu pamięci wirtualnej procesu, a modyfikacje w tej pamięci są automatycznie zapisywane w pliku. W związku z tym operacje wejścia / wyjścia mapowane w pamięci stanowią alternatywę dla operacji wejścia / wyjścia read(2) i write(2) dla pliku tworzącego plik. Drugim celem tego typu mapowania jest umożliwienie niepowiązanym procesom współdzielenia obszaru pamięci (jest to bardzo szybkie).

* **publiczne mapowanie anonimowe** - Współdzielone anonimowe mapowanie: Podobnie jak w przypadku prywatnego anonimowego mapowania, każde wywołanie mmap() w celu utworzenia publicznego anonimowego mapowania tworzy nowe, odrębne mapowanie, które nie udostępnia stron żadnemu innemu mapowaniu. Różnica polega na tym, że strony odwzorowania nie są kopiowane podczas zapisu. Oznacza to, że kiedy dziecko dziedziczy mapowanie po fork(), rodzic i dziecko współdzielą te same strony pamięci RAM, a zmiany dokonane w zawartości mapowania przez jeden proces są widoczne dla drugiego procesu. Współdzielone anonimowe mapowania umożliwiają komunikację między tymi procesami.

**Pokaż jak je utworzyć z użyciem wywołania mmap(2).**
![](https://i.imgur.com/P0hAHFg.png)

* **addr** - adres wirtualny pod jakim ma się pojawić zaalokowana pamięć, w przypadku podania NULL jądro samo wybiera odpowiednie miejsce w pamięci. addr jest tylko wskazówką dla jądra i może ono wybrać inny adres np. kiedy uzna że lepiej zaokrąglić adres do początku strony lub kiedy adres koliduje z inną już zaalokowaną pamięcią. W przypadku flagi *MAP_FIXED* addr musi zostać wyrównany do początku strony.
* **length** - długość zaalokowanego bloku pamięci (zostaje zaokrąglony w górę do wielokrotności wielkości strony)
* **prot** - maska określająca ochronę
![](https://i.imgur.com/xDvZ2Z5.png)
* **flags** - maska bitowa określająca różne opcje mapowania (musi zawierać dokładnie jedną flagę z: MAP_PRIVATE, MAP_SHARED)
* **fd** - file descriptor identyfikujący plik do odwzorowania (ignorowane w przypadku anonimowym)
* **offset** - Argument przesunięcia określa punkt początkowy ping mapowania w pliku i musi być wielokrotnością rozmiaru strony systemowej. Aby zmapować cały plik, określilibyśmy przesunięcie na 0 i *length* jako rozmiar pliku.

**Co się z nimidzieje  po  wywołaniu fork(2)?**

w przypadku MAP_PRIVATE dziedziczone są przez dziecko ale jest robiona kopia przy zapisie a w przypadku MAP_SHARED nie ma robionej kopii.

**Czy  wywołanie execve(2) tworzy  odwzorowania  prywatne  czy  dzielone?**
prywatne bo nie chcemy by segment *data* w pliku elf został zmodyfikowany.

**Jeśli wystartujemy n instancji danego programu to ile razy jądro załaduje jego plik ELF do pamięci?**

plik elf w większej części zostaje załadowany z dysku do pamięci ram raz a następnie jest tam trzymany. Kod nie jest możliwy do zmodyfikowania więc jest tam trzymany tylko raz ale w przypadku modyfikowalnych sekcji robiona jest kopia przy zapisie.

**Które z wymienionych odwzorowań mogą wymagać użycia pamięci wymiany(ang. swap space) i kiedy?**

mapowania anonimowe w przypadku gdy próbujemy zaalokować tak dużo pamięci że nie mieści się to w pamięci RAM.

## Zadanie 7-4

:::danger
Autor: Małgorzata Maciejewska
:::

Linux obsługuje błąd stronicowania jako wyjątek jądra. Jądro obsługuje ten wyjątek na różne sposoby, w zależności od tego, czy jądro wykryje naprawialną usterkę strony, czy błąd nienaprawialny -- wówczas SIGSEGV do przestrzeni użytkownika.
3 przypadki konieczności obsługi błędu stronicowania:
- segmentation fault - próba dostępu do nieistniejącej w pamięci wirtualnej strony -- SIGSEGV z kodem MAPPERR
- protection exception - nie zgadzają się uprawnienia -- SIGSEGV z kodem SIGV_ACCERR
- normal page fault - bit valid ustawiony na zero -- usterka strony

**Poważna usterka strony** -- żądanej strony nie ma w buforze stron w pamięci fizycznej, aby ją naprawić trzeba sięgnąć do pamięci zewnętrznej
**Pomniejsza usterka strony** -- żądana strona jest w buforze stron w pamięci fizycznej (dane należą do innego procesu i naprawienie usterki polega na dzieleniu tej części danych z procesem, który potrzebuje do nich dostępu)
**Bufor stron** -- jądro buforuje przy pierwszym odczycie lub zapisie pliku dane w niewykorzystanym obrzarze RAMu, co przyspiesza odczyt zbuforowanych stron

Kiedy wystąpi błąd strony przy zapisie, mimo że pole «vm_prot» pozwala na zapis do obiektu wspierającego?
Błąd strony przy zapisie, mimo że pole «vm_prot» pozwala na zapis do obiektu wspierającego, wystąpi, gdy mamy do czynienia z  kopiowaniem przy zapisie -- vm_flags ustawione na COW.

Kiedy jądro wyśle SIGBUS do procesu posiadającego odwzorowanie pliku w pamięć?
Gdy mapowanie było dłuższe niż plik źródłowy i proces poprosi o dostęp do stron, które są poza zmapowanym plikiem (wraz z zaokrągleniem do pełnych stron (uzupełnieniem zerami)) 



## Zadanie 7-5

:::danger
Autor: Antoni Pokusiński
:::
Kod programu:
```c=
static int QuickSort(long table[], size_t left, size_t right) {
  pid_t pid_left = -1, pid_right = -1, pid = -1;

  /* TODO: If there is more to sort than FORKSORT_MIN start a subprocess. */
  if ( right-left+1 >= FORKSORT_MIN ){
    if ((pid = Fork())) {
      return pid;
    }
  }

  if (left < right) {
    if (right - left <= INSERTSORT_MAX) {
      InsertionSort(table, left, right);
    } else {
      size_t pivot = left + random() % (right - left + 1);
      size_t split = Partition(table, left, right, table[pivot]);

      if (left == split) {
        SwapElem(table, left, pivot);
        split++;
      } else {
        pid_left = QuickSort(table, left, split - 1);
      }

      pid_right = QuickSort(table, split, right);

      /* TODO: Wait for possible children and exit if created a subprocess. */
      if (pid_right != -1){
        Waitpid(pid_right, NULL, 0);
      }
      if (pid_left != -1){
        Waitpid(pid_left, NULL, 0);
      }
      if ( right-left+1 >= FORKSORT_MIN ){
        exit(0);
      }

    }
  }
  
  (...)
  
   /* TODO: Allocate table... */
  long* table = Mmap(
    NULL, 
    sizeof(long)*NELEMS, 
    PROT_READ | PROT_WRITE, 
    MAP_SHARED | MAP_ANONYMOUS, 
    -1, 
    0
  );

```
Przed podziałem na podprocesy:
```
real    0m8,678s
user    0m8,473s
sys     0m0,176s
```
Po podziale:
```
real    0m5,202s
user    0m11,639s
sys     0m0,857s
```

W 1. przypadku mamy pojedynczy proces wykonujący obliczenia, więc działamy tylko na 1 procesorze, zaś w drugim wykonujemy obliczenia równolegle, co pozwala na użycie wielu procesorów. 

Mamy więc zwiększenie zużycie procesora , czyli czasu, jaki został poświęcony na wykonywanie instrukcji, jednak zmniejszył się czas przebywania w systemie, czyli czas od momentu utworzenia do zakończenia procesu.

**Prawo Amdahla** - możemy zwiększyć wydajność systemu używając wielu procesorów dla obliczeń równoległych, jednak to zwiększenie wydajności jest ograniczone przez czas potrzebny do wykonania operacji, które muszą być wykonane szeregowo (w odpowiedniej kolejności).

W naszym programie równolegle nie może być wykonywane ```partition``` i ```insertion_sort```.
## Zadanie 7-6

:::danger
Autor: Paweł Zmarzły
:::

```c=
/* Open (`size` = 0) or create (`size` > 0) database from `name` file. */
static void db_open(db_t *db, const char *name, size_t size)
{
  assert(powerof2(size));

  int fd = Open(name, O_RDWR | O_CREAT | (size ? O_EXCL : 0), DB_MODE);

  if (size == 0)
  {
    struct stat sb;
    Fstat(fd, &sb);
    size = sb.st_size / sizeof(entry_t);
    if (size == 0)
      size = 1;
  }

  /* TODO: Setup DB structure, set file size and map the file into memory.
           Inform OS that we're going to read DB in random order. */
  Ftruncate(fd, size * sizeof(entry_t));
  db->entry = Mmap(NULL, size * sizeof(entry_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  Madvise(db->entry, size * sizeof(entry_t), MADV_RANDOM);
  db->size = size;
  db->name = strdup(name);

  Close(fd);
}

/* Attempt to increase size of database. */
static bool db_rehash(db_t *db, size_t new_size)
{
  assert(powerof2(new_size));

  /* Create new database. */
  db_t new[1];

  char *name = alloca(strlen(db->name) + sizeof(".reshash") + 1);
  strcpy(name, db->name);
  strcat(name, ".rehash");
  db_open(new, name, new_size);

  /* Copy everything from old database to new database. */
  /* TODO: Inform OS that we're going to read DB sequentially. */
  Madvise(db->entry, db->size * sizeof(entry_t), MADV_SEQUENTIAL);

  for (size_t i = 0; i < db->size; i++)
  {
    if (!db_maybe_insert(new, db->entry[i]))
    {
      /* Oops... rehashing failed. Need to increase db size and try again. */
      /* TODO: Remove new database, since rehashing failed. */
      db_close(new);
      Unlink(name);

      return false;
    }
  }

  /* TODO: Replace old database with new one, remove old database. */
  Rename(new->name, db->name); // Zastąpi stary plik, o ile nie ma RENAME_NOREPLACE.
  Munmap(db->entry, db->size * sizeof(entry_t));

  db->entry = new->entry;
  db->size = new->size;
  free(new->name);
  return true;
}

static void doit(const char *path, op_t mode)
{
  db_t db;
  db_open(&db, path, 0);

  /* If input file is a terminal device then use standard reading technique. */
  /* TODO: Use fstat instead to handle pipes correctly. */
  struct stat st;
  Fstat(STDIN_FILENO, &st);

  if (!S_ISREG(st.st_mode)) // isatty?
  {
    char buf[ENT_LENGTH + 1];
    while (fgets(buf, ENT_LENGTH + 1, stdin))
      consume_line(buf, &db, mode);
  }
  else
  {
    /* TODO: Map stdin into memory, and read it line by line. */
    void *buf = Mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, STDIN_FILENO, 0);
    char *end = buf;
    do
    {
      end = consume_line(end, &db, mode);
    } while (end != NULL);
    Munmap(buf, st.st_size);
  }

  db_close(&db);
}
```

## Zadanie 7-7

:::danger
Autor: Aleksander Uniatowicz
:::

```c=
noreturn void external_command(char **argv) {
  const char *path = getenv("PATH");

  if (!index(argv[0], '/') && path) {
    /* TODO: For all paths in PATH construct an absolute path and execve it. */
    size_t len = strlen(path);
    while (len) {
      size_t path_len = strcspn(path, ":");
      char *curr_path = strndup(path, path_len);
      strapp(&curr_path, "/");
      strapp(&curr_path, *argv);
      len -= path_len + (path[path_len] == ':');
      printf("%s \n%s %ld\n", path, curr_path, len);
      path += path_len + 1;

      execve(curr_path, argv, environ);
      free(curr_path);
    }
  } else {
    (void)execve(argv[0], argv, environ);
  }

  msg("%s: %s\n", argv[0], strerror(errno));
  exit(EXIT_FAILURE);
}

```

## Zadanie 7-8

:::danger
Autor: Tomasz Woszczyński
:::

```c=
// for this to work, we should comment out 'token[n] = NULL' in do_redir
// before do_redir is implemented, as it removes necessary token

/* Execute internal command within shell's process or execute external command
 * in a subprocess. External command can be run in the background. */
static int do_job(token_t *token, int ntokens, bool bg) {
  int input = -1, output = -1;
  int exitcode = 0;

  ntokens = do_redir(token, ntokens, &input, &output);

  if (!bg) {
    if ((exitcode = builtin_command(token)) >= 0)
      return exitcode;
  }

  sigset_t mask;
  Sigprocmask(SIG_BLOCK, &sigchld_mask, &mask);

  /* TODO: Start a subprocess, create a job and monitor it. */
  pid_t pid = Fork();

  if (pid == 0) {
    // allow signals for the subprocess that are by default 
    // turned off for shell, i.e. CTRL+Z etc.
    Signal(SIGTSTP, SIG_DFL);
    Signal(SIGTTIN, SIG_DFL);
    Signal(SIGTTOU, SIG_DFL);

    // possibly open (duplicate) file descriptor that was changed
    // in do_redir call (it could've changed input/output values)
    if (input != -1) {
      Dup2(input, STDIN_FILENO);
      Close(input);
    }

    if (output != -1) {
      Dup2(output, STDOUT_FILENO);
      Close(output);
    }

    // finally call the command (it is surely not builtin)
    external_command(token);
  }

  // create own process group and then a job based on it, take
  // into account whether it is FG/BG process and then add the
  // process to the job
  Setpgid(pid, pid);
  int new_job = addjob(pid, bg);
  addproc(new_job, pid, token);

  // close file descriptors that were possibly opened earlier
  MaybeClose(&input);
  MaybeClose(&output);

  // based on bg value, run the job in bg or fg
  if (bg)
    printf("[%d] running '%s' [do_job called]\n", new_job, jobcmd(new_job));
  else
    monitorjob(&mask);

  Sigprocmask(SIG_SETMASK, &mask, NULL);
  return exitcode;
}
```