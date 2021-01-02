#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
// Z szkiców widzimy ze miejsca zeriowe to bedą około -0.8 i 0.2
double funkcja(double a, double b){
    double x = (a+b)/2;
    double wartosc=(x*x)-(2*cos((3*x)+1));
    if(abs(b-a)<0.00001){
        return x;
    }
    if (wartosc*((b*b)-(2*cos((3*b)+1)))<0)
    {
        return funkcja(x,b);
    }
    else
    {
        return funkcja(a,x);
    }

}


int main(int argc, char const *argv[])
{
    cout<<funkcja(-0.8,-0.7)<<endl;
    cout<<funkcja(0.1,0.3)<<endl;
    return 0;
}
