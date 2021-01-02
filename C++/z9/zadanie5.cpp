#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

int main() {
    string linia;
    smatch lacze;
    ifstream file("test.html");
    string wynik;
    regex reg(R"(<a +href *= *".*" *> *)");
    while (getline(file,linia))
    {
        wynik=wynik+linia;
    }
    while (regex_search(wynik,lacze, reg))
    {
        wynik= wynik.substr(lacze.position());
        linia= wynik.substr(wynik.find('\"') + 1);
        wynik=wynik.substr(wynik.find('>') + 1);
        cout<< linia.substr(0, linia.find('\"'))<<endl;
    }
}
//istreambuf