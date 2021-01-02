#include "zadanie.hpp"
using namespace std;


tab_bit::tab_bit(int rozm)
{
    tab= new slowo[(rozm-1)/rozmiarSlowa+1];
    dl = rozm;
    for(int i=0;i<(dl-1)/rozmiarSlowa+1;i++){
        tab[i]=0;
    }
}
tab_bit::tab_bit(slowo tb)
{
    tab= new slowo[1];
    dl = 64;
    tab[0]=tb;
}
tab_bit::ref::ref(int bit1, tab_bit *tab){
    ktore=&tab->tab[bit/rozmiarSlowa];
    bit=bit1%rozmiarSlowa;}
tab_bit::ref & tab_bit::ref::operator= (const int &tb)
{
    if(tb<=1){
        *ktore=(*ktore | (1<<bit));
    }else
    {
        *ktore=(*ktore & !(1<<bit));
    }
    return *this;
}
tab_bit::ref & tab_bit::ref::operator= (const ref &tb)
{
    if((*tb.ktore & (1<<bit)) != 0){
        *ktore= (*ktore | (1<<bit));
    }else
    {
        *ktore= (*ktore & (!(1<<bit)));
    }
    return *this;
}
tab_bit::ref & tab_bit::ref::operator= (const bool &tb)
{
    if(tb){
        *ktore= (*ktore | (1<<bit));
    }else
    {
        *ktore= (*ktore & !(1<<bit));
    }
    return *this;
}
tab_bit::tab_bit (const tab_bit &tb){
    dl = tb.dl;
    slowo *tabli=new slowo[(dl-1)/rozmiarSlowa+1];
    for(int i=0;i<(dl-1)/rozmiarSlowa+1;i++){
        tabli[i]=tb.tab[i];
    }
}
tab_bit::tab_bit (tab_bit &&tb){
    tab=tb.tab;
    dl = tb.dl;
}
tab_bit & tab_bit::operator= (const tab_bit &tb)
{
    this->dl=tb.dl;
    tab=new slowo[(dl-1)/rozmiarSlowa+1];
    for(int i=0;i<(dl-1)/rozmiarSlowa+1;i++){
        tab[i]=tb.tab[i];
    }
    return *this;
}
tab_bit & tab_bit::operator= (tab_bit &&tb)
{
    if(&tb==this) 
    return *this;
    this->~tab_bit();
    return *this;
}
tab_bit::~tab_bit(){
    delete this;
}
bool tab_bit::czytaj (int i) const{
    int dlll = i/rozmiarSlowa;
    i=i%rozmiarSlowa;
    slowo s=tab[dlll];
    return (s & (1<<i)) != 0;
};
bool tab_bit::pisz(int i, bool b){
    int dlll = i/rozmiarSlowa;
    i=i%rozmiarSlowa;
    if(b){
        tab[dlll]=(tab[dlll] | (1<<i));
    }else
    {
        tab[dlll]=(tab[dlll] & (!(1<<i)));
    }
    return true;
}
bool tab_bit::operator[] (int i) const{
    return this->czytaj(i);
}
tab_bit::ref & tab_bit::operator[] (int &tb){
    ref r(tb,this);
    return r;
}
int tab_bit::rozmiar () const{
    return dl;
}
tab_bit tab_bit::operator|(tab_bit a){ 
    int dll;
    if(this->rozmiar()>a.rozmiar()){
        dll=this->rozmiar();
        slowo *t=a.tab;
        a.tab=new slowo[dll];
        for(int i=0;i<(a.dl-1)/rozmiarSlowa+1;i++){
            a.tab[i]=t[i];
        }
        a.dl=dll;
    }else
    {
        dll=a.rozmiar();
        slowo *t=this->tab;
        this->tab=new slowo[dll];
        for(int i=0;i<(this->dl-1)/rozmiarSlowa+1;i++){
            this->tab[i]=t[i];
        }
        this->dl=dll;
    }
    tab_bit t(dll);
    for(int i=0;i<(dll-1)/rozmiarSlowa+1;i++){
        t.tab[i]=this->tab[i]|a.tab[i];
    }
    return t;
}
tab_bit tab_bit::operator&(tab_bit a){ 
    int dll;
    if(this->rozmiar()>a.rozmiar()){
        dll=this->rozmiar();
        slowo *t=a.tab;
        a.tab=new slowo[dll];
        for(int i=0;i<(a.dl-1)/rozmiarSlowa+1;i++){
            a.tab[i]=t[i];
        }
        a.dl=dll;
    }else
    {
        dll=a.rozmiar();
        slowo *t=this->tab;
        this->tab=new slowo[dll];
        for(int i=0;i<(this->dl-1)/rozmiarSlowa+1;i++){
            this->tab[i]=t[i];
        }
        this->dl=dll;
    }
    tab_bit t(dll);
    for(int i=0;i<(dll-1)/rozmiarSlowa+1;i++){
        t.tab[i]=this->tab[i]&a.tab[i];
    }
    return t;
}
tab_bit tab_bit::operator&=(tab_bit a){ 
    int dll;
    if(this->rozmiar()>a.rozmiar()){
        dll=this->rozmiar();
        slowo *t=a.tab;
        a.tab=new slowo[dll];
        for(int i=0;i<(a.dl-1)/rozmiarSlowa+1;i++){
            a.tab[i]=t[i];
        }
        a.dl=dll;
    }else
    {
        dll=a.rozmiar();
        slowo *t=this->tab;
        this->tab=new slowo[dll];
        for(int i=0;i<(this->dl-1)/rozmiarSlowa+1;i++){
            this->tab[i]=t[i];
        }
        this->dl=dll;
    }
    tab_bit t(dll);
    for(int i=0;i<(dll-1)/rozmiarSlowa+1;i++){
        t.tab[i]=this->tab[i]&a.tab[i];
    }
    this->tab=t.tab;
    this->dl=t.dl;
    return *this;
}
tab_bit tab_bit::operator|=(tab_bit a){ 
    int dll;
    if(this->rozmiar()>a.rozmiar()){
        dll=this->rozmiar();
        slowo *t=a.tab;
        a.tab=new slowo[dll];
        for(int i=0;i<(a.dl-1)/rozmiarSlowa+1;i++){
            a.tab[i]=t[i];
        }
        a.dl=dll;
    }else
    {
        dll=a.rozmiar();
        slowo *t=this->tab;
        this->tab=new slowo[dll];
        for(int i=0;i<(this->dl-1)/rozmiarSlowa+1;i++){
            this->tab[i]=t[i];
        }
        this->dl=dll;
    }
    tab_bit t(dll);
    for(int i=0;i<(dll-1)/rozmiarSlowa+1;i++){
        t.tab[i]=this->tab[i]|a.tab[i];
    }
    this->tab=t.tab;
    this->dl=t.dl;
    return *this;
}
tab_bit tab_bit::operator^(tab_bit a){ 
    int dll;
    if(this->rozmiar()>a.rozmiar()){
        dll=this->rozmiar();
        slowo *t=a.tab;
        a.tab=new slowo[dll];
        for(int i=0;i<(a.dl-1)/rozmiarSlowa+1;i++){
            a.tab[i]=t[i];
        }
        a.dl=dll;
    }else
    {
        dll=a.rozmiar();
        slowo *t=this->tab;
        this->tab=new slowo[dll];
        for(int i=0;i<(this->dl-1)/rozmiarSlowa+1;i++){
            this->tab[i]=t[i];
        }
        this->dl=dll;
    }
    tab_bit t(dll);
    for(int i=0;i<(dll-1)/rozmiarSlowa+1;i++){
        t.tab[i]=this->tab[i]^a.tab[i];
    }
    return t;
}
tab_bit tab_bit::operator^=(tab_bit a){ 
    int dll;
    if(this->rozmiar()>a.rozmiar()){
        dll=this->rozmiar();
        slowo *t=a.tab;
        a.tab=new slowo[dll];
        for(int i=0;i<(a.dl-1)/rozmiarSlowa+1;i++){
            a.tab[i]=t[i];
        }
        a.dl=dll;
    }else
    {
        dll=a.rozmiar();
        slowo *t=this->tab;
        this->tab=new slowo[dll];
        for(int i=0;i<(this->dl-1)/rozmiarSlowa+1;i++){
            this->tab[i]=t[i];
        }
        this->dl=dll;
    }
    tab_bit t(dll);
    for(int i=0;i<(dll-1)/rozmiarSlowa+1;i++){
        t.tab[i]=this->tab[i]^a.tab[i];
    }
    this->tab=t.tab;
    this->dl=t.dl;
    return *this;
}
tab_bit tab_bit::operator!(){
    for(int i=0;i<this->dl;i++){
        this->tab[i]=!this->tab[i];
    }
    return *this;
}
istream & operator >> (istream &we, tab_bit &tb){
    int x;
    we>>x;
    for(int i=0;i<tb.dl;i++){
            bool b;
            if(x%10==1){
                b=true;
            } else
            {
                b=false;
            }
            x=x/10;
            tb.pisz(i,b);
    }
    return we;
}
ostream & operator << (ostream &wy, const tab_bit &tb){
    string s="";
    for(int i=0;i<tb.dl;i++){
        if(tb.czytaj(i)){
            s="1"+s;}
            else
            {
                s="0"+s;
            } 
    }
    wy<<s;
    return wy;
}