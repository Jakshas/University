#include <iostream>
#include <limits>
using namespace std;
int main(int argc, char const *argv[])
{
    double dmin =numeric_limits<double>::min();
    double dmax =numeric_limits<double>::max();
    double deps =numeric_limits<double>::epsilon();
    float fmin =numeric_limits<float>::min();
    float fmax =numeric_limits<float>::max();
    float feps =numeric_limits<float>::epsilon();
    cout<<dmin<<" "<<dmax<<" "<<deps<<" "<<fmin<<" "<<fmax<<" "<<feps<<endl;
    return 0;
}

