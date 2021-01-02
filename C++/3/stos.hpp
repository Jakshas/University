#include <iostream>
#include <string>
using namespace std;

class stos{
    private:
    int pojemnosc;
    int ile;
    public:
    string* tablica;
    ~stos(){
        delete[] tablica;
    }
    stos(int poj){
        if(poj<=100){
        tablica=new string[poj];
        ile=0;
        pojemnosc=poj;
        }
    }
    stos(){
        stos(1);
        }
    stos(initializer_list<string> lista){
        int i=0;
        tablica=new string[lista.size()];
        for( auto it = lista.begin(); it != lista.end(); ++it ){
            tablica[i]=*it;
            i++;
        }
        ile=i;
        pojemnosc=100;
    }
    stos (stos &);
    stos & operator= (stos &st){
        pojemnosc=st.pojemnosc;
        ile=st.ile;
        tablica=new string[st.ile];
        for(int i=0;i<ile;i++){
            tablica[i]=st.tablica[i];
        }
        return *this;
    }
    stos (stos &&);
    stos & operator= (stos&& st){
        pojemnosc=st.pojemnosc;
        ile=st.ile;
        tablica=st.tablica;
        st.ile=0;
        st.pojemnosc=0;
        st.tablica=nullptr;
        return *this;
    }
    void wluz(string slowo);
    string sciagnij();
    string sprawdz();
    int rozmiar();
    stos odwroc();
};