#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
double szukaj(double a,double x0,int ile){
    double x=x0-(((pow(x0,2))-a)/(2*x0));
    if (abs(x0-x)>0.00001)
    {
        return szukaj(a,x,ile+1);
    }else
    {
        cout<<ile<<" ";
        return x;
    }
}

double szukajn(double a){
    int c=0;
    while (a>=1)
    {
        a=a/2.0;
        c++;
    }
    
    if((c%2)==1){
        return szukaj(a*2,10,0)*pow(2,((c-1)/2));
    }else
    {
        return szukaj(a,10,0)*pow(2,c/2);
    }
}

int main(int argc, char const *argv[])
{
    cout<<szukajn(0.5)<<endl;
    cout<<szukajn(4)<<endl;
    cout<<szukajn(3)<<endl;
    cout<<szukajn(24)<<endl;
    return 0;
}