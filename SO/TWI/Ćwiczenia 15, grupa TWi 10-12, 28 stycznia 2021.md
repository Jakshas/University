# Ćwiczenia 15, grupa TWi 10-12, 28 stycznia 2021

###### tags: `so20` `twi` `ćwiczenia`

## Deklaracje

Gotowość rozwiązania zadania należy wyrazić poprzez postawienie znaku X w odpowiedniej kolumnie. Aby wskazać szczególną chęć zreferowania danego zadania (co najwyżej jednego) należy oznaczyć je znakiem ==X== na żółtym tle.

**UWAGA: Tabelkę wolno edytować tylko wtedy, gdy jest na zielonym tle!**

:::danger
| Zadanie                | 14-1 | 14-2  | 14-4  | 14-5 | 14-6 |
|:---------------------- |:----:|:-----:|:-----:|:----:|:----:|
| Kamil Banaś            |      |       |       |      |      |
| Marcin Dąbrowski       |      |       |       |      |      |
| Kamil Galik            |      |       |       |      |      |
| Bartosz Głowacki       |  X   |       |       |   X  |      |
| Jakub Kaczmarek        |      |       |       |      |      |
| Karol Machoś           |      |       |       |      |      |
| Małgorzata Maciejewska |  X   |       |   X   |      |      |
| Antoni Pokusiński      |  X   |       |       |      |      |
| Mateusz Reis           |      |       |       |      |      |
| Adam Turowski          |      |       |       |      |      |
| Aleksander Uniatowicz  |  X   |   X   |  X?   |  X?  |      |
| Jan Wańkowicz          |      |       |       |      |      |
| Krzysztof Wiśniewski   |      |       |       |      |      |
| Tomasz Woszczyński     |      |       |       |      |      |
| Jakub Zając            |  X   | ==X== |       |      |      |
| Paweł Zmarzły          |  X   |   X   |   X   |  X   |  X   |
| Adam Zyzik             |  X   |   X   | ==X== |  X   |      |
:::

## Zadanie 14-1

:::danger
Autor: Aleksander Uniatowicz
:::

```c=
typedef struct Sem {
    pthread_mutex_t mutex;
    pthread_cond_t waiters;
    int value;
} Sem_t;


void init(Sem_t *s, int value){
    s->value = value;
    pthread_cond_init(&s->waiters, NULL);
    pthread_mutex_init(&s->mutex, NULL);
}

void wait(Sem_t *s){
    pthread_mutex_lock(&s->mutex);
    while(s->value <= 0){
        pthread_cond_wait(&s->waiters, &s->mutex);
    }
    s->value--;
    pthread_mutex_unlock(&s->mutex);
}

void post(Sem_t *s){
    pthread_mutex_lock(&s->mutex);
    s->value++;
    pthread_cond_signal(&s->waiters);
    pthread_mutex_unlock(&s->mutex);
}
```

## Zadanie 14-2

:::warning
Autor: Jakub Zając 
:::

