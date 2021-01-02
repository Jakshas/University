#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

long long int silnia(int n) {
    long long int sum = 1;
    for(int i = 1; i <= n; i++) {
        sum *= i;
    }
    return sum;
}
double jeden(double x){
    return 4*pow(cos(x),2)-3;
}
double dwa(double x){
    return (-16 * cos((x + (M_PI / 6.0) / 2.0) * cos((x - (M_PI/6.0)) / 2.0))) * sin((x + (M_PI/6.0) / 2.0) * sin((x-(M_PI/6.0)) / 2.0));
}

double jeden2(double x){
    return pow(x , -3)*((M_PI/2.0)-x-atan(1/x));
}

double dwa2(double x){
    double sum = 0;
    for (int i = 0; i < 100; i++)
    {
        double gura=(pow(-1 , i+1)*pow(x , i*2.0));
        sum =sum + (gura/(3.0+i*2.0));
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    cout<<jeden(M_PI/6.0)<<endl;
    cout<<dwa(M_PI/6.0)<<endl;
    cout<<jeden2(0.000001)<<endl;
    cout<<dwa2(0.000001);
}

