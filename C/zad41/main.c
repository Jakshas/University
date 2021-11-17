#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"

int main()
{
    int licznik1=0,mianownik1=0;
    int licznik2=0,mianownik2=0;
    char znak;
    scanf("%d/%d%c%d/%d",&licznik1,&mianownik1,&znak,&licznik2,&mianownik2);
    Wymierna liczba1=konstruujW(licznik1,mianownik1);
    Wymierna liczba2=konstruujW(licznik2,mianownik2);
    wypisz(liczba1);
    wypisz(liczba2);
    if(znak==':'){
    Wymierna z= dziel(liczba1,liczba2);
    wypisz(z);}
    if(znak=='*'){
    Wymierna c= mnoz(liczba1,liczba2);
    wypisz(c);}
    if(znak=='+'){
    Wymierna g =dodaj(liczba1,liczba2);
    wypisz(g);}
    if(znak=='-'){
    Wymierna n =odejmij(liczba1,liczba2);
    wypisz(n);}
}
// Jakub Szajner
