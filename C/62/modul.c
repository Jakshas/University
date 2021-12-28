#include "modul.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool poprawny(int dl, double ciagprz[], double ciagpo[])
{
    int c=0,w=0;
    for(int i=0; i<dl-1;i++){
        if(ciagpo[i]<=ciagpo[i+1]){
            c++;
        }
    }
    if(c==dl-1){
        w++;
    }
    int czysa=0;
    for(int i=0; i<dl;i++){
            int b=0;
        for(int j=0; j<dl;j++){
            if(ciagpo[i]==ciagprz[j]){
                b++;
            }
        }
        if(b>=1){
            czysa++;
        }
    }
    if(czysa==dl){
        w++;
    }
    if(w==2){
        return true;
    }else{
    return false;
    }
}
int czas1(double ciagprz[],int dl){
    long int z=clock();
    qsort(ciagprz,dl,sizeof(int),compare);
    int wynik=clock()-z;
    return wynik;
}
int czas2(double ciagprz[],int dl){
    long int z=clock();
    sortowanie(dl,ciagprz);
    int wynik=clock()-z;
    return wynik;
}
int compare (const void * x, const void * y)
{
    int xx = *(int*)x;
    int yy = *(int*)y;
    if(xx<yy) return -1;
    else if(xx==yy) return 0;
    else return 1;
}
void sortowanie(int dl,int tablica[])
{
for(int i = 1; i < dl; ++i) {
        int x = tablica[i];
        int j;
        for (j=i-1; j>= 0&& tablica[j]>x; --j) {
            tablica[j+1] = tablica[j];
        }
        tablica[j+1] = x;
    }
}
//Jakub Szajner
