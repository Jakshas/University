#include <iostream>
#include <cmath>
using namespace std;


void klasycznie(double a, double b , double c){
    double delta = (pow(b , 2)-(4*a*c));
    if(delta > 0){
        cout<<"wyniki to "<<((-b-sqrt(delta))/2*a)<<" i "<<((-b+sqrt(delta))/2*a)<<endl;
    }else
    {
        if(delta==0){
            cout<<"wynik to "<<-b/(2*a);
        }else
        {
            cout<<"nie ma wyniku";
        }
    }
    
}

void viet(double a, double b , double c){
    double delta = (pow(b , 2)-(4*a*c));
    if(delta > 0){
        double x1=c/((-a*b)-a*sqrt(delta));
        cout<<"wyniki to "<<x1<<" i "<<(-b/c)-x1<<endl;
    }else
    {
        if(delta==0){
            cout<<"wynik to "<<-b/(2*a);
        }else
        {
            cout<<"nie ma wyniku";
        }
    }
    
}

int main(int argc, char const *argv[])
{
    klasycznie(1,100000000000,1);
    viet(1,100000000000,1);
    return 0;
}
