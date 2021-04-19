#include<iostream>
using namespace std;


void quick_sort(int *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;
	
	int i = lewy - 1, j = prawy + 1, 
	pivot = tab[(lewy+prawy)/2];
	
	while(i <= j)
	{   
        do{
            ++i;
        }while(pivot>tab[i]);
        do{
            --j;
        }
		while(pivot<tab[j]);
		
		if( i <= j)
			swap(tab[i],tab[j]);
	}

	if(j > lewy)
	quick_sort(tab, lewy, j);
	if(i < prawy)
	quick_sort(tab, i, prawy);
}

int main(int argc, char const *argv[])
{
    int *tab = new int[10];
    for(int i = 0 ; i <10;i++){
        tab[i] = 10 - i;
    }
    quick_sort(tab,0,9);
        for(int i = 0 ; i <10;i++){
        cout << tab[i]<< " ";
    }
    return 0;
}
