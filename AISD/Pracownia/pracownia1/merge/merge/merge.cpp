#include <iostream>
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

int main(int argc, char const* argv[])
{
    int tab[] = { 1,3,5,2,4,6 };
    mergesort(tab, 0, 5);
    for (auto&& i : tab)
    {
        cout << i << " ";
    }

    return 0;
}

