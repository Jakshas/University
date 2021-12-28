#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {        
    regex reg("^(([0-2][1-9]|3[0-1])-(01|03|05|07|08|10|12)-{?!0000}[0-9]{4})|([0-2][1-9]-02-{?!0000}[0-9]{4})|(([0-2][1-9]|30)-(04|06|09|12)-{?!0000}[0-9]{4})$");
    string a="01-03-2020";
    string b="30-02-2020";
    string c="32-03-2020";
    string d="31-12-2020";
    cout << regex_match(a, reg);
    cout << regex_match(b, reg);
    cout << regex_match(c, reg);
    cout << regex_match(d, reg);
}