#include <stdio.h>
#include <stdlib.h>

#include "wymierne.h"


int main()
{
    int ilosc=0;
    printf("Podaj dlugosc wielomianu 1 ");
    scanf("%d",&ilosc);
    Wielomian wielo;
    Wymierna wielo2;
    Wymierna z;
    for(int i=0;i<ilosc;i++){
        int a=0,b=0;
        scanf("%d/%d",&a,&b);
        z=konstruujW(a,b);
        wielo[i]=z;
    }
    int ilosc2=0;
    printf("Podaj dlugosc wielomianu 2 ");
    scanf("%d",&ilosc2);
    for(int i=0;i<ilosc;i++){
        int a=0,b=0;
        scanf("%d/%d",&a,&b);
        Wymierna z=konstruujW(a,b);
        wielo[i]=z;
    }
Wymierna a=wylicz(ilosc,wielo);
printf("%lld",a);
//pisz(wielo,ilosc);
//dodawanie(wielo,wielo2,ilosc,ilosc2);
//odejmowanie(wielo,wielo2,ilosc,ilosc2);
}
//Jakub Szajner
