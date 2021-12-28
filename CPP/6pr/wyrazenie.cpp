#include "wyrazenie.hpp"
#include<math.h>
using namespace std;
vector<pair<string,double>> zmienna::zbior;
liczba::liczba(double input){
    this->priorytet = -1;
    this->wartosc = input;
}

string liczba::opis(){
    return to_string(wartosc);
}

double liczba::oblicz(){
    return wartosc;
}
 
pi::pi() {
    priorytet = -1;
    wartosc = 3.1415926535897;
}

double pi::oblicz(){
    return 3.14159265358979;
}

string pi::opis(){
    return "π";
}

e::e(){
    priorytet = -1;
    wartosc = 2.71828182845;
}

double e::oblicz(){
    return 2.71828182845;
}

string e::opis(){
    return "2.71828182845";
}

fi::fi(){
    priorytet = -1;
    wartosc = double(1.61803398874);
}

string fi::opis(){
    return "1.61803398874";
}

double fi::oblicz(){
    return 1.61803398874;
}

zmienna::zmienna(string nazwa, double wartosc){
    nazwa_zmiennej = nazwa;
    bool jest;
    priorytet = -1;
    for(int i{0}; i < zmienna::zbior.size(); i++){
        if (zmienna::zbior[i].first == nazwa){
            jest = true;
            zmienna::zbior[i].second == wartosc;
        }
    }
    if(jest == false){
        zbior.push_back(make_pair(nazwa, wartosc));
    }
}

string zmienna::opis(){
    return nazwa_zmiennej;
}

double zmienna::oblicz(){
    for(int i{0}; i < zbior.size(); i++){
        if (zbior[i].first == nazwa_zmiennej){
            return zbior[i].second;
        }
    }
}

Sin::Sin(wyrazenie *k){
    priorytet = -1;
    wyr = k;
}

string Sin::opis(){
    return "sin" + wyr->opis();
}

double Sin::oblicz(){
    return sin(wyr->oblicz());
}

Cos::Cos(wyrazenie *k){
    priorytet = -1;
    wyr = k;
}

string Cos::opis(){
    return "cos" + wyr->opis();
}

double Cos::oblicz(){
    return cos(wyr->oblicz());
}

przeciw::przeciw(wyrazenie *k){
    priorytet = -1;
    wyr = k;
}

string przeciw::opis(){
    return "-" + wyr->opis();
}

double przeciw::oblicz(){
    return (-1) * wyr->oblicz();
}

odwrot::odwrot(wyrazenie *k){
    priorytet = -1;
    wyr = k;
}

string odwrot::opis(){
    return "1/" + wyr->opis();
}

double odwrot::oblicz(){
    return 1 / wyr->oblicz();
}

Exp::Exp(wyrazenie *k){
    priorytet = -1;
    wyr = k;
}

string Exp::opis(){
    return "exp" + wyr->opis(); 
}

double Exp::oblicz(){
    return exp(wyr->oblicz());
}

ln::ln(wyrazenie *k){
    priorytet = -1;
    wyr = k;
}

string ln::opis(){
    return "ln" +  wyr->opis();
}

double ln::oblicz(){
    return log(wyr->oblicz());
}

bezw::bezw(wyrazenie *k){
    priorytet = -1;
    wyr = k;
}

string bezw::opis(){
    return "|" + wyr->opis() + "|";
}

double bezw::oblicz(){
    if(wyr->oblicz() >= 0){
        return wyr->oblicz();
    }
    else{
        return -1 * wyr->oblicz();
    }
}

operatorbin::operatorbin(wyrazenie *l, wyrazenie *p){
    lewe = l; prawe - p;
}

Dod::Dod(wyrazenie *l, wyrazenie *p) : operatorbin(l, p){
    lewostronnielaczne = 1; priorytet = 1;
}

double Dod::oblicz(){
    return lewe->oblicz() + prawe -> oblicz();
}

string Dod::opis(){

}

Odejm::Odejm(wyrazenie *l, wyrazenie *p) : operatorbin(l, p) {
    lewostronnielaczne = 1; priorytet = 1;
}

double Odejm::oblicz(){
    return lewe->oblicz() - prawe->oblicz();
}

string Odejm::opis(){

}

Mnoz::Mnoz(wyrazenie *l, wyrazenie *p) : operatorbin(l, p){
    priorytet = 2; lewostronnielaczne = 1;
}

double Mnoz::oblicz(){
    return lewe->oblicz() * prawe->oblicz();
}

string Mnoz::opis(){

}

Dziel::Dziel(wyrazenie *l, wyrazenie *p) : operatorbin(l, p){
    priorytet = 2; lewostronnielaczne = 1;
}

double Dziel::oblicz(){
    if(prawe->oblicz() == 0){
        throw invalid_argument("Nie dzielimy przez 0!");
    }
    return lewe->oblicz() / prawe->oblicz();
}

string Dziel::opis(){

}

Pot::Pot(wyrazenie *l, wyrazenie *p) : operatorbin(l, p){
    priorytet = 3; lewostronnielaczne = 0;
}

double Pot::oblicz(){
    return pow(lewe->oblicz(), prawe->oblicz());
}

string Pot::opis(){
    
}

Log::Log(wyrazenie *l, wyrazenie *p) : operatorbin(l, p){
    priorytet = 3; lewostronnielaczne = 0;
}

double Log::oblicz(){
    return log(prawe->oblicz()) / log(lewe->oblicz()); //ze wzoru na zamiane podstawy logarytmu
}

string Log::opis(){

}

Mod::Mod(wyrazenie *l, wyrazenie *p) : operatorbin(l, p){
    priorytet = 2; lewostronnielaczne = 0;
}

double Mod::oblicz(){
    if(prawe->oblicz()){
        throw invalid_argument("Nie da się wziąć modulo 0!");
    }
    return lewe->oblicz() - prawe->oblicz() * (floor(lewe->oblicz() / prawe->oblicz()));
}

int main(){
    pi k = pi();
    cout << k.opis() << '\n';
    cout << (new fi)->oblicz() << '\n';
}
