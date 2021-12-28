#include "wymierne.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
Wymierna wylicz(int ilosc, Wymierna tabela[ilosc])
{
    Wymierna wynik=0;
    printf("zmienna ");
    int izmienna=0;
    scanf("%d",&izmienna);
    double dzmienna=(double)izmienna;
    double p=0;
    for(int i=ilosc; i>0; i--)
    {
        Wymierna liczba=tabela[i];
        int iliczba=(int)liczba;
        liczba=liczba-iliczba;
        liczba>>=32;
        int x=liczba,y=iliczba,z;
        while(y>0)
        {
            if(x<y)
            {
                z=x;
                x=y;
                y=z;
            }
            x=x-y;
        }
        liczba=liczba/x;
        iliczba=iliczba/x;
        wynik=(wynik+pow(izmienna,p)*liczba)/iliczba;
        return wynik;
    }
}
Wymierna pisz(Wymierna tabela[],int ilosc){
    int potega=ilosc-1;
    for(int i=0;i<ilosc-1;i++){
        wypisz(tabela[i]);
        printf("*x^%d+",potega);
        potega--;
    }
    wypisz(tabela[ilosc-1]);
}
Wymierna dodawanie(Wymierna tablica1[],Wymierna tablica2[],int dlugosc1,int dlugosc2){
    Wymierna tablica[10];
    if(dlugosc1>dlugosc2){
            int potega=dlugosc1-1;
            int i;
    for(i=0;i<dlugosc2;i++){
        Wymierna z=dodaj(tablica1[i],tablica2[i]);
        wypisz(z);
        printf("*x^%d+",potega);
        potega--;
    }
    for(;i<dlugosc1;i++){
         wypisz(tablica1[i]);
        printf("*x^%d+",potega);
        potega--;
    }
    pisz(tablica,dlugosc1);
    }else{
        int i;
        int potega=dlugosc2-1;
    for(i=0;i<dlugosc1;i++){
        Wymierna z=dodaj(tablica1[i],tablica2[i]);
        wypisz(z);
        printf("*x^%d+",potega);
        potega--;
    }
    for(;i<dlugosc2;i++){
        wypisz(tablica2[i]);
        printf("*x^%d+",potega);
        potega--;
    }
    pisz(tablica,dlugosc2);
    }
}
Wymierna odejmowanie(Wymierna tablica1[],Wymierna tablica2[],int dlugosc1,int dlugosc2){
    Wymierna tablica[10];
    if(dlugosc1>dlugosc2){
            int potega=dlugosc1-1;
            int i;
    for(i=0;i<dlugosc2;i++){
        Wymierna z=odejmij(tablica1[i],tablica2[i]);
        wypisz(z);
        printf("*x^%d+",potega);
        potega--;
    }
    for(;i<dlugosc1;i++){
         wypisz(tablica1[i]);
        printf("*x^%d+",potega);
        potega--;
    }
    pisz(tablica,dlugosc1);
    }else{
        int i;
        int potega=dlugosc2-1;
    for(i=0;i<dlugosc1;i++){
        Wymierna z=odejmij(tablica1[i],tablica2[i]);
        wypisz(z);
        printf("*x^%d+",potega);
        potega--;
    }
    for(;i<dlugosc2;i++){
        wypisz(tablica2[i]);
        printf("*x^%d+",potega);
        potega--;
    }
    pisz(tablica,dlugosc2);
    }
}
//Jakub Szajner
