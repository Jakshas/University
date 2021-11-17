#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct kolejka
{
    double *start,*finisz,*poczatek,*koniec;
} Kolejka;
void init_kol(Kolejka *kp,int n,double tab[n]);
void opruznij(Kolejka *kp,int n,double tab[n]);
double odpiszk(Kolejka *kp,int n,double tab[n]);
double odpiszp(Kolejka *kp,int n,double tab[n]);
void dopiszp(Kolejka *kp,int n,double tab[n],double dana);
void dopiszk(Kolejka *kp,int n,double tab[n],double dana);
bool puste(Kolejka *kp,int n,double tab[n]);
int main()
{
    Kolejka *kp;
    int n=20;
    double tab[20];
    for(int i=0; i<20; i++)
    {
        tab[i]=0;
    }
    init_kol(kp,n,tab);
    printf("co chcesz zrobic? d=dopisz, o=odpisz, p=opróznij, c=czy puste, w= wypisz, z=zakoncz");
    char c = getchar();
    double dana;
    if(c='d')
    {
        printf("podaj liczbe ");
        scanf("%d ",dana);
        scanf("Czy chcesz ja dodac na koncu? t/n %c",&c);
        if(c=='t')
        {
            dopiszk(kp,n,tab,dana);
        }
        if (c=='n')
        {
            dopiszp(kp,n,tab,dana);
        }
    }
    if(c=='o')
    {
        scanf("Czy chcesz ja dodac na koncu? t/n %c",&c);
        if(c=='t')
        {
            odpiszk(kp,n,tab);
        }
        if (c=='n')
        {
            odpiszp(kp,n,tab);
        }
    }
    if(c=='o')
    {
        opruznij(kp,n,tab);
    }
    if(c=='c')
    {
        if(puste(kp,n, tab)==true)
        {
            printf("jest pusta");
        }
        else
        {
            printf("nie jest pusta");
        }
    }
    if(c=='z')
    {
        return 0;
    }
    if(c=='w')
    {
        for(int i=0; i<20; i++)
        {
            printf("%lf",tab[i]);
        }
    }
}

void init_kol(Kolejka *kp,int n,double t[n])
{
    kp->koniec=t;
    kp->poczatek=t;
    kp->start=t;
    kp->finisz=t+n;
}
void opruznij(Kolejka *kp,int n,double t[n])
{
    kp->poczatek=kp->koniec;
}
double odpiszk(Kolejka *kp,int n,double t[n])
{
    double wynik;
    wynik=*kp->koniec;
    kp->koniec=0;
    if(kp->koniec+1==kp->finisz)
    {
        kp->koniec=t;
    }
    else
    {
        kp->koniec++;
    }
    return wynik;
}
double odpiszp(Kolejka *kp,int n,double t[n])
{
    double wynik;
    wynik=*kp->poczatek;
    kp->poczatek=0;
    if(kp->poczatek+1==kp->finisz)
    {
        kp->poczatek=t;
    }
    else
    {
        kp->poczatek++;
    }
    return wynik;
}
void dopiszp(Kolejka *kp,int n,double t[n],double dana)
{
    if(kp->poczatek-1==kp->koniec)
    {
        printf("kolejka pe³na");
    }
    else
    {
        if(kp->poczatek-1==kp->start)
        {
            kp->poczatek=t;
        }
        else
        {
            kp->poczatek--;
        }
        *kp->poczatek=dana;
    }
}
void dopiszk(Kolejka *kp,int n,double t[n],double dana)
{
    if(kp->koniec+1==kp->poczatek)
    {
        printf("kolejka pe³na");
    }
    else
    {
        if(kp->koniec+1==kp->finisz)
        {
            kp->koniec=t;
        }
        else
        {
            kp->koniec++;
        }
        *kp->koniec=dana;
    }
}
bool puste(Kolejka *kp,int n,double tab[n])
{
    if(kp->poczatek==kp->koniec)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Jakub Szajner
