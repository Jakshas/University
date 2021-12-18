# Ćwiczenia 13, grupa TWi 10–12, 14 stycznia 2021

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                | 12-1  | 12-2  | 12-3  | 12-4 | 12-5  | 12-6 | 12-7  | 12-8 |
|:---------------------- |:-----:|:-----:|:-----:|:----:|:-----:|:----:|:-----:|:----:|
| Kamil Banaś            |       |       |       |      |       |      |       |      |
| Marcin Dąbrowski       |   X   |   X   |   X   |  X   |   X   |  X   |       |      |
| Kamil Galik            | ==X== |   X   |   X   |  X   |   X   |  X   |       |      |
| Bartosz Głowacki       |   X   |       | ==X== |      |   X   |  X   |       |      |
| Jakub Kaczmarek        |       |       |       |      |       |      |       |      |
| Karol Machoś           |   X   |   X   |   X   |  X   | ==X== |  X   |       |      |
| Małgorzata Maciejewska |   X   |   X   |   X   |  X   |   X   |      |       |      |
| Antoni Pokusiński      |   X   |   X   |       |      |   X   |      |       |      |
| Mateusz Reis           |   X   |   X   |   X   |  X   |   X   |      |       |      |
| Adam Turowski          |   X   |   X   |   X   |  X   |   X   |  X   |       |      |
| Aleksander Uniatowicz  |   X   | ==X== |   X   |  X   |   X   |  X   |   X   |  X   |
| Jan Wańkowicz          |   X   |   X   |   X   |      |   X   |  X   |   X   |      |
| Krzysztof Wiśniewski   |   X   |   X   |   X   |  X   |   X   |  X   |       |      |
| Tomasz Woszczyński     |   X   |   X   |   X   |  X   |       |      |       |      |
| Jakub Zając            |  :x   |  :x   |  :x   |      |  :x   |      |       |      |
| Paweł Zmarzły          |   X   |   X   |   X   |  X   |   X   |  X   | ==X== |  X   |
| Adam Zyzik             |   X   |   X   |   X   |      |   X   |      |       |      |
:::

## Zadanie 12-1

:::danger
Autor:  Kamil Galik
:::

```c=
__thread long myid;
static char **strtab;

void *thread(void *vargp) {
    myid = *(long *)vargp;
    static int cnt = 0;
    printf("[%ld]: %s (cnt=%d)\n", myid, strtab[myid], ++cnt);
    return NULL;
}

int main(int argc, char *argv[]) {
    ...
    strtab = argv;
    while (argc > 0) {
        myid = --argc;
        pthread_create(&tid, NULL, thread, (void *)&myid);
    }
    ...
}
```
**Współdzielone zmienne**: Zmienne do których przynajmniej 2 różne wątki robią referencję.

Współdzielone zmienne:
- cnt -> Statyczna zmienna lokalna, istnieje jej jedna instancja współdzielona przez wątki utworzone przez pthread_create().
- strtab -> Zmienna globalna, dostępna dla wszystkich wątków.
- myid -> W pthread_create() przekazujemy adres instancji myid z main i w wątkach robimy dostęp do wartości. (Jest współdzielona mimo słowa kluczowego **\_\_thread**, które sprawia, że każdy wątek ma swoją instancję zmiennej myid)
- argv[0] -> Przekazujemy wartość 0 jako argument \*thread przez pthread_create oraz strtab wskazuje na argv, więc strtab[myid] = argv[0].


**Wyścig**: Sytuacja, kiedy dwa wątki zrobią odczyt/zapis do współdzielonej zmiennej i finalny wynik tych zależy od tego, który i w jakim momencie to zrobi.

Źródłem wyścigów będą:
- cnt:  przykład z wykładu, wątki mogę się tak przepleść, że więcej niż jeden wątek odczyta i zapisze tę samą wartość, co daje nieprawidłowy wynik dla każdego kolejnego wątku.
- myid:  zanim nowoutworzony wątek zostanie zeschedulowany, to możliwe że rodzic zmieni już swoje myid.

## Zadanie 12-2

:::danger
Autor: Aleksander Uniatowicz
:::


**Sekcja krytyczna**:  Część programu, w której proces wykonuje operacje na współdzielonej pamięci, które mogą prowadzić do wyścigów.

