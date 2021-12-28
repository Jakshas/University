#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <stdbool.h>

Cykliczna *nowa(void)
{
    Cykliczna *p;
    if((p=(Cykliczna *)malloc(sizeof(Cykliczna)))==NULL)
    {
        return NULL;
    }
    else
    {
        p->koniec==NULL;
        return p;
    }
}
int do_cyklup(Cykliczna *cykl,TYP_INFO info)
{
    struct e_listy *p;

    if((p=(struct e_listy *)malloc(sizeof(struct e_listy))) == NULL)
        return 1;
    else
    {
        p->info=info;
        p->nast=NULL;
        if(cykl->koniec==NULL)
        {
            cykl->koniec=p->nast=p;
        }
        else
        {
            p->nast=cykl->koniec->nast;
            cykl->koniec->nast=p;
            return 0;
        }
    }
}
int do_cykluk(Cykliczna *cykl,TYP_INFO info)
{
    struct e_listy *p;

    if((p=(struct e_listy *)malloc(sizeof(struct e_listy))) == NULL)
        return 1;
    else
    {
        p->info=info;
        p->nast=NULL;
        if(cykl->koniec==NULL)
        {
            cykl->koniec=p->nast=p;
        }
        else
        {
            p->nast=cykl->koniec->nast;
            cykl->koniec->nast=p;
            cykl->koniec=p;
            return 0;
        }
    }
}
TYP_INFO podajp(Cykliczna *cykl)
{
    char* wynik=cykl->koniec->nast->info;
    return wynik;
}
TYP_INFO z_kolejki(Cykliczna *cykl)
{
    struct e_listy *p;
    TYP_INFO info;
    if((p=cykl->koniec->nast) == NULL)
        return TYP_NULL;
    else
    {
        cykl->koniec->nast=cykl->koniec->nast->nast;
        info=p->info;
        free(p);
        return info;
    }
}
bool pusta(Cykliczna *cykl){
    if(cykl->koniec==NULL){
        return true;
    }else{
    return false;
    }
}
int dlugosc(Cykliczna *cykl){
    struct e_listy *p;
    int x=0;
    p=cykl->koniec->nast;
    while(p==cykl->koniec){
        x++;
        p=p->nast;
    }
    return x;
}
//Jakub Szajner
