#include "zadanie.hpp"

using namespace std;

liczba::liczba(double input){
    this->wartosc=input;
    prio=-1;
}
string liczba::pisz(){
    return to_string(wartosc);
}
double liczba::oblicz(){
    return wartosc;
}
string pi::pisz(){
    return "π";
}
double pi::oblicz(){
    return wartosc;
}
pi::pi(){
    this->wartosc=3.14159265358979;
    prio=-1;
}
string e::pisz(){
    return "e";
}
double e::oblicz(){
    return wartosc;
}
e::e(){
    this->wartosc=2.71828182845;
    prio=-1;
}
string fi::pisz(){
    return "φ";
}
double fi::oblicz(){
    return wartosc;
}
fi::fi(){
    this->wartosc=1.61803398874;
    prio=-1;
}
zmienna::zmienna(string nazwa, double wartosc){
nazwa_zmiennej=nazwa;
zbior.push_back(make_pair(nazwa,wartosc));
}
string zmienna::pisz(){
return nazwa_zmiennej;
}
double zmienna::oblicz(){
    for(int i{0}; i < zmienna::zbior.size(); i++){
        if (zmienna::zbior[i].first == nazwa_zmiennej){
            return zmienna::zbior[i].second;
        }
    }return 0;
}
Sin::Sin(wyrazenie *k){
    wyr=k;
    prio=-1;
}
string Sin::pisz(){
return "sin" + wyr->pisz();
}
double Sin::oblicz(){
    return sin(wyr->oblicz());
}
Cos::Cos(wyrazenie *k){
    wyr=k;
    prio=-1;
}
string Cos::pisz(){
return "cos" + wyr->pisz();
}
double Cos::oblicz(){
    return cos(wyr->oblicz());
}
odwrot::odwrot(wyrazenie *k){
    wyr=k;
    prio=-1;
}
string odwrot::pisz(){
    return "1/" + wyr->pisz();
}
double odwrot::oblicz(){
    return 1/(wyr->oblicz());
}
Exp::Exp(wyrazenie *k){
    wyr=k;
    prio=-1;
}
string Exp::pisz(){
return "exp(" + wyr->pisz()+")";
}
double Exp::oblicz(){
    return exp(wyr->oblicz());
}
przeciw::przeciw(wyrazenie *k){
    wyr=k;
    prio=-1;
}
string przeciw::pisz(){
return "-" + wyr->pisz();
}
double przeciw::oblicz(){
    return -1*(wyr->oblicz());
}
ln::ln(wyrazenie *k){
    wyr=k;
    prio=-1;
}
string ln::pisz(){
return "ln" + wyr->pisz();
}
double ln::oblicz(){
    return log(wyr->oblicz());
}
bezw::bezw(wyrazenie *k){
    wyr=k;
    prio=-1;
}
string bezw::pisz(){
return "|" + wyr->pisz()+"|";
}
double bezw::oblicz(){
    return abs(wyr->oblicz());
}
operatorbin::operatorbin(wyrazenie *l, wyrazenie *p){
    lewe = l; prawe = p;
}
dodaj::dodaj(wyrazenie *l, wyrazenie *p):operatorbin(l, p){
    this->laczne=1;
    this->prio=1;
}
double dodaj::oblicz(){
return lewe->oblicz()+prawe->oblicz();
}
string dodaj::pisz(){
    string l,p;
    if((lewe->prio == -1) || (lewe->prio > this->prio)) {
        l = lewe->pisz();
    }else
    if(lewe->prio<this->prio){
        l = "(" + lewe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        l = lewe->pisz();
    }else
    {
        l = "(" + lewe->pisz() + ")";
    }
    if((prawe->prio == -1) || (prawe->prio > this->prio)) {
        p = prawe->pisz();
    }else
    if(prawe->prio<this->prio){
        p = "(" + prawe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        p = prawe->pisz();
    }else
    {
        p = "(" + prawe->pisz() + ")";
    }
    return l+"+"+p;
}
odejmij::odejmij(wyrazenie *l, wyrazenie *p):operatorbin(l, p){
    this->laczne=1;
    this->prio=1;
}
double odejmij::oblicz(){
return lewe->oblicz()-prawe->oblicz();
}
string odejmij::pisz(){
    string l,p;
    if((lewe->prio == -1) || (lewe->prio > this->prio)) {
        l = lewe->pisz();
    }else
    if(lewe->prio<this->prio){
        l = "(" + lewe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        l = lewe->pisz();
    }else
    {
        l = "(" + lewe->pisz() + ")";
    }
    if((prawe->prio == -1) || (prawe->prio > this->prio)) {
        p = prawe->pisz();
    }else
    if(prawe->prio<this->prio){
        p = "(" + prawe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        p = prawe->pisz();
    }else
    {
        p = "(" + prawe->pisz() + ")";
    }
    return l+"-"+p;
}
mnoz::mnoz(wyrazenie *l, wyrazenie *p):operatorbin(l, p){
    this->laczne=1;
    this->prio=2;
}
double mnoz::oblicz(){
return lewe->oblicz()*prawe->oblicz();
}
string mnoz::pisz(){
    string l,p;
    if((lewe->prio == -1) || (lewe->prio > this->prio)) {
        l = lewe->pisz();
    }else
    if(lewe->prio<this->prio){
        l = "(" + lewe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        l = lewe->pisz();
    }else
    {
        l = "(" + lewe->pisz() + ")";
    }
    if((prawe->prio == -1) || (prawe->prio > this->prio)) {
        p = prawe->pisz();
    }else
    if(prawe->prio<this->prio){
        p = "(" + prawe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        p = prawe->pisz();
    }else
    {
        p = "(" + prawe->pisz() + ")";
    }
    return l+"*"+p;
}
dziel::dziel(wyrazenie *l, wyrazenie *p):operatorbin(l, p){
    this->laczne=1;
    this->prio=2;
}
double dziel::oblicz(){
return lewe->oblicz()/prawe->oblicz();
}
string dziel::pisz(){
    string l,p;
    if((lewe->prio == -1) || (lewe->prio > this->prio)) {
        l = lewe->pisz();
    }else
    if(lewe->prio<this->prio){
        l = "(" + lewe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        l = lewe->pisz();
    }else
    {
        l = "(" + lewe->pisz() + ")";
    }
    if((prawe->prio == -1) || (prawe->prio > this->prio)) {
        p = prawe->pisz();
    }else
    if(prawe->prio<this->prio){
        p = "(" + prawe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        p = prawe->pisz();
    }else
    {
        p = "(" + prawe->pisz() + ")";
    }
    return l+"/"+p;
}
Pot::Pot(wyrazenie *l, wyrazenie *p):operatorbin(l, p){
    this->laczne=0;
    this->prio=3;
}
double Pot::oblicz(){
return pow(lewe->oblicz(),prawe->oblicz());
}
string Pot::pisz(){
    string l,p;
    if((lewe->prio == -1) || (lewe->prio > this->prio)) {
        l = lewe->pisz();
    }else
    if(lewe->prio<this->prio){
        l = "(" + lewe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        l = lewe->pisz();
    }else
    {
        l = "(" + lewe->pisz() + ")";
    }
    if((prawe->prio == -1) || (prawe->prio > this->prio)) {
        p = prawe->pisz();
    }else
    if(prawe->prio<this->prio){
        p = "(" + prawe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        p = prawe->pisz();
    }else
    {
        p = "(" + prawe->pisz() + ")";
    }
    return l+"^"+p;
}
Log::Log(wyrazenie *l, wyrazenie *p):operatorbin(l, p){
    this->laczne=0;
    this->prio=3;
}
double Log::oblicz(){
return log(lewe->oblicz()+prawe->oblicz());
}
string Log::pisz(){
    string l,p;
    if((lewe->prio == -1) || (lewe->prio > this->prio)) {
        l = lewe->pisz();
    }else
    if(lewe->prio<this->prio){
        l = "(" + lewe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        l = lewe->pisz();
    }else
    {
        l = "(" + lewe->pisz() + ")";
    }
    if((prawe->prio == -1) || (prawe->prio > this->prio)) {
        p = prawe->pisz();
    }else
    if(prawe->prio<this->prio){
        p = "(" + prawe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        p = prawe->pisz();
    }else
    {
        p = "(" + prawe->pisz() + ")";
    }
    return "log("+l+","+p+")";
}
Mod::Mod(wyrazenie *l, wyrazenie *p):operatorbin(l, p){
    this->laczne=0;
    this->prio=2;
}
double Mod::oblicz(){
return int(lewe->oblicz())%int(prawe->oblicz());
}
string Mod::pisz(){
    string l,p;
    if((lewe->prio == -1) || (lewe->prio > this->prio)) {
        l = lewe->pisz();
    }else
    if(lewe->prio<this->prio){
        l = "(" + lewe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        l = lewe->pisz();
    }else
    {
        l = "(" + lewe->pisz() + ")";
    }
    if((prawe->prio == -1) || (prawe->prio > this->prio)) {
        p = prawe->pisz();
    }else
    if(prawe->prio<this->prio){
        p = "(" + prawe->pisz() + ")";
    }
    else
    if(this->laczne == 1){
        p = prawe->pisz();
    }else
    {
        p = "(" + prawe->pisz() + ")";
    }
    return l+"%"+p;
}
