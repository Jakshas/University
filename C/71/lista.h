#include <stdlib.h>
#define TYP_INFO char*
#define TYP_NULL NULL
#include <stdbool.h>

struct e_listy
{
    TYP_INFO info;
    struct e_listy *nast;
};
typedef struct cykl
{
    struct e_listy *koniec;
} Cykliczna;

Cykliczna *nowa(void);
int do_cyklup(Cykliczna *cykl,TYP_INFO info);
int do_cykluk(Cykliczna *cykl,TYP_INFO info);
TYP_INFO podajp(Cykliczna *cykl);
TYP_INFO z_kolejki(Cykliczna *cykl);
bool pusta(Cykliczna *cykl);
int dlugosc(Cykliczna *cykl);
//Jakub Szajner
