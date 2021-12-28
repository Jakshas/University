#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <utility>
#include <stack>
#include <map>

using namespace std;

class Graf
{
    public:
        vector<pair<int,vector<pair<int,double>>>> tab;
        map<string,int> mapa;
        int iloscw=0;
        Graf(){

        }
        void dodajwierzcholek(int w){
            for (auto &&i : tab)
            {
                if (i.first==w)
                {
                    return;
                }
            }
            tab.push_back(pair<int,vector<pair<int,double>>>(w ,vector<pair<int,double>>()));
            iloscw++;
        }
        void dodajwierzcholek(int i,string s){
            mapa.insert(pair<string,int>(s,i));
            dodajwierzcholek(i);
        }
        int wyszukaj(int ii){
            for (auto &&i : tab)
            {
                if (i.first==ii)
                {
                    return i.first;
                }
            }
            return -1;
        }
        int wyszukaj(string ii){
            return wyszukaj(mapa.find(ii)->second);
        }


        void dodajkrawedz(int a, int b, double waga){
            for (auto &&i : tab)
            {
                if (i.first==a)
                {
                    for (auto &&j : i.second)
                    {
                        if (j.first==b)
                        {
                            return;
                        }
                    }
                    i.second.push_back(pair<int,double>(wyszukaj(b),waga));
            }
        }
        for (auto &&i : tab)
            {
                if (i.first==b)
                {
                    for (auto &&j : i.second)
                    {
                        if (j.first==a)
                        {
                            return;
                        }
                    }
                    i.second.push_back(pair<int,double>(wyszukaj(a),waga));
            }
        }
    }
        void dodajkrawedz(string a, int b, double waga){
            dodajkrawedz(mapa.find(a)->second,b,waga);
        }
        void dodajkrawedz(int a, string b, double waga){
            dodajkrawedz(a,mapa.find(b)->second,waga);
        }
        void dodajkrawedz(string a, string b, double waga){
            dodajkrawedz(mapa.find(a)->second,mapa.find(b)->second,waga);
        }
    void usunwierzcholek(int dana){
        int iter=0;
        for (auto &&i : tab){
            auto pom=i.first;
            if (pom == dana){
                tab.erase(tab.begin()+iter);
            }
            int joter=0;
                for (auto &&j : i.second)
                {
                    auto pom2=j.first;
                    if (pom2 == dana){
                        i.second.erase(i.second.begin()+joter);
                    }
                    joter++;
                }
            iter++;
        }
        iloscw--;
    }

    void usunwierzcholek(string dana){
            usunwierzcholek(mapa.find(dana)->second);
            mapa.erase(dana);
    }


    void usunkrawedz(int a , int b){
        for (auto &&i : tab){
            auto pom=i.first;
            if (pom == a){
                int joter=0;
                for (auto &&j : i.second)
                {
                    auto pom2=i.first;
                    if (pom2 == b){
                        i.second.erase(i.second.begin()+joter);
                    }
                    joter++;
                }}
        }
    }
        void usunkrawedz(string a, int b){
            usunkrawedz(mapa.find(a)->second,b);
        }
        void usunkrawedz(int a, string b){
            usunkrawedz(a,mapa.find(b)->second);
        }
        void usunkrawedz(string a, string b){
            usunkrawedz(mapa.find(a)->second,mapa.find(b)->second);
        }

    
    void zmienwage(int a , int b,double waga){
        for (auto &&i : tab){
            auto pom=i.first;
            if (pom == a){
                for (auto &&j : i.second)
                {
                    auto pom2=i.first;
                    if (pom2 == b){
                        j.second=waga;
                    }
                }
            }
        }
    }
        void zmienwage(string a, int b, double waga){
            zmienwage(mapa.find(a)->second,b,waga);
        }
        void zmienwage(int a, string b, double waga){
            zmienwage(a,mapa.find(b)->second,waga);
        }
        void zmienwage(string a, string b, double waga){
            zmienwage(mapa.find(a)->second,mapa.find(b)->second,waga);
        }

bool czysciezka(int ai,int bi){      
        stack<int> stos;
        bool wisited[iloscw];
        for (auto &&i : wisited)
        {
            i=false;
        }
        stos.push(ai);
        int aktualny;
        wisited[ai]=true;
        while (stos.empty()==false)
        {
            aktualny=stos.top();
            stos.pop();
            if (aktualny==bi)
            {
                return true;
            }
            for (auto &&uw : tab[aktualny].second)
            {
                int u=uw.first;
                if(wisited[u]==true){

                }else
                {
                    stos.push(u);
                    wisited[u]==true;
                }
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Graf * g=new Graf();
    g->dodajwierzcholek(0,"s");
    g->dodajwierzcholek(1,"p");
    g->dodajwierzcholek(2,"d");
    g->dodajkrawedz(0,1,1);
    g->dodajkrawedz(1,2,1);
    g->zmienwage(0,1,2);
    cout<<(g->czysciezka(2,0)?"T":"F");
    return 0;
}

// Zmieniłem implementacje wierzchołka z klasy na inty z mapa