#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <stdbool.h>
#include <string.h>

Cykliczna *nowa(void)
{
    Cykliczna *p;
    if((p=(Cykliczna *)malloc(sizeof(Cykliczna)))==NULL)
    {
        return NULL;
    }
    else
    {
        p->koniec=NULL;
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
    return 0;
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
    return 0;
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
bool pusta(Cykliczna *cykl)
{
    if(cykl->koniec==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int dlugosc(Cykliczna *cykl)
{
    struct e_listy *p;
    int x=1;
    p=cykl->koniec->nast;
    while(p!=cykl->koniec)
    {
        x++;
        p=p->nast;
    }
    return x;
}
int polacz(Cykliczna *cykl1,Cykliczna *cykl2)
{
    cykl2->koniec->nast=cykl1->koniec->nast;
    cykl1->koniec->nast=cykl2->koniec->nast;
    return 0;
}
void kopiuj(Cykliczna *cykl)
{
    struct e_listy *p;
    struct e_listy *kon;
    p=cykl->koniec->nast;
    kon=cykl->koniec;
    Cykliczna *kopia=nowa();
    do
    {
        TYP_INFO info=p->info;
        do_cykluk(kopia,info);
        p=p->nast;
    }
    while(p!=kon);
}
int wstawsort(Cykliczna *cykl, TYP_INFO info)
{
    int x=0;
    struct e_listy *p, *z;
    p=cykl->koniec->nast;
    while(strcmp(p->nast->info,info)==info&&x<dlugosc(cykl))
    {
        p=p->nast;
        x++;
    }
    if((z=(struct e_listy *)malloc(sizeof(struct e_listy))) == NULL)
        return 1;
    else
    {
        z->info=info;
        z->nast=p->nast;
        p->nast=z;
    }
    return 0;
}
void quicksort(Cykliczna *cykl){
    TYP_INFO pivot=cykl->koniec->info;
    Cykliczna *ckl1=nowa();
    Cykliczna *ckl2=nowa();
    do_cykluk(ckl2,cykl->koniec->info);
    struct e_listy *p=cykl->koniec->nast;
    if((p=(struct e_listy *)malloc(sizeof(struct e_listy))) == NULL)
        return 1;
    else{
    while(p!=cykl->koniec){
        if(strcmp(pivot,p->info)==pivot){
           wstawsort(ckl1,p->info);
        }else{
        wstawsort(ckl2,p->info);
        }
        p=p->info;
    }
    polacz(ckl1,ckl2);
}
}
//Jakub Szajner

