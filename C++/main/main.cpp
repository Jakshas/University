#include <iostream>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
using namespace std;

int main()
{string morse="---.. ....- \0",morse2="--... ----. \0",morse3="--... ....-  \0",morse4="-.... ----. \0",morse5="---.. ...-- \0",morse6="---.. ....- \0",morse7="--... ..---  \0",morse8="--... ----. \0",morse9="---.. ...- \0";
string morset[9]={morse,morse2,morse3,morse4,morse5,morse6,morse7,morse8,morse9},hasl;
int kod[9]={84,79,74,69,83,84,72,79,84},guess;
char haslo[20];

    for(int i=0;i<9;)
        {
        for(int k=0;morset[i][k]!='\0';k++)
        {
            cout<<morset[i][k];
           // Sleep(30);

        }
        cout<<endl;
        cout<<"Haslo: ";
        cin>>guess;

        if(guess==kod[i])
        {
            i++;


        }
        else
        {
            cout<<"Nope"<<endl;
        }
        }
        cout<<"Poprawna kombinacja"<<endl;
        cout<<"Wcisnij dowolny klawisz"<<endl;
        getch();
        system("cls");
        cout<<"ASK CAPTAIN ABOUT ANY INTERESTING OR INTELLIGENT APPROACH"<<endl;
        cout<<"Haslo: ";
         for(;;)
         {
             cin>>hasl;
             if(hasl=="ASCII")
                break;
         }
        cout<<"Kod: 84 79 74 69 83 84 72 79 84"<<endl;
        cout<<"Uzyj odpowiedzi :P"<<endl;
        for(;;)
        {
            getline(cin,hasl);
        if(hasl=="TO JEST HOT"||hasl=="TOJESTHOT")
            break;
            cout<<"Nope"<<endl;
        }
        cout<<"Yay, udalo Ci sie ^^"<<endl;
    return 0;
}
