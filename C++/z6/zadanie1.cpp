#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class person{
    public:
    string imie;
    string nazwisko;
    int wiek;
    double waga;
    double wzrost;

    person(string imie,string nazwisko,int wiek,double waga,double wzrost):imie(imie),nazwisko(nazwisko),wiek(wiek),waga(waga),wzrost(wzrost) {}
    friend ostream& operator<<(ostream& os, person per)
        {
            return os << per.imie << " " << per.nazwisko << " " << per.wiek << " " << per.waga << " " << per.wzrost << '\n';
        }

};

void pisz(deque<person>& inp)
{
    for(auto x : inp)
    {
        cout << x << endl;
    }
}

void BMI(deque<person>& inp)
{
    sort(inp.begin(), inp.end(), [] (const person& a, const person& b) { return a.waga/(a.wzrost) < b.waga/(b.wzrost);} );
    pisz(inp);
}

void schudli(deque<person>& inp)
{
    transform(inp.begin(), inp.end(), inp.begin(), [] (person a) { return person(a.imie, a.nazwisko, a.wiek, a.waga *= 0.9, a.wzrost); } );
    pisz(inp);
}

void podziel(deque<person>& inp)
{
    partition(inp.begin(), inp.end(), [] (person a) { return a.waga > 100; });
    pisz(inp);
}

void srodkowa(deque<person>& inp){
    nth_element(inp.begin(),inp.begin() + inp.size() / 2, inp.end(), [](const person& a, const person& b) { return a.wzrost < b.wzrost; });
    pisz(inp);
}

void minmax(deque<person>& inp)
{
    auto it = minmax_element(inp.cbegin(), inp.cend(), [] (const person& a, const person& b) { return a.wiek < b.wiek; });
    cout << *it.first;
    cout << *it.second;
}

void losowe(deque<person>& inp)
{
    random_shuffle(inp.begin(), inp.end() - 5);
    random_shuffle(inp.end() - 5, inp.end());
    pisz(inp);
}


int main(int argc, char const *argv[])
{
    deque<person> deq;
    deq.push_back(person("A", "B", 71, 60, 167));
    deq.push_back(person("C", "D", 52, 324, 175));
    deq.push_back(person("E", "F", 60, 150, 200));
    deq.push_back(person("G", "H", 343, 300, 300));
    deq.push_back(person("I", "J", 44, 224, 90));
    deq.push_back(person("K", "L", 37, 69, 174));
    deq.push_back(person("M", "N", 111, 65, 178));
    deq.push_back(person("O", "P", 77, 95, 179));
    deq.push_back(person("R", "S", 21, 323, 163));
    deq.push_back(person("T", "U", 222, 32, 140));
    deq.push_back(person("W", "X", 544, 656, 120));

    cout << "a" <<endl;
    BMI(deq);
    cout << "b" << endl;
    schudli(deq);
    cout <<"c" << endl;
    podziel(deq);
    cout << "e" <<endl;
    minmax(deq);
    cout <<"f" << endl;
    losowe(deq);

    return 0;
}
