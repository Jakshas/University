#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <stdbool.h>
int main()
{
    Cykliczna *cykl=nowa();
    Cykliczna *cykl2=nowa();
    TYP_INFO info={'a'};
    do_cyklup(cykl,info);
    do_cyklup(cykl2,info);
    do_cykluk(cykl,info);
    podajp(cykl);
    TYP_INFO z=podajp(cykl);
//    printf("%s ",z);
    z=z_kolejki(cykl);
  //  printf("%s ",z);
    if(pusta(cykl)){
        printf("jest pusta");
    }else{
    printf("ma wartosci");}
    printf("to jej dlugosc %d",dlugosc(cykl));
    polacz(cykl,cykl);
    info='z';
    wstawsort(cykl,info);
    kopiuj(cykl);
    do_cyklup(cykl,'b');
    do_cyklup(cykl,'g');
    do_cyklup(cykl,'a');
    quicksort(cykl);
}
//Jakub Szajner
