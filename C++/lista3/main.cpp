//Jakub Szajner Lista 3
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const vector<pair<int, string>> rzym = {{1000, "M"},
    {900, "CM"}, {500, "D"}, {400, "CD"},{100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
    {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

string bin2rom (int x){
    string wynik="";
    for(int i=0;i<13;i++){
    while(x>=rzym[i].first){
        wynik=wynik+rzym[i].second;
        x=x-rzym[i].first;
        }
    }
    return wynik;
}
int x=rzym[1].first;
int main(int argc, char **argv){
    try{
    if(argc<2){
        string wyjatek="za mało argumentow";
        throw wyjatek;
    }
    for(int i=1;i<argc;i++){
        if(stoi(argv[i])){
        int wartosc=stoi(argv[i]);
        if(wartosc<1||wartosc>3999){
            string wyjatek="wartosc z poza przedzialu";
            throw wyjatek;
        }else
        {
        cout<< bin2rom(wartosc)<<endl;
        } 
    }else
    {
        string wyjatek="nie udalo sie zaminic liczby";
        throw wyjatek;
    }
    
    }
}
catch(string a){
    cout<<"Funkcja zwróciła bład:"<<a<<endl;
}}