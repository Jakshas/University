#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "merge.h"
#include "quick.h"
#include "heap.h"
#include "shell.h"

using namespace std;


//main, z jego poziomu dziala wybor sortowan od najmniejszego do najwiekszego
int main(int argc, char const *argv[])
{
    int czas = 0;//czas dzialania sorotowania
    int wybor = 0;//dla menu
    int ile_posorotowanych = 0;//w jakim stopniu psorotwane
    int przebieg = 1;//liczba przebiegow tworzenia tablic i sortowan
    int n = 0; //rozmiar tablicy

    cout << "podaj rozmiar tablicy" << endl;
    cin >> n;
    int* tab = new int[n]; //dynamiczna tablica by nie trzeba bylo
                            //zmieniac jej rozmiaru zaleznego od n
    int* tmp = new int[n]; //tablica pomocnicza dla warunku od najwiekszej do najmniejszej

    //menu % uporzadkowania
    cout << "Wybiez w jakim stopniu posortowane:"<< endl;
    cout << "25 = 25%" << endl;
    cout << "50 = 50%" << endl;
    cout << "75 = 75%" << endl;
    cout << "95 = 95%" << endl;
    cout << "99 = 99%" << endl;
    cout << "997 = 99,7%" << endl;
    cout << "0 = wszystko losowe" << endl;
    cout << "-100 = od najwiekszej do najmniejszej" << endl;
    cin >> ile_posorotowanych;
    cout << endl;
    
    //menu sortowan
    cout << "Wybiez jakie sortowanie:"<< endl;
    cout << "1.merge" << endl;
    cout << "2.quick" << endl;
    cout << "3.heap" << endl;
    cout << "4.shell" << endl;
    cin >> wybor;
    cout << endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000000);
    while(przebieg < 101)
    {   
        //zapelnienie tablicy liczbami losowymi
        for (int i = 0; i < n; i++)
        {
            tab[i] = dis(gen);
            //cout << tab[i] << " "; //wyswietlenie dla sprawzenia
        } 
        
        // sortowanie kawalka 
        switch(ile_posorotowanych)
        {
            case 25:
                quicksort(tab, 0, ((n-1)*25/100)); //sortowanie 25% poczatku
            break;
   
            case 50:
                quicksort(tab, 0, ((n-1)*50/100)); //sortowanie 50% poczatku
            break;
   
            case 75:
                quicksort(tab, 0, ((n-1)*75/100)); //sortowanie 75% poczatku
            break;
   
            case 95:
                quicksort(tab, 0, ((n-1)*95/100)); //sortowanie 95% poczatku
            break;

            case 99:
                quicksort(tab, 0, ((n-1)*99/100)); //sortowanie 99% poczatku
            break;

            case 997:
                quicksort(tab, 0, ((n-1)*997/1000)); //sortowanie 99,7% poczatku
            break;

            case 0: //wszystko losowe, brak posortowania wstepnego
            break;

            case -100:
                quicksort(tab, 0, n-1);   //sortowanie calosci
                for (int i = 0; i < n; i++) //od najwiekszej do najmniejszej
                    tmp[i] = tab[n-1-i];

                for (int i = 0; i < n; i++)
                    tab[i] = tmp[i];
            break;

            default:
            cout << "zla opcja posortwan" << endl; //jak zadne sortowanie
            return 0;
    }
        
        /*//Wyswietlenie tablicy
        cout << "wyswietlenie tablicy" << endl;
        for (int i = 0; i < n; i++)
            cout << tab[i] << " ";
        cout << endl;
        cout << endl;
        */
    
       //polecenie wybranego sortowania
       auto start = chrono::high_resolution_clock::now();//czas start
       switch(wybor)
    {
        case 1:
        mergesort(tab, 0, n - 1); //tablica, poczatek, koniec (ponieważ tablica to 0 i n-1)
        break;
   
        case 2:
        quicksort(tab, 0, n - 1); //tablica, poczatek, koniec (poniważ tablica to 0 i n-1)
        break;
   
        case 3:
        heapsort(tab, n); //tablica, rozmiar
        break;
   
        case 4:
        shell(tab, n);  //tablica rozmiar
        break;

        default:
        cout << "zla opcja" << endl; //jak zadne sortowanie
        return 0;
    }
        auto stop = chrono::high_resolution_clock::now(); //czas stop
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); //ile minelo od start do stop
        czas = czas + duration.count(); //sumowanie czasow

        //sprawdznie czy posortowane
        int max = tab[0]; //najwieksza liczba
        int miejsce = 0; //na ktorej pozycji
        for(int i = 0; i < n; i++)
        {
            if(tab[i] > max)
            {
                max = tab[i];
                miejsce = i+1; //by byla liczba z zakresu od 1 do n
            }
        }

        cout << przebieg << ". Najwieksza liczba to: " << max << endl;
        cout << przebieg << ". Wystepuje ona na pozycji: " << miejsce << endl;
        cout << endl;

        for (int i = 0; i < n; i++) //wyzeroawanie
            tab[i] = 0;
    
        przebieg++;
    }

    cout << "Czas dzialania: " << czas/(60*1000000) << " minut, "
                                << czas/1000000 << " sekund, " 
                                << czas/1000 << " milisekund, "
                                << czas << " mikrosekund, " << endl;

    return 0;
}