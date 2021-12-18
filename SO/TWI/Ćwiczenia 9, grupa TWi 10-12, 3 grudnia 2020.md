# Ćwiczenia 9, grupa TWi 10-12, 3 grudnia 2020

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej ko
lumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) nal
eży oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                |  8-1  |  8-2  | 8-3 | 8-4 | 8-5 | 8-6 | 8-7 | 8-8 |
|:---------------------- |:-----:|:-----:|:---:|:---:|:---:|:---:|:---:|:---:|
| Kamil Banaś            |       |       |     |     |     |     |     |     |
| Marcin Dąbrowski       | ==X== |   X   |  X  |  X  |  X  |     |     |  X  |
| Kamil Galik            |   X   |   X   |  X  |     |  X  |     |     |     |
| Bartosz Głowacki       |   X   |   X   |  X  |  X  |  X  |     |     |  X  |
| Jakub Kaczmarek        |   X   |   X   |  X  |  X  |  X  |     |     |  X  |
| Karol Machoś           |   X   |   X   |  X  |  X  |  X  |     |     |  X  |
| Małgorzata Maciejewska |   X   |   X   |  X  |  X  |     |     |     |     |
| Antoni Pokusiński      |   X   |   X   |     |  X  |  X  |  X  |     |  X  |
| Mateusz Reis           |   X   |   X   |     |     |     |  X  |     |  X  |
| Adam Turowski          |   X   |   X   |  X  |     |  X  |     |     |  X  |
| Aleksander Uniatowicz  |   X   |   X   |  X  |==X==|  X  |  X  |     |  X  |
| Jan Wańkowicz          |   X   |   X   |  X  |  X  |  X  |  X  |     |  X  |
| Krzysztof Wiśniewski   |   X   | ==X== |  X  |  X  |  X  |     |     |  X  |
| Tomasz Woszczyński     |   X   |   X   |  X  |  X  |  X  |  X  |     |  X  |
| Jakub Zając            |   X   |   X   |  X  |     |     |  X  |     |     |
| Paweł Zmarzły          |   X   |   X   |  X  |  X  |  X  |  X  |  X  |  X  |
| Adam Zyzik             |       |       |     |     |     |     |     |     |
:::

## Zadanie 8-1

:::danger
Autor: Marcin Dąbrowski
:::

