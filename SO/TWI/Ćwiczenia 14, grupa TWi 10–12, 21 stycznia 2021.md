# Ćwiczenia 14, grupa TWi 10–12, 21 stycznia 2021

###### tags: `so20` `ćwiczenia` `twi`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                | 13-1  | 13-2 | 13-3  | 13-4 | 13-5 | 13-6 |
|:---------------------- |:-----:|:----:|:-----:|:----:|:----:|:----:|
| Kamil Banaś            |       |      |       |      |      |      |
| Marcin Dąbrowski       |       |  X   |   X   |  X   |      |  X   |
| Kamil Galik            |   X   |      |   X   |  X   |      |      |
| Bartosz Głowacki       |   X   |  X   |   X   |  X   |      |  X   |
| Jakub Kaczmarek        |       |      |       |      |      |      |
| Karol Machoś           |       |  X   |   X   |  X   |      |  X   |
| Małgorzata Maciejewska |   X   |  X   |   X   |  X   |      |  X   |
| Antoni Pokusiński      | ==X== |  X   |   X   |  X   |      |  X   |
| Mateusz Reis           |   X   |      |   X   |  X   |  X   |  X   |
| Adam Turowski          |       |      |   X   |  X   |      |  X   |
| Aleksander Uniatowicz  |   X   |  X   | ==X== |  X   |  X   |  X   |
| Jan Wańkowicz          |   X   |  X   |   X   |  X   |  X   |  X   |
| Krzysztof Wiśniewski   |       |      |   X   |  X   |      |  X   |
| Tomasz Woszczyński     |       |      |       |      |      |      |
| Jakub Zając            |   X   |      |   X   |  X   |      |  X   |
| Paweł Zmarzły          |   X   |  X   |   X   |  X   |  X   |  X   |
| Adam Zyzik             |   X   |      |       |      |      |      |
:::

## Zadanie 13-1

:::danger
Autor: Antoni Pokusiński
:::
```python=
def producer():
    while True:
            item = produce()
        if queue.full():
            sleep()
        queue.push(item)
        if not queue.empty():
            wakeup(consumer)
          
          
def consumer():
    while True:
        if queue.empty():
            sleep()
        item = queue.pop()
        if not queue.full():
            wakeup(producer)
        consume(item)
```

### Zakleszczenie
* załóżmy, kolejka że jest pełna, w ```producer()``` sprawdzamy ```if queue.full()``` więc wejdziemy do ```sleep()```
* przed wykonaniem ```sleep()```: ```consumer()``` opróżni bufor wieloma iteracjami pętli *while* i po skonsuwomaniu ostatniego item'u zacznie kolejną iterację pętli *while*. 
* ponieważ bufor jest pusty, ```consumer()``` wykona ```sleep()```
* ```sleep()``` w wątku producenta również zostanie wykonany i mamy zakleszczenie

### Push do pełnej kolejki
* załóżmy, że kolejka jest pełna. W ```consumer()``` wykonujemy ```item = queue.pop()``` i od razu sprawdzamy warunek ```if not queue.full()```. Jednak jeszcze nie wykonujemy ```wakeup(producer)```
* w ```producer()``` wykonujemy ```queue.push(item)```. Teraz kolejka jest pełna. 
* wykonujemy kolejne instrukcje i przechodzimy do kolejnej iteracji. W niej mamy ```if queue.full()```, więc wykonujemy ```sleep()```. 
* zaraz po wykonaniu ```sleep()``` w ```producer()``` wykonujemy "zawieszone" ```wakeup(producer)```.
* wykonamy teraz ```queue.push(item)```, co spowoduje przepełnienie bufora.

### Pop z pustej kolejki
Analogicznie do poprzedniego przykładu.
* dodajemy 1 item do pustej kolejki, wchodzimy do if'a, ale nie wykonujemy od razu ```wakeup(consumer)```
* ściągamy item, wykonujemy kolejne instrukcje, przechodzimy do następnej iteracji
* kolejka jest pusta, więc wykonujemy ```sleep()```, ale w tym momencie "odwiesza się" ```wakeup(consumer)```, wobec czego po chwili wykonamy ```item = queue.pop()``` na pustej kolejce
## Zadanie 13-2

:::danger
Autor: Karol Machoś
:::

