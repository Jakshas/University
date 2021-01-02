#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

void funkcja(double a, double b, double n){
    if (n>15)
    {
        return;
    }
    double oszacowanie = pow(2,-n-1)*(b-a);
    double x = (a+b)/2;
    double wartosc=x*exp(x)-0.06064;
    cout<<n<<" "<<oszacowanie<<" "<<0.0646926359947960-x<<endl;
    if (wartosc*(x*exp(x)-0.06064)>0)
    {
        funkcja(a,x,n+1);
    }else
    {
        funkcja(x,b,n+1);
    }
}

int main(int argc, char const *argv[])
{
    funkcja(0,1,0);
    return 0;
}