![](https://i.imgur.com/dVJqvtv.png)
```c=
typedef struct rwlock_t {
    pthread_t* owner;
    int readers;
    pthread_mutex_t critsec;
    pthread_cond_t no_readers;
    pthread_cond_t no_writer;
    pthread_mutex_t writer;
} rwlock_t; 

void init(rwlock_t* lock) {
    lock->owner = NULL; // writer
    lock->readers = 0;
    pthread_mutex_init(&lock->critsec, NULL);
    pthread_cond_init(&lock->no_readers, NULL);
    pthread_cond_init(&lock->no_writer, NULL); 
    pthread_mutex_init(&lock->writer, NULL);
}

void rd_lock(rwlock_t* lock) {
    pthread_mutex_lock(&lock->critsec); // sekcja krytyczna
    while(lock->owner != NULL) {
        pthread_cond_wait(&lock->no_writer, &lock->critsec);
    }
    lock->readers++;
    pthread_mutex_unlock(&lock->critsec); // sekcja krytyczna
}

void wr_lock(rwlock_t* lock) {
    pthread_mutex_lock(&lock->writer); // tylko jeden writer
   
    pthread_mutex_lock(&lock->critsec); // sekcja krytyczna
    
    while(lock->readers > 0) {
        pthread_cond_wait(&lock->no_readers, &lock->critsec);
    }
    lock->owner = phtread_self();
    
    pthread_mutex_unlock(&lock->critsec); // sekcja krytyczna
}

void unlock(rwlock_t* lock) {
    bool is_writer = (bool)pthread_equal(lock->owner,pthread_self());
    pthread_mutex_lock(&lock->critsec); // sekcja krytyczna
    if(is_writer) {
        lock->owner = NULL;
        pthread_cond_broadcast(&lock->no_writer, &lock->critsec);
        pthread_mutex_unlock(&lock->wirter);
    } else {
        lock->readers--;
        if(lock->readers == 0){
            thread_cond_signal(&lock->no_readers, &lock->critsec);
        }
    }
    pthread_mutex_unlock(&lock->critsec); // sekcja krytyczna
}
```

## Zadanie 14-4

:::danger
Autor: Adam Zyzik
:::

```c
while (true) {
    /* Wait till you get hungry. */
    rand_usleep(5000, 10000);

    /* Queue for delicious ramen. */
    outc('.');
    ramen_wait(r);

    /* It's so yummy! */
    outc('@');
    rand_usleep(1000, 2000);

    /* Time to leave, but don't be rude or else... */
    ramen_finish(r);
    outc('_');
    // tutaj nie potrafimy zapewnić, że _ zostanie wypisane przed
    // zajęciem miejsca przez kolejną osobę (@) bez modyfikowania kodu
    
    // z tego powodu poniższe linijki dodałem tutaj, a nie na końcu ramen_finish()
    pthread_mutex_lock(&r->mutex);
    pthread_cond_broadcast(&r->cond_var);
    pthread_mutex_unlock(&r->mutex);
}
```

```c
typedef struct ramen {
  /* TODO: Put internal state & mutexes & condvars here. */
  int fre;    // liczba wolnych miejsc
  int skon;   // liczba osób, które skończyły jeść
  int left;   // liczba osób, które wyszła z restauracji
  unsigned seats;
  pthread_mutex_t mutex;
  pthread_cond_t cond_var;
} ramen_t;

static void ramen_init(ramen_t *r, unsigned seats) {
  /* TODO: Initialize internal state of ramen restaurant. */
  pthread_mutex_init(&r->mutex, NULL);
  pthread_cond_init(&r->cond_var, NULL);
  r->seats = seats;
  r->fre = seats;
  r->left = 0;
  r->skon = 0;
}

static void ramen_destroy(ramen_t *r) {
  /* TODO: Destroy all synchronization primitives. */
  pthread_cond_destroy(&r->cond_var);
  pthread_mutex_destroy(&r->mutex);
}

static void ramen_wait(ramen_t *r) {
  /* TODO: Enter the restaurant unless it's full or people haven't left yet. */
  pthread_mutex_lock(&r->mutex);
  while (true) {
    if (r->fre && !r->left) {
      r->fre--;
      break;
    }
    pthread_cond_wait(&r->cond_var, &r->mutex);
  }
  pthread_mutex_unlock(&r->mutex);
}

static void ramen_finish(ramen_t *r) {
  /* TODO: Finished eating, so wait for all other to finish before leaving. */
  pthread_mutex_lock(&r->mutex);
  r->skon++;
  while (r->skon == r->seats - r->fre) {
    pthread_cond_wait(&r->cond_var, &r->mutex);
  }
  r->left++;
  if (r->left == (r->seats - r->fre)) {
    r->left = 0;
    r->skon = 0;
    r->fre = r->seats;
  }
  // pthread_cond_broadcast(&r->cond_var);
  pthread_mutex_unlock(&r->mutex);
}
```

>[name=Paweł]
>```c=
>typedef struct ramen
>{
>  /* TODO: Put internal state & mutexes & condvars here. */
>  int seats;
>  int at_table;
>  int finished;
>  bool quitting;
>  pthread_mutex_t mutex;
>  pthread_cond_t seats_changed;
>} ramen_t;
>
>static void ramen_init(ramen_t *r, unsigned seats)
>{
>  /* TODO: Initialize internal state of ramen restaurant. */
>  r->seats = seats;
>  r->at_table = 0;
>  r->finished = 0;
>  r->quitting = false;
>  pthread_mutex_init(&r->mutex, NULL);
>  pthread_cond_init(&r->seats_changed, NULL);
>}
>
>static void ramen_destroy(ramen_t *r)
>{
>  /* TODO: Destroy all synchronization primitives. */
>  pthread_mutex_destroy(&r->mutex);
>  pthread_cond_destroy(&r->seats_changed);
>}
>
>static void ramen_wait(ramen_t *r)
>{
>  /* TODO: Enter the restaurant unless it's full or people haven't left yet. */
>  pthread_mutex_lock(&r->mutex);
>
>  while (r->quitting || r->at_table == r->seats)
>    pthread_cond_wait(&r->seats_changed, &r->mutex);
>
>  r->at_table++;
>
>  pthread_mutex_unlock(&r->mutex);
>}
>
>static void ramen_finish(ramen_t *r)
>{
>  /* TODO: Finished eating, so wait for all other to finish before leaving. */
>  pthread_mutex_lock(&r->mutex);
>
>  // if (++r->finished == r->seats) // bar oblegany
>  if (++r->finished == r->at_table) // jemy w mniejszych grupkach
>  {
>    r->quitting = true;
>    pthread_cond_broadcast(&r->seats_changed);
>  }
>
>  while (!r->quitting)
>    pthread_cond_wait(&r->seats_changed, &r->mutex);
>
>  if (--r->at_table == 0)
>  {
>    r->finished = 0;
>    r->quitting = false;
>    pthread_cond_broadcast(&r->seats_changed);
>  }
>
>  pthread_mutex_unlock(&r->mutex);
>}
>```

## Zadanie 14-5

:::danger
Autor: Bartosz Głowacki
:::

```c=
#include "csapp.h"

static __thread unsigned seed;

static void rand_usleep(int min, int max) {
  usleep(rand_r(&seed) % (max - min + 1) + min);
}

#define DEBUG
#ifdef DEBUG
static __unused void outc(char c) {
  Write(STDOUT_FILENO, &c, 1);
}

/* XXX Please use following function to simulate malicious scheduler.
 * Just insert a call to rand_yield between instructions in your solution. */
static __unused void rand_yield(void) {
  /* Once every 100 calls to this function (on average)
   * it yields and lets kernel choose another thread. */
  if (rand_r(&seed) % 100 == 42)
    sched_yield();
}
#else
#define outc(c)
#define rand_yield()
#endif

typedef struct office {
  /* TODO: Put internal state & mutexes & condvars here. */
  unsigned all_seats; // constant value
  unsigned free_seats;
  bool clerk_free;
  bool is_job_done;
  
  int next_free_seat;
  int next_customer_seat;
  pthread_mutex_t seats_mutex;
  pthread_cond_t cond;
  pthread_cond_t job_done;
  pthread_cond_t clerk_waiting;
} office_t;

// returns seat number
static inline int sit_on_seat(office_t *o)
{
	o->free_seats--;
	int tmp = o->next_free_seat;
	o->next_free_seat = (o->next_free_seat + 1) % o->all_seats;
	return tmp;
}

static inline void get_up_from_the_seat(office_t *o)
{
	o->free_seats++;
	o->next_customer_seat = (o->next_customer_seat + 1) % o->all_seats;
}

static inline int i_am_next(office_t *o, int my_seat)
{
	return o->next_customer_seat == my_seat;
}

static void office_init(office_t *o, unsigned seats) {
  /* TODO: Initialize internal state of post office. */
  o->all_seats = seats;
  o->free_seats = seats;
  o->next_free_seat = 0;
  o->next_customer_seat = 0;
  o->clerk_free = true;
  o->is_job_done = false;
  pthread_mutex_init(&(o->seats_mutex), NULL);
  pthread_cond_init(&(o->cond), NULL);
  pthread_cond_init(&(o->clerk_waiting), NULL);
  pthread_cond_init(&(o->job_done), NULL);
}

static void office_destroy(office_t *o) {
  /* TODO: Destroy all synchronization primitives. */
  pthread_cond_destroy(&(o->cond));
  pthread_cond_destroy(&(o->clerk_waiting));
  pthread_cond_destroy(&(o->job_done));
  pthread_mutex_destroy(&(o->seats_mutex));
}

static bool customer_walk_in(office_t *o) {
  /* TODO: No seats then leave, otherwise wait for a clerk call. */
  pthread_mutex_lock(&(o->seats_mutex));
  if (o->free_seats == 0) {
  	pthread_mutex_unlock(&(o->seats_mutex));
  	return false;
  }
  int my_seat = sit_on_seat(o);
  pthread_cond_signal(&(o->clerk_waiting)); // przyszedłem więc potencjalnie muszę obudzić clerka
  while (!i_am_next(o, my_seat) || !o->clerk_free) {
  	pthread_cond_wait(&(o->cond), &(o->seats_mutex));
  }
  o->clerk_free = false;
  get_up_from_the_seat(o);
  
  //czekam dopóki nie skończy się robota
  while(!o->is_job_done)
    pthread_cond_wait(&(o->job_done),&(o->seats_mutex));
  o->is_job_done = false;
  
  pthread_mutex_unlock(&(o->seats_mutex));
  return true;
}

static void clerk_wait(office_t *o) {
  /* TODO: Wait for a customer or call one from a seat. */
  pthread_mutex_lock(&(o->seats_mutex));
  while(o->free_seats == o->all_seats) {
    pthread_cond_wait(&(o->clerk_waiting),&(o->seats_mutex));
  }
  pthread_cond_broadcast(&(o->cond));

  pthread_mutex_unlock(&(o->seats_mutex));
}

static void clerk_done(office_t *o) {
  /* TODO: Tell the customer that the job is done. */
  pthread_mutex_lock(&(o->seats_mutex));
  o->is_job_done = true;
  pthread_cond_signal(&(o->job_done));
  o->clerk_free = true;
  pthread_mutex_unlock(&(o->seats_mutex));
}

static void *customer(void *data) {
  office_t *b = data;

  seed = (unsigned)pthread_self();

  while (true) {
    if (customer_walk_in(b)) {
      /* Yay! I sent my registered mail :) */
      outc('+');
      /* I guess they'll force me to go there again... */
      rand_usleep(5000, 10000);
    } else {
      /* Heck! No empty seats :( */
      outc('-');
      /* Try again in a while... */
      rand_usleep(500, 1000);
    }
  }

  return NULL;
}

static void *clerk(void *data) {
  office_t *b = data;

  seed = (unsigned)pthread_self();

  while (true) {
    /* Wait for customer to walk in or grab one that is seated. */
    clerk_wait(b);
    /* Do the paperwork! */
    rand_usleep(500, 1000);
    /* Another customer leaving happy? */
    clerk_done(b);
  }

  return NULL;
}

#define SEATS 4
#define CUSTOMERS 12

int main(void) {
  office_t o;
  office_init(&o, SEATS);

  pthread_t clerkThread;
  pthread_t customerThread[CUSTOMERS];

  Pthread_create(&clerkThread, NULL, clerk, &o);
  for (int i = 0; i < CUSTOMERS; i++)
    Pthread_create(&customerThread[i], NULL, customer, &o);

  pthread_join(clerkThread, NULL);
  for (int i = 0; i < CUSTOMERS; i++)
    Pthread_join(customerThread[i], NULL);

  office_destroy(&o);
  return 0;
}
```

## Zadanie 14-6

:::danger
Autor: Paweł Zmarzły
:::

```c=
typedef struct ride
{
  /* TODO: Put internal state & mutexes & condvars here. */
  pthread_mutex_t mutex;

  int seats;
  int seats_reserved;
  int seats_taken;
  pthread_cond_t seat_reserved;
  pthread_cond_t seat_taken;
  pthread_cond_t seat_freed;

  bool ready_for_next_ride;
  pthread_cond_t became_ready_for_next_ride;

  bool cart_is_closed;
  pthread_cond_t cart_closed;
  pthread_cond_t cart_opened;
} ride_t;

static void ride_init(ride_t *r, unsigned seats)
{
  pthread_mutex_init(&r->mutex, NULL);

  r->seats = seats;
  r->seats_reserved = 0;
  r->seats_taken = 0;
  pthread_cond_init(&r->seat_reserved, NULL);
  pthread_cond_init(&r->seat_taken, NULL);
  pthread_cond_init(&r->seat_freed, NULL);

  r->ready_for_next_ride = true;
  pthread_cond_init(&r->became_ready_for_next_ride, NULL);

  r->cart_is_closed = false;
  pthread_cond_init(&r->cart_closed, NULL);
  pthread_cond_init(&r->cart_opened, NULL);
}

static void ride_destroy(ride_t *r)
{
  /* TODO: Destroy all synchronization primitives. */
  pthread_mutex_destroy(&r->mutex);
  pthread_cond_destroy(&r->seat_reserved);
  pthread_cond_destroy(&r->seat_taken);
  pthread_cond_destroy(&r->seat_freed);
  pthread_cond_destroy(&r->became_ready_for_next_ride);
  pthread_cond_destroy(&r->cart_closed);
  pthread_cond_destroy(&r->cart_opened);
}

static void cart_load(ride_t *r)
{
  /* TODO: Wait for all seats to be taken and depart. */
  pthread_mutex_lock(&r->mutex);

  while (r->seats_reserved < r->seats)
    pthread_cond_wait(&r->seat_reserved, &r->mutex);

  r->ready_for_next_ride = false;
  r->cart_is_closed = true;
  pthread_cond_broadcast(&r->cart_closed);

  while (r->seats_taken < r->seats)
    pthread_cond_wait(&r->seat_taken, &r->mutex);

  pthread_mutex_unlock(&r->mutex);
}

static void cart_unload(ride_t *r)
{
  /* TODO: Wait for all passangers to leave and be ready for next ride. */
  pthread_mutex_lock(&r->mutex);

  r->cart_is_closed = false;
  pthread_cond_broadcast(&r->cart_opened);

  while (r->seats_taken > 0)
    pthread_cond_wait(&r->seat_freed, &r->mutex);

  r->ready_for_next_ride = true;
  pthread_cond_broadcast(&r->became_ready_for_next_ride);

  pthread_mutex_unlock(&r->mutex);
}

static void passenger_board(ride_t *r)
{
  /* TODO: Wait for the cart, enter it and wait for the ride to begin. */
  pthread_mutex_lock(&r->mutex);

  while (!r->ready_for_next_ride || r->seats_reserved == r->seats)
    pthread_cond_wait(&r->became_ready_for_next_ride, &r->mutex);

  r->seats_reserved++;
  pthread_cond_broadcast(&r->seat_reserved);

  while (!r->cart_is_closed)
    pthread_cond_wait(&r->cart_closed, &r->mutex);

  // Zapięcie pasów, bez tego nie odjedziemy.
  // Bez dwustopniowego mechanizmu, blokowalibyśmy się wyżej
  // (wózek odjechałby i przyjechał zanim zauważylibyśmy).
  r->seats_taken++;
  r->seats_taken++;
  pthread_cond_broadcast(&r->seat_taken);

  pthread_mutex_unlock(&r->mutex);
}

static void passenger_unboard(ride_t *r)
{
  /* TODO: Wait for the ride to end and leave the cart. */
  pthread_mutex_lock(&r->mutex);

  while (r->cart_is_closed)
    pthread_cond_wait(&r->cart_opened, &r->mutex);

  r->seats_taken--;
  r->seats_reserved--;
  pthread_cond_broadcast(&r->seat_freed);

  pthread_mutex_unlock(&r->mutex);
}
```