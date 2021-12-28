#include <stdio.h>
#include <stdlib.h>
#include "modul.h"

int main()
{
    int dl;
    printf("podaj dlugosc ");
    scanf("%d",&dl);
    double ciag[dl];
    losowe(dl,ciag);
    double ciagpo[dl];
    if(poprawny(dl, ciag, ciagpo)){
        printf("poprawne");
    }
    if(czas1(ciag, dl)>czas2(ciag, dl)){
        printf("qsort szybszy");
    }else{
    if(czas1(ciag, dl)==czas2(ciag, dl)){
        printf("taki sam czas");
    }else{
    printf("moje sortowanie szybsze");}
    }
}
bool losowe(int dl, double ciag[])
{
    for(int i=0; i<dl; i++)
    {
        ciag[i]=rand();
    }
}
//Jakub Szajner
