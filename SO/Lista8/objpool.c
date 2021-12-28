#include "csapp.h"
#include "bitstring.h"

typedef struct {
  int data[8];          /* contents does not matter, sizeof(...) = 32 */
} object_t;

#define ARENA_EXTRA                                                            \
  struct {                                                                     \
    size_t nitems;      /* number of items */                                  \
    size_t nfree;       /* number of free items */                             \
    void *items;        /* pointer to first item */                            \
    bitstr_t bitmap[0]; /* bitmap of free items */                             \
  }

#include "arena.h"

static arenalist_t arenas = STAILQ_HEAD_INITIALIZER(arenas);

static arena_t *init_arena(arena_t *ar) {
  /* TODO: Calculate nitems given ARENA_SIZE, size of arena_t and object_t. */
  // how much space can be assigned for content of blocks
  size_t avaiable_space = (ARENA_SIZE - sizeof(arena_t));

  // size of a bitmap that'll represent avaiable_space/(single block size)
  // number of elements
  size_t bitmap_size = bitstr_size(avaiable_space / sizeof(object_t));

  // the bitmap size has to be alse taken into consideration
  size_t nitems = (avaiable_space - bitmap_size) / sizeof(object_t);
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
    /* znajdujemy pierwszy wolny blok (pierwszy zerowy bit) */
  bit_ffc( ar->bitmap, ar->nitems, &index );
  /* zmieniamy stan bloku z wolnego na wykorzystany */
  bit_set( ar->bitmap, index );
  /* zmniejszamy ilość wolnych bloków */
  ar->nfree--;
  return ar->items + sizeof(object_t) * index;
}

static void free_block(arena_t *ar, void *ptr) {
  int index = (ptr - ar->items) / sizeof(object_t);
  /* TODO: Determine if ptr is correct and mark it free, update nfree. */
    /* upewniam się, że index wskazuje na obiekt wewnątrz naszej areny */
  /* i sprawdzam, czy użytkownik nie próbuje zwolnić wolnego już bloku */
  assert( ( index >= 0 && index < ar->nitems ) && bit_test( ar->bitmap, index ) );
  /* czyścimy blok i zwiększamy ilość wolnych bloków */
  bit_clear( ar->bitmap, index );
  ar->nfree++;
}

static void *objalloc(void) {
  /* Find arena with at least one free item. */
  arena_t *ar = NULL;
  STAILQ_FOREACH(ar, &arenas, arenalink) {
    if (ar->nfree > 0)
      return alloc_block(ar);
  }
  /* If none found then allocate an item from new arena. */
  return alloc_block(init_arena(alloc_after_arena(&arenas, NULL)));
}

static void objfree(void *ptr) {
  if (ptr == NULL)
    return;
  arena_t *ar = find_ptr_arena(&arenas, ptr);
  assert(ar != NULL);
  free_block(ar, ptr);
}

static void objmemcheck(void) {
  arena_t *ar;
  STAILQ_FOREACH(ar, &arenas, arenalink) {
    /* Check if nfree matches number of cleared bits in bitmap. */
    size_t nused = 0;
    for (int i = 0; i < ar->nitems; i++)
      nused += bit_test(ar->bitmap, i) ? 1 : 0;
    assert(nused == ar->nitems - ar->nfree);
  }
}

/* The test */

#define MAX_PTRS 10000
#define CYCLES 100

static void *alloc_fn(int *lenp) {
  *lenp = sizeof(object_t);
  return objalloc();
}

#define free_fn objfree
#define memchk_fn objmemcheck

#include "test.h"