Założenia rozwiązania problemu sekcji krytycznej:
- **Żadne dwa procesory nie mogą jednocześnie wykonywać instrukcji ze swoich sekcji krytycznych. (Nie może istnieć przeplot instrukcji z sekcji krytycznych dotyczących tych samych danych współdzielonych**)- Zapobiega to powstawaniu wyścigów, ponieważ wrażliwe bloki instrukcji są wykonywane w odddzielnych momentach w czasie i nie ma sytuacji, że wynik jest zależny od dokładnej kolejności wykonywania instrukcji przez procesy (Do tego niwelujemy powstanie błędnego wyniku w skutek wyścigów).
- **Nie można zakładać faktów dotyczących sprzętu, na którym działa program (ilość procesorów, ich szybkość etc.)** - Program powinien działać uniwersalnie na dowolnym sprzęcie i zwracać prawidłowy wynik niezależnie od aspektów sprzętowych. 
- **Proces wykonujący instrukcje poza swoją sekcją krytyczną nie może blokować innych procesów** - Procesy powinny być blokowane jedynie przy próbie wejścia w swoją sekcję krytyczną, gdy inny proces jest w trakcie wykonywania swojej. Pozostałe procesy powinny móc spokojnie wykonywać swoje zadania. 
- **Żaden proces nie może czekać wiecznie na wejście do swojej sekcji krytycznej** - każdy proces musi ukończyć swoje zadanie. Żaden proces nie może zostać zagłodzony.

**Wyłączenie przerwań** - Podejście do rozwiązania problemu sekcji krytycznych polegające na wyłączeniu obsługi przerwań w momencie gdy program wchodzi do swojej sekcji krytycznej i włączeniu jej ponownie, gdy tę sekcję opuści. Proces jest zmieniany jedynie w wyniku przerwań, więc przy takiej blokadzie mamy pewność, że bieżący proces się nie zmieni w trakcie wykonywania opeacji z sekcji krytycznej.

Problemem jest tutaj to, że dajemy programowi w user space potężne i niebezpieczne narzędzie. W komputerze z jednym procesorem, po wyłączeniu przerwań może się okazać, że ponownie ich nie włączamy, co może zawiesić cały system. Przy okazji może wystąpić wyścig z jądrem, które czasami używa tej strategii przy aktualizowaniu list. Wtedy wymagane jest wyłączenie przerwań, a my możemy je właczyć. W systemie z wieloma procesorami rozwiązanie to traci sens, bo wyłączamy przerwania jedynie na jednym CPU, a wątki z pozostałych CPU dalej mają dostęp do współdzielonej pamięci.

