#include <iostream>
using namespace std;

int wyrazenie(int a){
    if (a<0)
    {
        cerr << "zły argument";
        return -1;
    }
    if (a<2)
    {
        return 1;
    }
    if (a%2 != 0)
    {
        a--;
    }
    int wynik = 1;
    for (;a > 1; a = a - 2)
    {
        int b = wynik;
        wynik = wynik * a;
        if(wynik/a == b)
            return -1;
    }
    return wynik;
}

int main(int argc, char const *argv[])
{
    cout << wyrazenie(20) << endl;
    cout << wyrazenie(6) << endl;
    cout << wyrazenie(1) << endl;
    cout << wyrazenie(0) << endl;
    cout << wyrazenie(-1) << endl;
    return 0;
}
