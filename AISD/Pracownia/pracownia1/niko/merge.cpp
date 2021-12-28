#include <iostream>
#include "merge.h"

using namespace std;

void scalanie(int* tab, int l, int p, int n) {
    int* pom = new int[n-l]; //wycinek kawalka tablicy glownej
    int i = 0; //iterator
    int ll = l;
    int pp = p;

    while (ll < p && pp < n) //lewa < srodek i prawa < koniec 
    {
        if (tab[ll] < tab[pp]) //gdy element na pocz < niz srodkowy
        {
            pom[i] = tab[ll];
            i++;
            ll++;
        }
        else
        {
            pom[i] = tab[pp]; //gdy element na pocz > niz srodkowy
            i++;
            pp++;
        }
    }

    while (ll < p) //gdy poczatek < srodek
    {
        pom[i] = tab[ll];
        i++;
        ll++;
    }

    while (pp < n) //gdy sordek < koniec
    {
        pom[i] = tab[pp];
        i++;
        pp++;
    }

    for (int i = 0; l + i < n; i++) //dopoki poczatek + iterator < koniec dodawaj
    {
        tab[l + i] = pom[i];
    }
    delete[] pom; //usuniecie dla zwolninia pamieci
}

void mergesort(int* tab, int poczatek, int koniec) {

    if (poczatek < koniec)
    {
        int srodek = (poczatek + koniec) / 2; //podzial na pol
        mergesort(tab, poczatek, srodek); // do sordka
        mergesort(tab, srodek + 1, koniec);//od sordka
        scalanie(tab, poczatek, srodek + 1, koniec + 1); //calosc, koniec +1 dla rozmiaru tbalicy
    }

}