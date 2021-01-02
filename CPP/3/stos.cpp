#include "stos.hpp"
#include <string>
using namespace std;

void stos::wluz(string slowo){
    if(ile<pojemnosc){
        tablica[ile]=slowo;
        ile++;
    }}
string stos::sciagnij(){
    if(ile>0){
        ile--;
        string pom=tablica[ile];
        tablica[ile]="";
        return pom;
    }
    return "";
}
string stos::sprawdz(){
    if(ile>0){
        string s=tablica[ile-1];
    return s;}
    return "nie ma nic na stosie";
}
int stos::rozmiar(){
    return ile;
}
stos stos::odwroc(){
    stos nowa(pojemnosc);
    for(int i=0;i<ile;i++){
        nowa.tablica[i]=tablica[ile-1-i];
    }
    nowa.ile=ile;
    nowa.pojemnosc=pojemnosc;
    return nowa;
}