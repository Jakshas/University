#include <iostream>
#include <cmath>
using namespace std;

double zla(double b , double c){
    double r=-c/2.0,q=b/3;
    return cbrt(r+sqrt(pow(q,3)+pow(r,2)))+cbrt(r-sqrt(pow(q,3)+pow(r,2)));
}

double dobra(double b , double c){
    double r=-c/2.0,q=b/3;
    double pierwiastek=cbrt(r+sqrt(pow(q,3)+pow(r,2)));
    return (2*r) / (pow(pierwiastek,2) + pow(1/pierwiastek,2) * pow(q,2) + q);
}

int main(int argc, char const *argv[])
{
    cout<<zla(100000,0.000001)<<endl;
    cout<<dobra(100000,0.000001)<<endl;
    double x1=-1.00044e-11;
    double x2=-1e-11;
    cout<<(x1*x1*x1)+100000*x1+0.000001<<endl;
    cout<<(x2*x2*x2)+100000*x2+0.000001<<endl;
    return 0;
}
