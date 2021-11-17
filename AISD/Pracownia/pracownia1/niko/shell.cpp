//plik wykonawczy dla sortowania shella
#include <iostream>
#include <random>
#include "shell.h"

using namespace std;


void shellsort(int* tab, int n, int o) { //insert sort na odleglosci o
    for (int i = o; i < n; i++)
    {
        int el = tab[i];
        int j = i - o;
        while (j >= 0 && tab[j] > el)
        {
            tab[j + o] = tab[j];
            j = j - o;
        }
        tab[j + o] = el;
    }
}

void shell(int* tab, int n) { //tablica, rozmiar
    for (int i = 10; i <= n; i=i*10)
    {
        shellsort(tab, n, n/i);
    }
    
    //shellsort(tab, n, 1000);
    //shellsort(tab, n, 100);
    //shellsort(tab, n, 10);
    //shellsort(tab, n, 1);

    //optymalniej for (int i = 5; i <= n; i=i*2)
}


