#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double szukaj(double a,double x0,int ile){
    double x=x0-((1/pow(x0,2))-a)/(-2/pow(x0,3));
    if (abs(x0-x)>0.00001)
    {
        return szukaj(a,x,ile+1);
    }else
    {
        cout<<ile<<" ";
        return x;
    }
}

int main(int argc, char const *argv[])
{
    cout<<szukaj(4,0.5,0)<<endl;
    cout<<szukaj(9,0.5,0)<<endl;
    cout<<szukaj(2,0.5,0)<<endl;
    cout<<szukaj(0.25,0.5,0)<<endl;
    return 0;
}