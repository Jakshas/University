#include <iostream>
#include <ctime>
using namespace std;
int main(int argc, char const *argv[])
{   
    time_t now = time(0);
    tm *dataa=gmtime(&now);
    switch (int miesiac=dataa->tm_mon)
    {
    case 0:
        cout<<dataa->tm_mday<<" stycznia "<<dataa->tm_year+1900;
        break;
    case 1:
        cout<<dataa->tm_mday<<" lutego "<<dataa->tm_year+1900;
        break;
    case 2:
        cout<<dataa->tm_mday<<" marca "<<dataa->tm_year+1900;
        break;
    case 3:
        cout<<dataa->tm_mday<<" kwietnia "<<dataa->tm_year+1900;
        break;
    case 4:
        cout<<dataa->tm_mday<<" maja "<<dataa->tm_year+1900;
        break;
    case 5:
        cout<<dataa->tm_mday<<" czerwca "<<dataa->tm_year+1900;
        break;
    case 6:
        cout<<dataa->tm_mday<<" lipca "<<dataa->tm_year+1900;
        break;
    case 7:
        cout<<dataa->tm_mday<<" sierpnia "<<dataa->tm_year+1900;
        break;
    case 8:
        cout<<dataa->tm_mday<<" września "<<dataa->tm_year+1900;
        break;
    case 9:
        cout<<dataa->tm_mday<<" pażdziernika "<<dataa->tm_year+1900;
        break;
    case 10:
        cout<<dataa->tm_mday<<" listopada "<<dataa->tm_year+1900;
        break;
    case 11:
        cout<<dataa->tm_mday<<" grudnia "<<dataa->tm_year+1900;
        break;
    
    default:
        break;
    }
    return 0;
}
