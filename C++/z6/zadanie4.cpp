#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;


string dos(istream& stm )
{
    string str ;
    char c ;
    while( stm.get(c) ) str += c ;
    return str ;
}

int main(int argc, const char *argv[])
{
    ifstream plik(argv[1]);
    string text = dos(plik);

    int wszystkie = count_if(text.begin(), text.end(), [] (const char& let) {return (let >= 'a' && let <= 'z') || (let >= 'A' && let <= 'Z'); });
    for(char i='a'; i <= 'z'; i++)
    {
        double literka = count_if(text.begin(), text.end(), [&] (char& l) { return tolower(l) == i; });
        cout << i << ": " << literka/wszystkie << ";" << endl;
    }
}