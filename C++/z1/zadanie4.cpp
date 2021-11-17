#include <iostream>
using namespace std;
enum class Imiona: uint16_t
    {
        Jakub,
        Kacper,
        Oliwia,
        Damian
    };  
    void function(string s, Imiona i);
int main(int argc, char const *argv[])
{
    string s="witaj";
    function(s,Imiona::Jakub);
    return 0;
}
void function(string s, Imiona i){
    switch (i)
    {
    case Imiona::Jakub:
        cout<<"Jakubie, "<<s;
        break;
        case Imiona::Kacper:
        cout<<"Kacprze, "<<s;
        break;
            case Imiona::Oliwia:
        cout<<"Oliwio, "<<s;
        break;
            case Imiona::Damian:
        cout<<"Damianie, "<<s;
        break;
        
    default:
        break;
    }
}
