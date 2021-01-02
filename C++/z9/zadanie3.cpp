#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    regex reg("^([A-Z][a-z]* *)*(-[A-Z][a-z]*)?(([A-Z][a-z]*)*)?$");
    string a="Wroclaw";
    string b="Gorzow Wilkopolski";
    string c="Jeden-Dwa-Trzy";
    string d="Jeden Dwa Trzy Cztery";
    cout << regex_match(a, reg);
    cout << regex_match(b, reg);
    cout << regex_match(c, reg);
    cout << regex_match(d, reg);
}