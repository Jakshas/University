#include<iostream>
#include "quick.h"

using namespace std;


void quicksort(int *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return; //gdy brak elementow do porownania 
	
	int i = lewy - 1, j = prawy + 1,
	pivot = tab[(lewy+prawy)/2]; //ustawiana os
	
	while(i <= j) //dopoki "lewa" mniejsza, rowna "prawa"
	{   
        do{
            ++i;
        }while(pivot>tab[i]); //dopoki element po "lewej" jest mniejszy od pivota
		
        do{
            --j;
        }while(pivot<tab[j]); //dopoki element "prawy" jest wiekszy od pivota
		
		if( i <= j)
			swap(tab[i],tab[j]); //zamienia elementy gdy "lewy" jest mnniejszy rowny prawemu
	}

	if(j > lewy) //sortowanie przesuniete gdy "prawa" jest wieksza od lewa
	quicksort(tab, lewy, j);
	if(i < prawy) //sortownie gdy "lewa" jest mniesza od prawa
	quicksort(tab, i, prawy);
}