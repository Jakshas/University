#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void perm(int n,int tablica[]);
void zmien(int *a, int *b);
void wypisz(int tablica[]);
int nc;
int main()
{
    int n;
    scanf("%d",&n);
    nc=n;
    int tablica[n];
    for(int i=0; i<=n; i++)
    {
        tablica[i]=i+1;
    }
    n=0;
    perm(n,tablica);
}
void perm(int n, int tablica[])
{
    if(n<nc-1)
    {
        for(int i = n; i < nc; i++)
        {
            int c = tablica[n];
            tablica[n] = tablica[i];
            tablica[i] = c;
            perm(n+1,tablica);
        }
    int c = tablica[n];
    for(int i = n; i < nc-1; i++) tablica[i] = tablica[i+1];
    tablica[nc-1] = c;
    }
    else
    {
        int x=0;
         for(int p = 0; p < nc; p++){
        for(int licznik=1; p+licznik < nc; licznik++){
            if(tablica[p]+licznik==tablica[p+licznik]){
                x++;
                break;
            }
        for(int licznik=1; p+licznik < nc ; licznik++)
            if(tablica[p]-licznik==tablica[p+licznik]){
                x++;
                break;
            }
        }
    }
    if(x==0){
        for(int i = 0; i < nc; i++)
    {
        printf("%d ",tablica[i]);
    }
    printf("\n");
    }}
}

