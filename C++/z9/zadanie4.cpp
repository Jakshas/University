#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    regex reg(R"(^\( *[0-9]+(\.[0-9]+)? *\+ *[0-9]+(\.[0-9]+)?i *\)$)");
    string a="(1 + 1i)";
    string b="(2.3 +2i)";
    string c="( 1.234   + 1.23i)";
    string d="( 4.232 + 3.13)";
    cout << regex_match(a, reg);
    cout << regex_match(b, reg);
    cout << regex_match(c, reg);
    cout << regex_match(d, reg);
}