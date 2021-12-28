#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    double a=1,b=2,c=3;
    if(double delta=(pow(b,2)-4*a*c)>0){
        double w1=(-b-sqrt(delta))/(2*a),w2=(-b+sqrt(delta))/(2*a);
        cout<<"2 Miejsca zerowe "<<w1<<" i "<<w2;
    }else
    {
        if (delta==0)
        {
            double w1=(-b)/(2*a);
            cout<<"1 Miejsce zerowe "<<w1;
        }else
        {
            cout<<"Brak miejsc zerowych";
        }
        
        
    }
    
    return 0;
}
