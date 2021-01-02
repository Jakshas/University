#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    return 4040 / (sqrt(pow(x, 11) + 1) + 1);
}

int main() {
    cout << func(0.000001) << endl;
}