![](https://i.imgur.com/Uu03k2Z.png)

**Drobno-ziarniste blokowanie** - strategia radzenia sobie z sekcją krytyczną polegająca na wydzieleniu pojedynczych zmiennych i struktur wydzielonych i stworzenie dla każdej z nich osobnej blokady.

W ten sposób mamy wiele sekcji krytycznych i w każdej z nich może przebywać jeden proces, a co za tym idzie wiele procesów naraz może wykonywać operacje ze swoich (różnych) sekcji krytycznych, co zwiększa możliwość zrównoleglenia danych partii programu.
Z prawa Amdahla im więcej operacji w programie można zrównolegli oraz im więcej procesorów może działać równolegle tym większe jest przyspieszenie działania programu.


## Zadanie 12-3

:::danger
Autor: Bartosz Głowacki
:::

implementacja compare-and-swap
```c=
typedef int spin_t;
int compare_and_swap(spin_t *ptr, int expected, int new) {
    int original =*ptr;
    if (original == expected)
        *ptr = new;
    return original;
}
```

implementacja blokady wirującej
```c=
void lock(spin_t *lock) {
    while (CompareAndSwap(lock, 0, 1) == 1); // spin
}

void unlock(spin_t *p) {
    *p = 0;
}
```

**Czemu blokada wirująca nie jest sprawiedliwa?**
![](https://i.imgur.com/hqR3ybN.png)
blokada wirująca nie wprowadza żadnej kolejności w jakiej czekające wątki mają zostać odblokowane przez co może zajść sutuacja głodzenia kiedy jeden wątek ciągle czeka i nie może nic zrobić a inne wątki są odblokowywane ciągle. Problem ten możnaby rozwiązać wprowadzając przykładowo kolejkę FIFO zablokowanych bloków.

**Wiemy, że w przestrzeni użytkownika wątek może zostać wywłaszczony,jeśli znajduje się w sekcji krytycznej chronionej dowolną blokadą. Jakie problemy to rodzi?**

wyobraźmy sobie sytuację kiedy jest dużo wątków i każdy z nich czeka na odblokowanie sekcji krytycznej. Problem z wirującą blokadą jest taki że kiedy zacznie się wykonywać wątek czekający to robi się nieskończona pętla która może nawet trwać całą długość najdłuższego możliwego kwantu czasu i wtedy w tym czasie marnowane są cykle procesora, czas i energia (bo nieskończona pętla może spowodować nawet przyśpieszenie taktowania procesora). W przytoczonym wyżej przykładzie z wieloma wątkami może być tak że zanim zacznie być wykonywany wątek który nałożył blokadę zacznie i skończy się wiele wątków czekających co może trwać bardzo dużo czasu i zużyć dużo energii kompletnie bez sensu.

## Zadanie 12-4

:::danger
Autor: Małgorzata Maciejewska
:::

Warunki konieczne do zakleszczenia:
(skopiowane z http://www.mif.pg.gda.pl/homepages/marcin/PWIR2018_2019/pwir-1.pdf)
1. Wzajemne wykluczanie (Mutual exclusion)– istnieje co najmniej jeden zasób, który w danym czasie może być wykorzystywany tylko przez jeden proces
2. Brak wywłaszczania (No preemption) – zasoby nie podlegają wywłaszczeniu, tzn. zasób nie może zostać odebrany zajmującemu go procesowi podczas wykorzystania zasobu
3. Przetrzymywanie zasobu i oczekiwanie na inny (Hold-and-wait)
4. Cykl w grafie oczekiwania na zasoby (Circular wait)– istnieje zamknięty łańcuch procesów (cykl), w którym każdy proces oczekuje na zasoby przetrzymywane przez proces poprzedzający, np. P1 zajmuje Z1, P2 zajmuje Z2, P1 oczekuje na Z2, P2 oczekuje na Z1

Przeciwdzałanie zakleszczeniom -- działania podjęte w celu uniknęcia zakleszczeń, które polegają na przypilnowaniu, aby co najmniej jeden z warunków koniecznych do wystąpienia zakleszczenia nie będzie spełniony

Przeciwdzałanie cyklom w grafie oczekiwania na zasoby -- pisanie kodu blokującego tak, aby nigdy nie wywołał cyklu - często robi się to uporządkowaniem blokad (np. w przypadku dwóch blokad, alby zwsze jenda pojawiała się przed drugą). Całkowitego uporządkowania się nie stosuje, ale częściowe uporządkowanie jest używane w mapowaniu pamięci w Linuxach.

Przeciwdziałanie hold-and-wait -- nałożenie wszystkich blokad na raz, atomowo. To rozwiązanie nie jest stosowane, bo trzeba wcześniej wiedzieć, jakie blokady będą potrzebne, co jest problematyczne, zmniejsza też współbieżność, bo blokady są zakładane wcześniej a nie wtedy gdy są potrzebne

Przeciwdzałanie brakowi wywłaszczania -- użycie pthread_mutex_trylock(), np. w takim kodzie:
```
 top:
 pthread_mutex_lock(L1);
 if (pthread_mutex_trylock(L2) != 0) {
 pthread_mutex_unlock(L1);
 goto top;
 }
 ```
Uwaga na livelocki (ale je da się rozwiązać, np. przez wrowadzenie losowego opóźnienia przed kolejnym obrotem pętli). Pojawiają się problemy z związane z hermetyzacją -- mogą być problemy z implementacją powtoru na początek w przypadku gdy jedna z blokad jest zakopana w programie, i trzeba uważać na zwalnianie zasobów. To rozwiązanie jest jednakowoż czasami używane pod pewnymi warunkami (np. w wektorach w Javie).

Przeciwdziałanie wzajemnemu wykluczaniu -- budowanie takich struktur przy pomocy instrukcji hardwerowych, żeby nie były porzebne blokady (operacje atomowe). Bodowanie tych struktur, zwłąszcza skomplikowanych, jest dość trudne, ale czasem jest wykorzystywane, np. w jądrze Linuxa.

Ponadto sposobami radzenia sobie z zakleszczeniami jest scheduling oraz wykrywanie rzadko występujących zakleszczeń i naprawianie.

## Zadanie 12-5

:::danger
Autor: Karol Machoś
:::

![](https://i.imgur.com/w68C7Vr.png)
### Wytłuszczone pojęcia:
- **wzajmne wykluczanie** - jedna z metod kontroli wykonywania równoległych procesów, w taki sposób aby nie dochodziło do wyścigów. W momencie w którym jeden proces wykonuje instrukcje zawarte w tzw. sekcji krytycznej (zad2), reszta procesów nie przejdzie do ich wykonywania.


```c=
shared boolean blocked [2] = { false, false };
shared int turn = 0;

void P (int id) {
    while (true) {
        blocked[id] = true;
        while (turn != id) {
            while (blocked[1 - id])
                continue;
            turn = id;
        }
        /* put code to execute in critical section here */
        blocked[id] = false;
    }
}

void main() { parbegin (P(0), P(1)); }
```
(Kontr)przykładowy przebieg dwóch wątków:
```c=
P1: while (true) {
P1:   blocked[1] = true;
P1:   while (turn != 1) {
P1:     while (blocked[0]) {
P1:     } // Przełączenie kontekstu z P1 na P0. W tym momencie blocked={false,true}
P0: while (true) {
P0:   blocked[0] = true;
P0:   while (turn != 0) {
P0:   }
P0:   criticalSection(P0);
P1:     turn = 1; // Przełączenie kontekstu z P0 na P1
P1:   while (turn != 1)
P1:   }
P1:   critcalSection(P1);
```

## Zadanie 12-6

:::danger
Autor: Adam Turowski
:::
![](https://i.imgur.com/hHBQN8T.png)

### Czemu oddanie czasu procesora funkcjią `yield` nie rozwiązuje wszystkich problemów?
* Zakładając, że działa $N$ wątków oraz, że jeden z nich jest w sekcji krytycznej, pozostałe $N-1$ wątków jest blokowane. Dzięki wykorzystaniu funkcji `yield` znacząco ograniczone, względem blokad wirujących, będzie wykorzystanie czasu procesora na wykonywanie kodu wątków zablokowanych. Jednakże nadal będzie ono miało miejsce, bo, przy przełączaniu kontekstu, w $N-1$ przypadkach będzie należało sprawdzić, czy dany wątek jest blokowany czy nie. 
* W żaden sposób nie zmieni się problem głodzenia wątków.

### Zreferuj implementację **blokad usypiających** podaną w 28.14
```c=
int TestAndSet(int *old_ptr, int new){
    int old = *old_ptr;
    *old_ptr = new;
    return old;
}

typedef struct __lock_t {
    int flag;
    int guard;
    queue_t *q;
}

void lock_init(lock_t *m){
    m->flag = 0;
    m->guard = 0;
    queue_init(m->q);
}

void lock(lock_t *m){
    while(TestAndSet(&m->guard, 1) == 1);
    if(m->flag == 0){ // zasów nie był blokowany
        m->flag = 1; // zablokuj zasób
        m->guard = 0; 
    } else{
        queue_add(m->q, gettid()); // ustaw się w kolejce po zasób
        setpark(); // zadeklaruj, że kładziesz się spać
        m->guard = 0;
        park(); // idź spać
    }
}

void unlock(lock_t *m){
    while(TestAndSet(&m->guard, 1) == 1);
    if(queue_empty(m->q)) // żaden wątek nie czeka na zasób
        m->flag = 0; // odblokuj zasób
    else
        unpark(queue_remove(m->q)); // obudź pierwszy wątek w kolejce
    m->guard = 0;
}
```

### Czemu jest ona niepoprawna bez użycia funkcji `setpark`?
Niewywoływanie funkcji `setpark` tworzy możliwość wystąpienia wyścigu, na chwilę przed wywołaniem `park`. Może dojść do sytuacji w której wątek będzie próbował "zaparkować" i w tym momencie dojdzie do przełączenia kontekstu na wątek blokujący, który go odblokuje. Po ponownym przełączeniu kontekstu do wątku "parkującego", może dojść do jego uśpienia na zawsze.

Aby tego uniknąć można użyć funkcji `setpark`, która pozwala wątkowi poinformować pozostałe, że ma on zamiar "zasnąć". Jeżeli w tym momencie zostanie wywłaszczony, i kolejny na liście proces zawoła `park` to funkcja, zamiast wywołać `sleep`, powróci od razu.

### Czy rozwiązuje problem głodzenia?
Wykorzystanie listy, w celu ustalenia kolejności wykonywania wątków, z pewnością ogranicza problem głodzenia, ale nie rozwiązuje go. Nadal nie ma żadnych zabezpieczeń przed tym, że wątek nałoży blokadę "na zawsze", pozbawiając pozostałe wątki zasobów lub wpadnie w "pętlę" wywołań `yield`, podczas gdy inne wątki na zmianę będą wykonywać swoje sekcje krytyczne.


## Zadanie 12-7

:::danger
Autor: Paweł Zmarzły
:::

**semafor zliczający** - pozwala na dostęp do zasobu, maksymalnie X wątkom jednocześnie
**semafor binarny** - jak wyżej, przyjmuje wartości 0 i 1
**muteks** - posiada właściciela i tylko on może z niego zdjąć blokadę. Można z nim próbować rozwiązać [problem priority inversion](https://www.freertos.org/Real-time-embedded-RTOS-mutexes.html)

`mutex` - blokada nad `count`
`delay` - na tym śpimy

- count = 2
- wątki C i D wywołują csem::P() -> count = 0
- wątki A i B wywołują csem::P() -> count = -2
    - wątki A i B zostają między linią 17 a 18
- wątki C i D wywołują csem::V
    - jako że nic nie czeka jeszcze na delay, w linii 27 delay jest zwiększany, najpierw przez C potem przez D, ale jest to semafor binarny, więc "gubimy" jedno wywołanie 
- count = 0, ale delay = 1, więc A lub B pójdzie spać!

## Zadanie 12-8

:::danger
Autor: Paweł Zmarzły
:::

https://www.nongnu.org/ext2-doc/ext2.html

**zajętość i-tego i-węzła**:

- `bg_id = (inode - 1) / s_inode_per_groups`
- z BGDT skocz do `bg_inode_bitmap` w danej grupie `bg_id`, odczytaj bit zajętości

**zajętość k-tego bloku**:

- `bg_id = (block_id - first_data_block) / s_blocks_per_groups`
- z BGDT skocz do `bg_block_bitmap` w danej grupie `bg_id`, odczytaj bit zajętości

**adres (fizyczny) bloku zawierającego dane k-tego (logicznego) bloku pliku opisanego przez i-ty i-węzeł**:

- sprawdzamy czy inode jest zajęty
- `bg_id = (inode - 1) / s_inode_per_groups`
- z BGDT skocz do `bg_inode_table` w danej grupie `bg_id`
- `local inode index = (inode - 1) % s_inodes_per_group`
- `inode = bgdt[bg_id]->bg_inode_table[local_inode_index]`
- sprawdzamy `inode->i_blocks`: Since this value represents 512-byte blocks and not file system blocks, this value should not be directly used as an index to the `i_block` array. Rather, the maximum index of the `i_block` array should be computed from `i_blocks / ((1024<<s_log_block_size)/512)`.
- czytamy `i_block`:
    - The first 12 blocks are direct blocks
    - The 13th entry in this array is the block number of the first indirect block; which is a block containing an array of block ID containing the data. Therefore, the 13th block of the file will be the first block ID contained in the indirect block. With a 1KiB block size, blocks 13 to 268 of the file data are contained in this indirect block.
    - analogicznie dla doubly indirect i triply indirect

```c
if (nr_bloku < 12) { return direct }
nr_bloku = (nr_bloku - 12) / (BLOCK_SIZE / 4)
// dla 1KiB: BLOCK_SIZE / 4 = 256
if (nr_bloku < 1) { return single_indirect }
nr_bloku = (nr_bloku - 1) / (BLOCK_SIZE / 4)
if (nr_bloku < 1) { return double_indirect }
nr_bloku = (nr_bloku - 1) / (BLOCK_SIZE / 4)
if (nr_bloku < 1) { return triple_indirect }
return file_too_large
```