# Zadanie 1
### Systemy uniksowe udostępniają wywołania systemowe sbrk(2) oraz parę mmap(2) i munmap(2). Służą one do przydziału stron na użytek bibliotecznego algorytmu zarządzania pamięcią. Czemu implementacje malloc(3) preferują drugą opcję? Wyjaśnij to odwołując się do mapy pamięci wirtualnej procesu.
***Wskazówka**: Rozważ scenariusz, w którym proces zwolnił dużo pamięci przydzielonej na początku jego życia.*
![](https://i.imgur.com/4oDdgZt.png)

**sbrk()** - pozwala przesunąć koniec sterty (jeśli jest dostępna niezaalokowana pamięć), efektywnie powiększając ją. W **malloc**u używany do alokacji pamięci o rozmiarze mniejszym niż wartość **MMAP_THRESHOLD** (domyślnie 128kB).

**mmap()** - pozwala zaalokować strony pamięci bezpośrednio w miejscu pomiędzy stertą a stosem.

Dlaczego **malloc()** preferuje wykorzystanie **mmap()** nad **sbrk()**?

Za przykład weźmy proces, który na samym początku działania alokuje duży obszar pamięci, który następnie jest zwalniany. Zanim to nastąpi, alokujemy kolejny, mniejszy, obszar. Rozważmy sytuacje:
* używamy wywołania **sbrk()**
* używamy wywołania **mmap()**

W pierwszej z nich dochodzi do dwukrotnego przesunięcia końca sterty. Po zwolnieniu dużego bloku pamięci, efektywnie tracimy dostęp do niej, ponieważ używając **sbrk()** jesteśmy w stanie manipulować tylko końcem sterty. Sprawia to, że jeśli chcielibyśmy ponownie zaalokować duży blok pamięci, to musielibyśmy znowu zwiększyć wartość końca sterty (nie możemy go zmniejszyć, bo zaalokowany jest też mały obszar pamięci). Nie byłoby możliwości wykorzystania pamięci zwolnionej.

Używanie **mmap()** pozwaliłoby nam wykorzystać ponownie ten obszar.  

## Zadanie 8-2

:::danger
Autor: Krzysztof Wiśniewski
:::
### Wyjaśnij różnicę między fragmentacją wewnętrzną i zewnętrzną.
**Fragmentacja wewnętrzna** - Straty w zaalokowanej pamięci (pamięć z której nie korzysta program używający malloca) spowodowane:
* zaokrąglaniem ilości zaalokowanym słów pamięci do podzielnych przez 2
* potrzebą przechowywania informacji o strukturze (np. wskaźnik używany przez free)

**Fragmentacja zewnętrzna** - Straty w zaalokowanej pamięci (pamięć z której nie korzysta program używający malloca) spowodowane dziurami w pamięci po zdealokowaniu pamięci (*free*)
Przykład:
![](https://i.imgur.com/NpkJqS0.png)
mamy 8 wolnych słów pamięci, ale nie jesteśmy w stanie zaalokować bloku o rozmiarze 7-iu słów pamięci

**[Kompaktowanie](https://en.wikibooks.org/wiki/Memory_Management/Memory_Compacting)** - zmiana położenia bloków pamięci w celu pozbycia się zbędnych przerw między nimi (fragmentacji zewnętrznej)


### Czemu nie można zastosować kompaktowania w bibliotecznym algorytmie przydziału pamięci?
Bo możemy mieć jakieś wskaźniki na zaalokowany blok pamięci i po przesunięciu tego bloku byłyby błędne, a biblioteczny program nie ma do nich dostępu i nie mógłby ich poprzestawiać.

### Na podstawie §2.3 opowiedz o dwóch głównych przyczynach występowania fragmentacji zewnętrznej.
**Fragmentation is caused by isolated deaths.**
A crucial issue is the creation of free areas whose neighboring areas are not free. This is a function of two things: which objects are placed in adjacent areas and when those objects die. Notice that if the allocator places objects together in memory, and they die at the same time" (with no intervening allocations), no fragmentation results: the objects are live at the same time, using contiguous memory, and when they die they free contiguous memory. An allocator that can predict which objects will die at approximately the same time can exploit that information to reduce fragmentation, by placing those objects in contiguous memory


**Fragmentation is caused by time-varying behavior.**
Fragmentation arises from changes in the way a program uses memory - for example, freeing small blocks and requesting large ones. This much is obvious, but it is important to consider patterns in the changing behavior of a program, such as the freeing of large numbers of objects and the allocation of large numbers of objects of different types. Many programs allocate and free different kinds of objects in different stereotyped ways. Some kinds of objects accumulate over time, but other kinds may be used in bursty patterns. The allocator's job is to exploit these patterns, if possible, or at least not let the patterns undermine its strategy.
## Zadanie 8-3

:::danger
Autor: Kamil Galik
:::

Patterny:
- Ramp: Zbieranie coraz większe ilości pamięci w czasie (np. zbierane i zachowywanie logów)
- Peak: W trakcie danej części procesu alokowana i wykorzystywana jest pamięć, aby później większośc z niej została zwolniona (Zachowane zostają np. rezultaty wykonania tej części).
- Plateau: Alokacja dużej ilości pamięci "na zapas", aby później z niej korzystać.

![](https://i.imgur.com/GEW1aww.png)
Grobner rozbija złozone wyrażenia w liniową kombinację wielomianów, co wymaga od niego ciągłego zapamiętywania i przepisywania danych. Wykorzystany jest więc ramp.

![](https://i.imgur.com/HGgzehH.png)
GCC w  trakcie kompilacji dużego pliku źródłowego. Widać wykorzystanie peaka. Dane są na bieżąco alokowane i zwalniane.

![](https://i.imgur.com/Kk3PSjg.png)
Ewidentne użycie Plateau. Na początku działania zostaje zaalokowany duży blok pamięci i jest używany przez całe działanie programu.



Czas życia bloku a jego rozmiar: Typ obiektu jest zwykle związany z jego rozmiarem. Dla obiektów różnych typów czas życia jest zazwyczaj różny (przez to, że różne typy mają rózne przeznaczenia). Zwykle większy blok pamięci wiąże się więc z dłuższym czasem życia i dłuższym przeznaczeniem, a małe bloczki żyją krótko.


1. first fit:
   bierzemy pierwszy blok do którego możemy zmieścić dane, zaczynając od poczatku
   
2. next fit:
   bierzemy pierwszy blok do którego możemy zmieścić dane, ale zaczynając miejsca gdzie poprzednio skończyliśmy
   
3. best fit:
   bierzemy blok, do którego się zmieszczą danę, i będzie miał rozmiar najbliższy rozmiarowi danych  (z dostępnych bloków)

## Zadanie 8-4

:::danger
Autor: Aleksander Uniatowicz
:::

![](https://i.imgur.com/bCvuyj5.png)


## Zadanie 8-5

:::danger
Autor: Tomasz Woszczyński
:::

**Algortym kubełkowy** *(ang. segregated-fit)* polega na przechowywaniu list wolnych bloków w taki sposób, że każda lista przechowuje bloki o wyznaczonym rozmiarze (zwykle najmniejsze wartości mają dedykowane listy, a większe listy przechowujące rozmiary od $2^i + 1$ do $2^{i+1}$). Kiedy wykonywana jest alokacja, wybiera się blok z najmniejszej wystarczającej listy.

![](https://i.imgur.com/YTXvPPo.png)

Operacja alokacji pamięci poleceniem `malloc(n)` działa następująco: wybierany jest odpowiedni najmniejszy kubełek, w razie gdy ten kubełek zawiera wolny blok, to wolny blok jest usuwany z listy wolnych bloków i oznaczany jako zajęta, na koniec zwracany jest wskaźnik na ten blok. Gdy kubełek jest już cały zajęty, to należy szukać bloku w kolejnym kubełku. W przypadku, gdy wszystkie kubełki są zajęte, alokowana jest nowa strona przeznaczona dla bloków o żądanym rozmiarze. Wtedy dla wolnego bloku wykonywany jest podział, pamięć alokowana, a pozostałe miejsce jest umieszczane na liście wolnych bloków.

Operacja zwalniania pamięci poleceniem `free(ptr)` oznacza najpierw blok jako wolny, a w przypadku gdy sąsiadujący blok jest wolny, są one łączone. Następnie cały wolny blok jest przenoszony do listy wolnych bloków.

Jeśli chcemy zwolnić ostatni element z listy za pomocą `free`, musimy wziąć pod uwagę, że ostatni element zawiera wskaźnik na początek większego kubełka - należy więc przepiąć wskaźniki, jednak nie jest to problematyczne, gdyż do początku kolejnego kubełka i końca poprzedniego możemy się dostać w czasie stałym $O(1)$.

**Złączanie leniwe** *(ang. deferred coalescing)* polega na łączeniu bloków dopiero w momencie, gdy kolejny raz chcemy zaalokować pamięć i nie napotkaliśmy bloku o wystarczająco dużym rozmiarze. Gdybyśmy chcieli leniwie złączać bloki, moglibyśmy zmniejszyć czas wyszukiwania bloków przy małych alokacjach. Problemem wynikającym z tego podejścia jest zwiększenie fragmentacji:

* użycie pamięci przy gorliwym złączaniu:
![](https://i.imgur.com/nHI5wpm.png)
* użycie pamięci przy leniwym złączaniu:
![](https://i.imgur.com/kcf894Q.png)

Powyższe grafiki pochodzą z publikacji [Visualising Dynamic Memory Allocators](https://spiral.imperial.ac.uk/bitstream/10044/1/5766/1/GCspy.pdf).

## Zadanie 8-6

:::danger
Autor: Jakub Zając
:::

```c=
static arena_t *init_arena(arena_t *ar)
{
  /* TODO: Calculate nitems given ARENA\_SIZE, size of arena\_t and object_t. */
  size_t free_space = (ARENA_SIZE - sizeof(arena_t));
  size_t bitmap_size = bitstr_size(free_space / sizeof(object_t));
  size_t nitems = (free_space - bitmap_size) / sizeof(object_t);
  
  ar->nitems = nitems;
  ar->nfree = nitems;
 
  /* Determine items address that is aligned properly. */
  ar->items = arena_end(ar) - nitems * sizeof(object_t);
  
  return ar;
}

static void *alloc_block(arena_t *ar) {
  assert(ar->nfree > 0);
  int index;
  /* TODO: Calculate index of free block and mark it used, update nfree. */   
  bit_ffc(ar->bitmap, ar->nitems, &index);    
  
  assert(index != -1);
  
  bit_set(ar->bitmap, index);
  ar->nfree--;
  
  return ar->items + sizeof(object_t) * index; 
}

static void free_block(arena_t *ar, void *ptr)
{ 
  int index = (ptr - ar->items) / sizeof(object_t);
   /* TODO: Determine if ptr is correct and mark it free, update nfree. */ 
  assert(ar->nitems > index);
  assert(bit_test(ar->bitmap, index));  
  
  bit_clear(ar->bitmap, index);
  ar->nfree++;
}
```

- sturktura danych: 
    - bitmap `bitstr_t`
- alloc
    - opis działania:
        - znajdź pierwszą arenę z wolnymi blokami
        - znajdź w bitmapie ten wolny blok w arenie, zwróć jego indeks
        - oznacz blok o tym indeksie jako zaalokowany, bitmapie zmiejsz liczbę wolnych bloków w arenie
        - zwróć wskaźnik na blok
    - pesymistyczna złożoność:
        - O(n*m), gdzie n - liczba aren, m - liczba bitów w bitmapie `nitems`
- free
    - opis działania:
        - znajdź arenę w ktorej jest wskaźnik na blok
        - oblicz indeks w tej arenie zwalnanego bloku
        - oznacz blok o tym indeksie jako wolny, bitmapie zwiększ liczbę wolnych bloków w arenie
    - pesymistyczna złożoność:
        - O(n), gdzie n - liczba aren
- narzut pamięciowy metadanych:
    - `nitems+sizeof(AREA_EXTRA)-sizeof(bitstr_t)`
- maksymalny rozmiar nieużytków:
    - przez fakt że rozmiary bloków są stałe, zawsze wykorzystamy ponownie konkretne bloki
    - jedak nawet jak zwolnimy wszytkie bloki z areny, ona sama nie zostanie zwolniona, co może być nieuźytkiem w ramach całego systemu
- fragmetacja: 
    - zewnętrzna:
        - nie występuje bo rozmiar bloków jest stały więc zawsze będziemy mogli te bloki wykorzystać
    - wewnętrzna:
        - nie występuje ponieważ nie wyrównujemy anie nie umieszczamy metadanych w bloku


## Zadanie 8-7

:::danger
Autor: Paweł Zmarzły
:::

```c=
static arena_t *init_arena(arena_t *ar)
{
  /* TODO: Calculate nitems given ARENA_SIZE, size of arena_t and object_t. */
  size_t nitems = (ARENA_SIZE - sizeof(arena_t)) / sizeof(object_t);
  while (ARENA_SIZE - nitems * sizeof(object_t) < nitems + nitems / 8)
    nitems--;

  ar->nitems = nitems;
  ar->nfree = nitems;
  /* Determine items address that is aligned properly. */
  ar->items = arena_end(ar) - nitems * sizeof(object_t);
  return ar;
}
static void ffc(bitstr_t *bitmap, int nitems, int *ret)
{
  // printf("enter %d\n", nitems);
  int full_words = nitems / 8 / 8;
  for (int i = 0; i < full_words; i++)
  {
    // Szukam pierwszej jedynki w negacji fragmentu bitmap.
    long to_scan;
    for (int j = 0; j < 8; j++)
      ((unsigned char *)&to_scan)[j] = bitmap[8 * i + j];
    to_scan = ~to_scan;
    // printf("scan %lx\n", to_scan);

    // https://www.felixcloutier.com/x86/bsf
    // https://stackoverflow.com/questions/57633304
    // https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
    bool zero_flag;
    long one_idx;
    __asm__(
        "bsf %[to_scan], %[one_idx]"
        // Wyjście. = overwrites, r register, @cc constraint, z zero flag
        : [ one_idx ] "=r"(one_idx), "=@ccz"(zero_flag)
        // Wejście. m memory or r register
        : [ to_scan ] "mr"(to_scan));

    if (zero_flag)
      continue; // Same jedynki we fragmencie.

    // printf("found\n");
    *ret = i * 8 * 8 + one_idx;
    return;
  }

  // printf("fallback\n");
  bit_ffc(bitmap + full_words * 8, nitems - full_words * 8 * 8, ret);
  if (*ret != -1)
    *ret += full_words * 8 * 8;
}

#define L1BITMAP(ar) (ar->bitmap)
#define L1LENGTH(ar) (ar->nitems / 8 + 1)
#define L2BITMAP(ar) (ar->bitmap + L1LENGTH(ar))
#define L2LENGTH(ar) 8
static void *alloc_block(arena_t *ar)
{
  assert(ar->nfree > 0);
  /* TODO: Calculate index of free block and mark it used, update nfree. */
  int l1index;
  ffc(L1BITMAP(ar), L1LENGTH(ar), &l1index);
  assert(l1index != -1);
  // fprintf(stderr, "Found L1=%d\n", l1index);

  int l2index;
  ffc(L2BITMAP(ar) + l1index, L2LENGTH(ar), &l2index);
  assert(l2index != -1);
  // fprintf(stderr, "Found L2=%d\n", l1index * 8 + l2index);

  bit_set(L2BITMAP(ar) + l1index, l2index);
  ar->nfree--;

  int full_test;
  ffc(L2BITMAP(ar) + l1index, L2LENGTH(ar), &full_test);
  if (full_test == -1)
  {
    // fprintf(stderr, "Full L1=%d\n", l1index);
    bit_set(L1BITMAP(ar), l1index);
  }

  return ar->items + sizeof(object_t) * (l1index * 8 + l2index);
}
static void free_block(arena_t *ar, void *ptr)
{
  int index = (ptr - ar->items) / sizeof(object_t);
  /* TODO: Determine if ptr is correct and mark it free, update nfree. */
  assert(ar->items + sizeof(object_t) * index == ptr);
  assert(index >= 0);
  assert(index < ar->nitems);
  assert(bit_test(L2BITMAP(ar), index));
  // fprintf(stderr, "Freed L2=%d\n", index);
  bit_clear(L2BITMAP(ar), index);
  // fprintf(stderr, "Freed L1=%d\n", index / 8);
  bit_clear(L1BITMAP(ar), index / 8);
  ar->nfree++;
}
static void objmemcheck(void)
{
  arena_t *ar;
  STAILQ_FOREACH(ar, &arenas, arenalink)
  {
    /* Check if nfree matches number of cleared bits in bitmap. */
    size_t nused = 0;
    for (int i = 0; i < ar->nitems; i++)
      // TODO: Tutaj zmiana!
      nused += bit_test(L2BITMAP(ar), i) ? 1 : 0;
    assert(nused == ar->nitems - ar->nfree);
  }
}
```

BSF przyspiesza.
Dwupoziomowa bitmapa spowalnia.

## Zadanie 8-8

:::danger
Autor: Adam Turowski
:::

**niejawna lista** (*implicit list*) - Metoda trzymania informacji o wolnych blokach pamięci zawierająca wskaźniki między kolejnymi obszarami pamięci![](https://i.imgur.com/lDucbco.png)

```c=
#include "csapp.h"
#include "arena.h"

#define MAX_LENGTH 126
#define MAX_BLKSZ (MAX_LENGTH + 1)

#define DEBUG_LEVEL 2

static arenalist_t arenas = STAILQ_HEAD_INITIALIZER(arenas);
static arena_t *cur_arena = NULL;
static unsigned cur_offset;

static void init_chunk(void *ar) {
  uint8_t *data = ar;
  unsigned offset = sizeof(arena_t);

  while (offset + MAX_BLKSZ < ARENA_SIZE) {
    data[offset] = -MAX_BLKSZ;
    offset += MAX_BLKSZ;
  }

  data[offset] = -(ARENA_SIZE - 1 - offset);
  data[ARENA_SIZE - 1] = 0;
}

#define BLOCK_HEADER(data) (data[cur_offset])
#define END_OF_CHUNK(data) (BLOCK_HEADER(data) == 0)
#define BLOCK_USED(data) (BLOCK_HEADER(data) > 0)
#define BLOCK_SIZE(data) (abs(BLOCK_HEADER(data)))

#define NEXT_BLOCK_HEADER(data) (data[cur_offset + BLOCK_SIZE(data)])
#define NEXT_BLOCK_FREE(data) (NEXT_BLOCK_HEADER(data) < 0)
#define NEXT_BLOCK_SIZE(data) (abs(NEXT_BLOCK_HEADER(data)))

#define MOVE_NEXT(data) cur_offset += BLOCK_SIZE(data)
#define CURRENT_PTR(data) (data + cur_offset + 1)

static void *alloc_block(int8_t *data, uint8_t len) {
  void *result = NULL;

  while (!END_OF_CHUNK(data)) {
    if (BLOCK_USED(data)) {
      /* TODO: occupied block */
      MOVE_NEXT(data);
    } else if (BLOCK_SIZE(data) == len) {
      /* TODO: free block of exact size */
      BLOCK_HEADER(data) *= -1;
      result = CURRENT_PTR(data);
      break;
    } else if (BLOCK_SIZE(data) > len) {
      /* TODO: free block is too large */
      int free_len = BLOCK_SIZE(data) - len;
      BLOCK_HEADER(data) = len;
      NEXT_BLOCK_HEADER(data) = -free_len;
      result = CURRENT_PTR(data);
      break;
    } else if (!NEXT_BLOCK_FREE(data)) {
      /* TODO: next block is occupied or does not exists */
      MOVE_NEXT(data);
    } else if (NEXT_BLOCK_SIZE(data) <= len - BLOCK_SIZE(data)) {
      /* TODO: merge two free blocks, but do not allocate */
      BLOCK_HEADER(data) = BLOCK_HEADER(data) + NEXT_BLOCK_HEADER(data);
    } else {
      /* TODO: merge two free blocks and allocate with split */
      int free_len = BLOCK_SIZE(data) + NEXT_BLOCK_SIZE(data) - len;
      BLOCK_HEADER(data) = len;
      NEXT_BLOCK_HEADER(data) = -free_len;
      result = CURRENT_PTR(data);
      break;
    }
  }
  return result;
}

static char *stralloc(size_t len) {
  assert(len <= MAX_LENGTH);

  if (len == 0)
    return NULL;

  if (cur_arena == NULL) {
    /* there are no arenas yet */
    init_chunk(alloc_first_arena(&arenas));
    cur_arena = STAILQ_FIRST(&arenas);
    cur_offset = sizeof(arena_t);
  }

  arena_t *ar = cur_arena;
  char *ptr;

  while (!(ptr = alloc_block((int8_t *)ar, len + 1))) {
    /* no space left on the current arena, move to the next one */
    ar = STAILQ_NEXT(ar, arenalink);
    cur_offset = sizeof(arena_t);

    /* that was the last arena, move to the first one */
    if (ar == NULL)
      ar = STAILQ_FIRST(&arenas);

    if (ar == cur_arena) { /* we've checked all arenas on the list. */
      init_chunk(alloc_after_arena(&arenas, ar));
      ar = STAILQ_NEXT(ar, arenalink);
    }
  }

  cur_arena = ar;
  return ptr;
}

static void strfree(char *str) {
  if (str == NULL)
    return;
  int8_t *sstr = (int8_t *)str;
#if DEBUG_LEVEL > 0
  assert(sstr[-1] > 0);
  arena_t *ar = find_ptr_arena(&arenas, str);
  assert(ar != NULL);
#if DEBUG_LEVEL > 1
  int8_t *ptr = (int8_t *)ar + sizeof(arena_t);
  while (ptr < sstr - 1) {
    assert(*ptr != 0);
    ptr += (*ptr > 0 ? *ptr : -*ptr);
  }
  assert(ptr == sstr - 1);
#endif
#endif
  /* TODO: mark block as free */
  int8_t* header = sstr - 1;
  *header *= -1;
}

static void strmemcheck(void) {
  arena_t *ar;
  STAILQ_FOREACH(ar, &arenas, arenalink) {
    const int8_t *data = (const int8_t *)ar;
    unsigned offset = sizeof(arena_t);
    while (offset != ARENA_SIZE - 1) {
      assert(offset < ARENA_SIZE);
      assert(data[offset] != 0);
      offset += abs(data[offset]);
    }
    assert(data[offset] == 0);
  }
}

/* The test */

#define MAX_PTRS 100
#define MAX_LEN 100
#define CYCLES 100

static void *alloc_fn(int *lenp) {
  *lenp = rand() % (MAX_LEN + 1);
  return stralloc(*lenp);
}

#define free_fn(ptr) strfree(ptr)
#define memchk_fn() strmemcheck()

#include "test.h"

```

- struktura danych: niejawna lista
- jak przebiegają operacje alloc i free:
    - alloc: Iterujemy się po wszystkich arenach i wszystkich blokach w nich, az uda nam się zaalokować dane. O(n)
    - free: Podajemy do strfree wskaźnik na miejsce w pamięci w którym zaczynają się dane które chcemy zwolnić, po czym zmieniamy status bloku z zajętego na wolny. O(1)
- narzut metadanych: jeden bajt na blok
- maksymalny rozmiar nieużytków: 1 bajt na blok dla kazdego z zaalokowanych bloków 
(1/3 listy dla samych bloków o długości 2)
- fragmentacje: fragmentacja wewnętrzna nie zachodzi, fragmentacja zewnętrzna zachodzi ale nie jest istotnym problemem.