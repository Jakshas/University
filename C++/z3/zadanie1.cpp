#include <iostream>
#include <limits>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int max = numeric_limits<long long int>::max();
    long long int min = numeric_limits<long long int>::min();
    cout<<max<<" "<<min;
    cout << numeric_limits<long long int>::digits << endl;
    return 0;
}
// 64 bity
