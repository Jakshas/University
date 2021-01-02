#include "stos.hpp"
#include <string>

using namespace std;
int main(){
    stos stosik=stos({"a","s","d"});
    while(1>0){
        cout<<"co chcesz zrobic z kopcem wpisz(a: utwurz stos,  b:dodaj , c: usun ,s: sprawdz, z zakończ)"<<endl;
        char co;
        cin>>co;
        if(co=='a'){
            cout<<"podaj pojemnosc: ";
        int ile;
        cin>>ile;
        stosik=stos(ile);
        cout<<endl;
        }
        if(co=='b'){
            string slowo;
            cout<<"podaj słowo:";
            cin>>slowo;
            cout<<endl;
            stosik.wluz(slowo);
        }
        if(co=='c'){
            cout<<"usuniete słowo: "<< stosik.sciagnij();
            cout<<endl;
        }
        if(co=='s'){
            string s=stosik.sprawdz();
            cout<<"sprawdzone słowo: ";
            cout<<s;
            cout<<endl;
        }
        if(co=='z'){
            break;
        }
    }
}