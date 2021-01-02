#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    regex reg("^([0-1]?[0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?$");
    string a= "12:20:03";
    string b= "12:20";
    string c="12:80";
    cout << regex_match(a, reg)<<endl;
    cout << regex_match(b, reg)<<endl;
    cout << regex_match(c, reg)<<endl;
}