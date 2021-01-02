#include <stdio.h>
#include <stdlib.h>
#include "wymierne.h"
Wymierna konstruujW(int licznik,int mianownik){
        if(mianownik==0){
        return 0;
    }
    if(mianownik<0){
        mianownik*=-1;
        licznik*=-1;
    }
    int x=licznik,y=mianownik,z;
    if(x<0){
        x=x*-1;
    }
    while(y>0){
        if(x<y){
            z=x;
            x=y;
            y=z;
        }
        x=x-y;
    }
    licznik=licznik/x;
    mianownik=mianownik/x;
    Wymierna liczba;
    liczba=licznik;
    liczba<<=32;
    liczba=liczba+mianownik;
    return liczba;

}
Wymierna wypisz(Wymierna liczba){
int iliczba=(int)liczba;
liczba=liczba-iliczba;
liczba>>=32;
int x=liczba,y=iliczba,z;
    while(y>0){
        if(x<y){
            z=x;
            x=y;
            y=z;
        }
        x=x-y;
    }
     liczba=liczba/x;
     iliczba=iliczba/x;
printf("%lld/%d",liczba,iliczba);
}
Wymierna dziel(Wymierna liczba1,Wymierna liczba2){
int mianownik, licznik;
int iliczba1=(int)liczba1;
liczba1=liczba1-iliczba1;
liczba1>>=32;
int iliczba2=(int)liczba2;
liczba2=liczba2-iliczba2;
liczba2>>=32;
mianownik=iliczba1*liczba2;
licznik=liczba1*iliczba2;
Wymierna liczba;
liczba=licznik;
liczba<<=32;
liczba=liczba+mianownik;
return liczba;

}
Wymierna mnoz(Wymierna liczba1,Wymierna liczba2){
int mianownik, licznik;
int iliczba1=(int)liczba1;
liczba1=liczba1-iliczba1;
liczba1>>=32;
int iliczba2=(int)liczba2;
liczba2=liczba2-iliczba2;
liczba2>>=32;
mianownik=iliczba1*iliczba2;
licznik=liczba1*liczba2;
Wymierna liczba;
liczba=licznik;
liczba<<=32;
liczba=liczba+mianownik;
return liczba;

}
Wymierna dodaj(Wymierna liczba1,Wymierna liczba2){
int mianownik, licznik,x,y;
int iliczba1=(int)liczba1;
liczba1=liczba1-iliczba1;
liczba1>>=32;
int iliczba2=(int)liczba2;
liczba2=liczba2-iliczba2;
liczba2>>=32;
x=iliczba1,y=iliczba2;
int z;
 while(y>0){
        if(x<y){
            z=x;
            x=y;
            y=z;
        }
        x=x-y;
    }
    if(x=1){
        liczba1=liczba1*iliczba2;
        liczba2=liczba2*iliczba1;
        iliczba1=iliczba2*iliczba1;
        mianownik=iliczba1;
        licznik=liczba1+liczba2;
    }else{
    iliczba1=iliczba1*x;
    liczba1=liczba1*x;
    liczba2=liczba2*x;
    mianownik=iliczba1;
    licznik=liczba1+liczba2;
}
Wymierna liczba;
liczba=licznik;
liczba<<=32;
liczba=liczba+mianownik;
return liczba;
}
Wymierna odejmij(Wymierna liczba1,Wymierna liczba2){
int mianownik, licznik,x,y;
int iliczba1=(int)liczba1;
liczba1=liczba1-iliczba1;
liczba1>>=32;
int iliczba2=(int)liczba2;
liczba2=liczba2-iliczba2;
liczba2>>=32;
x=iliczba1,y=iliczba2;
int z;
 while(y>0){
        if(x<y){
            z=x;
            x=y;
            y=z;
        }
        x=x-y;
    }
    if(x=1&&liczba1!=liczba2){
        liczba1=liczba1*iliczba2;
        liczba2=liczba2*iliczba1;
        iliczba1=iliczba2*iliczba1;
        mianownik=iliczba1;
        licznik=liczba1+liczba2;
    }else{
    iliczba1=iliczba1*x;
    liczba1=liczba1*x;
    liczba2=liczba2*x;
    mianownik=iliczba1;
    licznik=liczba1-liczba2;
}
Wymierna liczba;
liczba=licznik;
liczba<<=32;
liczba=liczba+mianownik;
return liczba;
}
// Jakub Szajner

