#include <stdio.h>
#include <stdlib.h>
typedef struct ula{
int mianownik;
int licznik;
}Ulamki;

Ulamki *stwurz(int mianownik,int licznik);

int main()
{

}
Ulamki *stwurz(int mianownik,int licznik){
    Ulamki *ul;
    ul=malloc(sizeof(Ulamki));
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
    ul->licznik=x;
    ul->mianownik=y;
    return ul;
}
Ulamki *dodajn(Ulamki *jeden,Ulamki *dwa){
    Ulamki *ul;
    ul=malloc(sizeof(Ulamki));
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
ul->licznik=licznik;
ul->mianownik=mianownik;
return ul;
}
Ulamki *odejmijn(Ulamki *jeden,Ulamki *dwa){
    Ulamki *ul;
    ul=malloc(sizeof(Ulamki));
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
ul->licznik=licznik;
ul->mianownik=mianownik;
return ul;
}
Ulamki *dzieln(Ulamki *jeden,Ulamki *dwa){
    Ulamki *ul;
    ul=malloc(sizeof(Ulamki));
    int liczba1=jeden->licznik,liczba2=dwa->licznik;
    int iliczba1=jeden->mianownik,iliczba2=dwa->mianownik;
    int x=iliczba1,y=iliczba2,mianownik,licznik;
mianownik=iliczba1*liczba2;
licznik=liczba1*iliczba2;
ul->licznik=licznik;
ul->mianownik=mianownik;
return ul;
}
Ulamki *mnuzn(Ulamki *jeden,Ulamki *dwa){
    Ulamki *ul;
    ul=malloc(sizeof(Ulamki));
    int liczba1=jeden->licznik,liczba2=dwa->licznik;
    int iliczba1=jeden->mianownik,iliczba2=dwa->mianownik;
    int x=iliczba1,y=iliczba2,mianownik,licznik;
mianownik=iliczba1*iliczba1;
licznik=liczba1*liczba2;
ul->licznik=licznik;
ul->mianownik=mianownik;
return ul;
}
