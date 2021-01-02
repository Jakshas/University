#include <stdio.h>
#include <stdlib.h>
typedef int wart;
typedef struct tab
{
    int pozycja;
    wart wartosc;
    struct tab *nast;
} Tablica;
Tablica *nowa_tablica();
void dodaj(Tablica *t,int p,wart w);
int main()
{
    Tablica *t;
    t=nowa_tablica();
    dodaj(t,5,10);
    printf("|%d|",indeks(t,5));
    dodaj(t,5,11);
    printf("|%d|",indeks(t,5));
    dodaj(t,6,12);
    printf("|%d|",indeks(t,6));
    dodaj(t,4,18);
    printf("|%d|",indeks(t,4));

}

Tablica *nowa_tablica()
{
    Tablica *t=malloc(sizeof(Tablica));
    t->pozycja=NULL;
    t->wartosc=0;
    t->nast=NULL;
    return t;
}

void dodaj(Tablica *t,int p,wart w)
{
    if(t->pozycja==NULL)
    {
        t->pozycja=p;
        t->wartosc=w;
    }
    else
    {
        if(t->pozycja==p)
        {
            t->wartosc=w;
        }
        else
        {
            if(t->pozycja>p)
            {
                while(t->pozycja!=p)
                {
                    Tablica *tp=malloc(sizeof(Tablica));
                    tp->pozycja=t->pozycja-1;
                    tp->wartosc=0;
                    tp->nast=t;
                    *t=*tp;
                }
                t->wartosc=w;
            }
            else
            {
                if(t->pozycja<p)
                {
                    Tablica *wsk=t;
                    while((wsk->pozycja!=p))
                    {
                        if(wsk->nast==NULL)
                        {
                            Tablica *tp=malloc(sizeof(Tablica));
                            tp->pozycja=wsk->pozycja+1;
                            tp->wartosc=0;
                            tp->nast=NULL;
                            wsk->nast=tp;
                            *wsk=*tp;
                        }
                        else
                        {
                            wsk=wsk->nast;
                        }
                    }
                    wsk->wartosc=w;
                }
            }
        }
    }
}
wart indeks(Tablica *t,int p)
{
    Tablica *tp=t;
    while(tp->pozycja!=p&&tp->nast==NULL)
    {
        tp=tp->nast;
    }
    if(p==tp->pozycja)
    {
        return tp->wartosc;
    }
    return 0;
}
