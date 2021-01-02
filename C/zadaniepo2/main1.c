
#include <stdio.h>
#include <stdlib.h>
typedef struct ula{
int mianownik;
int licznik;
}Ulamki;
Ulamki *dodaj(Ulamki *jeden,Ulamki *dwa){
    int liczba1=jeden->licznik,liczba2=dwa->licznik;
    int iliczba1=jeden->mianownik,iliczba2=dwa->mianownik;
    int x=iliczba1,y=iliczba2,mianownik,licznik;
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
dwa->licznik=licznik;
dwa->mianownik=mianownik;
return dwa;
}
Ulamki *odejmij(Ulamki *jeden,Ulamki *dwa){
    int liczba1=jeden->licznik,liczba2=dwa->licznik;
    int iliczba1=jeden->mianownik,iliczba2=dwa->mianownik;
    int x=iliczba1,y=iliczba2,mianownik,licznik;
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
dwa->licznik=licznik;
dwa->mianownik=mianownik;
return dwa;
}
Ulamki *dziel(Ulamki *jeden,Ulamki *dwa){
    int liczba1=jeden->licznik,liczba2=dwa->licznik;
    int iliczba1=jeden->mianownik,iliczba2=dwa->mianownik;
    int x=iliczba1,y=iliczba2,mianownik,licznik;
mianownik=iliczba1*liczba2;
licznik=liczba1*iliczba2;
dwa->licznik=licznik;
dwa->mianownik=mianownik;
return dwa;
}
Ulamki *mnuz(Ulamki *jeden,Ulamki *dwa){
    int liczba1=jeden->licznik,liczba2=dwa->licznik;
    int iliczba1=jeden->mianownik,iliczba2=dwa->mianownik;
    int x=iliczba1,y=iliczba2,mianownik,licznik;
mianownik=iliczba1*iliczba1;
licznik=liczba1*liczba2;
dwa->licznik=licznik;
dwa->mianownik=mianownik;
return dwa;
}
