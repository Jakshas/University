#include <iostream>
#include <ctime>
using namespace std;

void scalanie(int* tab, int l, int p, int n) {
    int* pom = new int[n];
    int i = 0;
    int ll = l;
    int pp = p;
    while (ll < p && pp < n)
    {
        if (tab[ll] < tab[pp])
        {
            pom[i] = tab[ll];
            i++;
            ll++;
        }
        else
        {
            pom[i] = tab[pp];
            i++;
            pp++;
        }
    }
    while (ll < p)
    {
        pom[i] = tab[ll];
        i++;
        ll++;
    }
    while (pp < n)
    {
        pom[i] = tab[pp];
        i++;
        pp++;
    }
    for (int i = 0; l + i < n; i++)
    {
        tab[l + i] = pom[i];
    }
    pom
}

void mergesort(int* tab, int poczatek, int koniec) {

    if (poczatek < koniec)
    {
        int srodek = (poczatek + koniec) / 2;
        mergesort(tab, poczatek, srodek);
        mergesort(tab, srodek + 1, koniec);
        scalanie(tab, poczatek, srodek + 1, koniec + 1);
    }

}

int main(int argc, char const *argv[])
{
    srand(time(0));
    int tab[100000];

    for (int i = 0; i < 100000; i++)
    {
        tab[i] = rand() % 100000;
    }
    mergesort(tab, 0, 100000-1);
    for (auto&& i : tab)
    {
        cout << i << " ";
    }

    return 0;
}