![](https://i.imgur.com/qFEzi4N.png)
```python=
def acquire():
    mutex.wait()
    if must_wait:
        waiting +=1
        mutex.post()
        block.wait()
        mutex.wait()
        waiting -=1
    active +=1
    must_wait = (active == 3)
    mutex.post()
    
def release():
    mutex.wait()
    active -= 1
    if active == 0:
        n = min(waiting, 3)
        while n > 0:
            block.post()
            n-=1
        must_wait = False
    mutex.post()
```

## Przeplot, który doprowadzi do błędu:

|    | T1     | T2     | T3     | T4     | T5     | T6     | T7     | T8     |
| -- | --     | --     | --     | --     | --     | --     | --     | --     |
| P1 | aquire |        |        |        | release|        |        |        |
| P2 |        | aquire |        |        |        |release |        |        |
| P3 |        |        | aquire |        |        |        |release |        |
| P4 |        |        |        |`aquire`|        |        |        |        |
| P5 |        |        |        |        |        |        |        | aquire |

`aquire` - oznacza, że wątek zasnął podczas wykonywania operacji **aquire** (dokładnie: zatrzymał się na linijce 6).

W momencie gdy wątek P3 ostatecznie zwróci zasób i znowu inne wątki będą mogły uzyskiwać do niego dostęp, złośliwy scheduler może przejść od razu do wykonywania operacji aquire w P5 co naruszy opisaną w programie kolejność FIFO (wątek P4 już wcześniej oczekiwał na zasób)


## Zadanie 13-3

:::danger
Autor: Aleksander Uniatowicz
:::

```c=
#include "csapp.h"

static __unused void outc(char c)
{
  Write(STDOUT_FILENO, &c, 1);
}

static void randsleep(void)
{
  usleep(rand() % 5000 + 5000);
}

#define N 10

#define SOLUTION

static pthread_t td[N];
static sem_t forks[N];
/* TODO: If you need extra shared state, define it here. */

static sem_t sem;

void *philosopher(void *id)
{
  int right = (intptr_t)id;
  int left = right == 0 ? N - 1 : right - 1;

  for (;;)
  {
    /* Think */
    randsleep();
    printf("Think: %ld\n", (long)id);

    /* TODO: Take forks (without deadlock & starvation) */
    Sem_wait(&sem);

    Sem_wait(&forks[right]);
    // randsleep();
    Sem_wait(&forks[left]);

    /* Eat */
    randsleep();
    printf("Eat: %ld\n", (long)id);

    /* TODO: Put forks (without deadlock & starvation) */
    Sem_post(&forks[left]);
    Sem_post(&forks[right]);

    printf("End: %ld\n", (long)id);

    Sem_post(&sem);
  }

  return NULL;
}

int main(void)
{
  /* TODO: If you need extra shared state, initialize it here. */
  Sem_init(&sem, 0, N - 1);

  for (int i = 0; i < N; i++)
    Sem_init(&forks[i], 0, 1);

  for (int i = 0; i < N; i++)
    Pthread_create(&td[i], NULL, philosopher, (void *)(intptr_t)i);

  for (int i = 0; i < N; i++)
    Pthread_join(td[i], NULL);

  return EXIT_SUCCESS;
}
```


## Zadanie 13-4

:::danger
Autor: Adam Turowski
:::

```c=
#include "csapp.h"

static __unused void outc(char c) {
  Write(STDOUT_FILENO, &c, 1);
}

#define N 100
#define M 100

static struct {
  /* TODO: Put semaphores and shared variables here. */
  int servings; //Ilosc porcji w garze
  sem_t mutex; //Semafor ograniczający mozliwość jedzenia przez dzikusów
  sem_t empty; //Semafor oznaczający ze gar jest pusty
  sem_t full; //Semafor oznaczający ze gar jest pełny
} *shared = NULL;


static void savage(void) {
  for (;;) {
    /* TODO Take a meal or wait for it to be prepared. */
    Sem_wait(&(shared->mutex)); //Stan w kolejce do gara
    if(!shared->servings) // Jesli nie ma porcji
    {
      Sem_post(&(shared->empty)); // Poinformuj ze gar jest pusty
      Sem_wait(&(shared->full)); // I poczekaj az gar bedzie pelny
    }
    shared->servings--; // Zjedz porcje
    outc('W');
    Sem_post(&(shared->mutex)); //Odejdz od gara
    /* Sleep and digest. */
    usleep(rand() % 1000 + 1000);
  }

  exit(EXIT_SUCCESS);
}

static void cook(void) {
  for (;;) {
    /* TODO Cook is asleep as long as there are meals.
     * If woken up they cook exactly M meals. */
    Sem_wait(&(shared->empty)); //Poczekaj az gar bedzie pusty
    shared->servings = M; //Napelnij gar
    Sem_post(&(shared->full)); //Daj informacje ze gar jest pelny
  }
}

/* Do not bother cleaning up after this process. Let's assume that controlling
 * terminal sends SIGINT to the process group on CTRL+C. */
int main(void) {
  shared = Mmap(NULL, getpagesize(), PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED,
                -1, 0);

  /* TODO: Initialize semaphores and other shared state. */
  shared->servings = 0; // Gar zaczyna pusty
  Sem_init(&(shared->mutex), 1, 1);
  Sem_init(&(shared->empty), 1, 1);
  Sem_init(&(shared->full), 1, 0);

  for (int i = 0; i < N; i++)
    if (Fork() == 0)
      savage();

  cook();

  return EXIT_SUCCESS;
}

```

## Zadanie 13-5
:::danger
Autor: Jan Wańkowicz
:::

```c=
#include "csapp.h"

static __unused void outc(char c) {
  Write(STDOUT_FILENO, &c, 1);
}

typedef struct {
  /* TODO: Use this structure to store barrier internal state. */
  volatile int arriving,leaving;
  volatile int n;
  volatile int flag;
  sem_t sem_flag;
  sem_t sem_leaving;
  sem_t mutex;
} barrier_t;

static barrier_t *barrier_init(int n) {
  if (n < 1)
    app_error("barrier_init requires n > 0");

  barrier_t *b = Mmap(NULL, sizeof(barrier_t), PROT_READ|PROT_WRITE,
                      MAP_ANON|MAP_SHARED, -1, 0);

  /* TODO: Initialize barrier internal state. */
  b->arriving=0,b->leaving=n,b->n=n;
  Sem_init(&b->sem_flag, 1, 0);
  Sem_init(&b->sem_leaving, 1, 1);
  Sem_init(&b->mutex, 1, 1);
  return b;
}

static void barrier_wait(barrier_t *b) {
  /* TODO: Provide wait procedure implementation here. */
  Sem_wait(&b->mutex);
  if(b->arriving==0)
  {
    if(b->leaving!=b->n)
    {
        Sem_post(&b->mutex);
        Sem_wait(&b->sem_leaving);
        Sem_wait(&b->mutex);
    }
  }
  b->arriving++;
  int a=b->arriving;
  Sem_post(&b->mutex);
  if(a==b->n)
  {
    Sem_wait(&b->mutex);
    b->arriving=0;
    b->leaving=1;
    for(int i=0;i<b->n-1;i++)
      Sem_post(&b->sem_flag);
    Sem_post(&b->mutex);
  }
  else
  {
    Sem_wait(&b->sem_flag);
    Sem_wait(&b->mutex);
    b->leaving++;
    if(b->leaving == b->n){
        Sem_post(&b->sem_leaving);
    }
    Sem_post(&b->mutex);
  }
  
}

static void barrier_destroy(barrier_t *b) {
  /* TODO: Provide destroy procedure implementation here. */
  Munmap(b,sizeof(barrier_t));
}

#define K 3
#define N 50
#define P 100

static noreturn void horse(barrier_t *b) {
  int n = rand() % K + K;

  outc('+');

  for (int i = 0; i < n; i++) {
    barrier_wait(b);
    usleep(rand() % 2000 + 1000);
  }

  outc('-');

  exit(EXIT_SUCCESS);
}

/* Do not bother cleaning up after this process. Let's assume that controlling
 * terminal sends SIGINT to the process group on CTRL+C. */
int main(void) {
  barrier_t *b = barrier_init(N);

  int horses = 0;

  for (;;) {
    do {
      if (Fork() == 0) {
        srand(getpid());
        horse(b);
      }
      horses++;
    } while (horses < P);

    Wait(NULL);
    horses--;
  }

  barrier_destroy(b);

  return EXIT_SUCCESS;
}
```

> [name=Paweł] moja wersja:
> ```c=
> static barrier_t *barrier_init(int n)
> {
>   if (n < 1)
>     app_error("barrier_init requires n > 0");
> 
>   barrier_t *b = Mmap(NULL, sizeof(barrier_t), PROT_READ | PROT_WRITE,
>                       MAP_ANON | MAP_SHARED, -1, 0);
> 
>   /* TODO: Initialize barrier internal state. */
>   Sem_init(&b->lock, 1, 1);
>   Sem_init(&b->sleep, 1, 0);
>   b->n = n;
>   b->waiting = 0;
>   return b;
> }
> 
> static void barrier_wait(barrier_t *b)
> {
>   /* TODO: Provide wait procedure implementation here. */
>   Sem_wait(&b->lock);
>   b->waiting++;
>   if (b->waiting == b->n)
>   {
>     for (int i = 0; i < b->n; i++)
>       Sem_post(&b->sleep);
>     b->waiting = 0;
>   }
>   Sem_post(&b->lock);
>   Sem_wait(&b->sleep);
> }
> 
> static void barrier_destroy(barrier_t *b)
> {
>   /* TODO: Provide destroy procedure implementation here. */
>   Sem_wait(&b->lock);
>   Sem_destroy(&b->lock);
>   Sem_destroy(&b->sleep);
>   Munmap(b, sizeof(barrier_t));
> }
> ```

## Zadanie 13-6

:::danger
Autor: Paweł Zmarzły
:::

Wersja, gdzie palacze są budzeni częściej niż potrzeba:

```c=
/* TODO: If you need any extra global variables, then define them here. */
static sem_t lock;

static bool trywait(sem_t *sem)
{
  // w przeciwieństwie do sem_trywait, nasz trywait działa tylko
  // pod warunkiem, że jest jedynym źródłem operacji wait
  Sem_wait(&lock);
  int v;
  Sem_getvalue(sem, &v);
  if (v > 0)
    Sem_wait(sem);
  Sem_post(&lock);
  return v > 0;
}

static void *smokerWithMatches(void *arg)
{
  seed = pthread_self();

  while (true)
  {
    /* TODO: wait for paper and tobacco */
    if (!trywait(&paper))
      continue;
    if (!trywait(&tobacco))
    {
      Sem_post(&paper);
      continue;
    }
    make_and_smoke('M');
  }

  return NULL;
}

int main(void)
{
  // ...
  
  /* TODO: Initialize your global variables here. */
  Sem_init(&lock, 0, 1);
  
  // ...
}
```

Wersja z 4 ekstra wątkami:

```c=
/* TODO: If you need any extra global variables, then define them here. */
static sem_t lock;
static sem_t wakeTobacco;
static sem_t wakeMatches;
static sem_t wakePaper;
static sem_t wakeArbiter;
bool tobaccoOnTable = false;
bool matchesOnTable = false;
bool paperOnTable = false;

/* TODO: If you need extra threads, then define their main procedures here. */
static void *matchesObserver(void *arg)
{
  while (true)
  {
    Sem_wait(&matches);
    Sem_wait(&lock);
    matchesOnTable = true;
    Sem_post(&lock);
    Sem_post(&wakeArbiter);
  }
  return NULL;
}

static void *paperObserver(void *arg)
{
  while (true)
  {
    Sem_wait(&paper);
    Sem_wait(&lock);
    paperOnTable = true;
    Sem_post(&lock);
    Sem_post(&wakeArbiter);
  }
  return NULL;
}

static void *tobaccoObserver(void *arg)
{
  while (true)
  {
    Sem_wait(&tobacco);
    Sem_wait(&lock);
    tobaccoOnTable = true;
    Sem_post(&lock);
    Sem_post(&wakeArbiter);
  }
  return NULL;
}

static void *arbiter(void *arg)
{
  while (true)
  {
    Sem_wait(&wakeArbiter);
    Sem_wait(&lock);

    bool reset = true;
    if (matchesOnTable && paperOnTable)
      Sem_post(&wakeTobacco);
    else if (matchesOnTable && tobaccoOnTable)
      Sem_post(&wakePaper);
    else if (paperOnTable && tobaccoOnTable)
      Sem_post(&wakeMatches);
    else
      reset = false;

    if (reset)
    {
      matchesOnTable = false;
      tobaccoOnTable = false;
      paperOnTable = false;
    }
    Sem_post(&lock);
  }
  return NULL;
}

static void *smokerWithMatches(void *arg)
{
  seed = pthread_self();

  while (true)
  {
    /* TODO: wait for paper and tobacco */
    Sem_wait(&wakeMatches);
    make_and_smoke('M');
  }

  return NULL;
}

int main(void)
{
  Sem_init(&tobacco, 0, 0);
  Sem_init(&matches, 0, 0);
  Sem_init(&paper, 0, 0);
  Sem_init(&doneSmoking, 0, 1);

  /* TODO: Initialize your global variables here. */
  Sem_init(&lock, 0, 1);
  Sem_init(&wakeTobacco, 0, 0);
  Sem_init(&wakeMatches, 0, 0);
  Sem_init(&wakePaper, 0, 0);
  Sem_init(&wakeArbiter, 0, 0);

  pthread_t agentThread;
  Pthread_create(&agentThread, NULL, agent, NULL);

  pthread_t smokerPaperThread, smokerMatchesThread, smokerTobaccoThread;
  Pthread_create(&smokerPaperThread, NULL, smokerWithPaper, NULL);
  Pthread_create(&smokerMatchesThread, NULL, smokerWithMatches, NULL);
  Pthread_create(&smokerTobaccoThread, NULL, smokerWithTobacco, NULL);

  pthread_t paperObserverThread, matchesObserverThread, tobaccoObserverThread;
  Pthread_create(&paperObserverThread, NULL, paperObserver, NULL);
  Pthread_create(&matchesObserverThread, NULL, matchesObserver, NULL);
  Pthread_create(&tobaccoObserverThread, NULL, tobaccoObserver, NULL);

  pthread_t arbiterThread;
  Pthread_create(&arbiterThread, NULL, arbiter, NULL);

  Pthread_join(agentThread, NULL);
  Pthread_join(smokerPaperThread, NULL);
  Pthread_join(smokerMatchesThread, NULL);
  Pthread_join(smokerTobaccoThread, NULL);

  return 0;
}  
```