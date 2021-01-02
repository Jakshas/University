//Jakub Szajner
#include <iostream>
#include <cmath>
#include <string>
#include <vector>


using namespace std;

int64_t zmien(string slowo){
    int64_t dl=slowo.length();
    int64_t wartosc=0;
    int64_t znak=1;
    if(slowo.front()=='-'){
        dl=dl-1;
        znak=-1;
    }
    int64_t razy= 1;
    for(int i=0;i<dl;i++){
        char literka=slowo.back();
        slowo.pop_back();
        int64_t lit=literka-'0';
        wartosc=wartosc+lit*razy;
        razy=razy*10;
    }
    wartosc=wartosc*znak;
    return wartosc;
}

bool czypierwsza(int64_t x)
{
    int64_t y=sqrt(x);
    if(x%2==0){
                    return false;
                }
for(int64_t j=3; j<=y; j=j+2)
            {
                if(x%j==0){
                    return false;
                }
            }
            return true;
}
void wypisz(vector<int64_t> wart){
    cout<<wart.at(0)<<" = ";
    wart.erase(wart.begin());
    for(int64_t x: wart){
    cout<<x<<" * ";
    }
    cout<<'\b';
    cout<<'\b';
    cout<<" ";
}
vector<int64_t> rozluz( char *argv[],int64_t i){
    vector<int64_t> wart;
        if(!atol(argv[i]))
        {
            cerr<<"blad"<<endl;
        }
        else
        {
            int64_t liczba =zmien(argv[i]);
            wart.push_back(liczba);
            if(czypierwsza(liczba)){
                wart.push_back(liczba);
            }else{
            if(liczba<0)
            {
                wart.push_back(-1);
                liczba=liczba*(-1);
            }
            int64_t granica=liczba/2;
            int64_t y=sqrt(liczba);
            while(liczba%2==0)
                {
                    wart.push_back(2);
                    liczba=liczba/2;
                }
            for(int64_t j=3; j<=y; j=j+2)
            {
                while(liczba%j==0)
                {
                    wart.push_back(j);
                    liczba=liczba/j;
                }
            }
            if(liczba>1){
                wart.push_back(liczba);
            }
        }}
    return wart;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        cerr << "wpisz liczbe jako argument funckji" << endl;
    }
    for(int i=1;i<argc;i++){
    vector<int64_t> wart =rozluz(argv,i);
    wypisz(wart);
    cout<<endl;
    }
    return 0;
}
