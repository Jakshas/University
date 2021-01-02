#include "zadanie.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    wyrazenie *wyr = new odejmij(new pi(),new dodaj(new liczba(2),new mnoz(new zmienna("x",1),new liczba(7))));
    cout<<wyr->pisz()<<"="<<wyr->oblicz()<<endl;
    wyr=new dziel(new mnoz(new odejmij(new zmienna("x",1),new liczba(1)),new zmienna("x",1)),new liczba(2));
    cout<<wyr->pisz()<<"="<<wyr->oblicz()<<endl;
    wyr=new dziel(new dodaj(new liczba(3),new liczba(5)),(new mnoz(new zmienna("x",1),new liczba(7))));
    cout<<wyr->pisz()<<"="<<wyr->oblicz()<<endl;
    wyr= new odejmij(new dodaj(new liczba(2),new mnoz(new zmienna("x",1),new liczba(7))),new dodaj(new mnoz(new zmienna("y",1),new liczba(3)),new liczba(5)));
    cout<<wyr->pisz()<<"="<<wyr->oblicz()<<endl;
    wyr= new dziel(new mnoz(new dodaj(new zmienna("x",1),new liczba(1)),new zmienna("x",1)),new Exp(new Pot(new zmienna("x",1),new liczba(2))));
    cout<<wyr->pisz()<<"="<<wyr->oblicz()<<endl;
}
