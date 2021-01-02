#include <iostream>
#include <cmath>
using namespace std;

double pi(int k) {
    if(k == 1) return 2;
    return pow(2, k) * sqrt(2 * (1 - sqrt(1 - pow(pi(k-1) / pow(2,k), 2))));
}

void new_pi(int k) {
    double *T = new double[1000];
    T[0] = 2.0;
    for(int i = 1; i < 550; i++){
        T[i] = sqrt(2.0 * pow(T[i-1], 2.0) / (1.0 + sqrt(1.0 - pow((T[i-1] / pow(2.0, i)), 2))));
        cout << i << " " << T[i] << endl;
    }
}

int main() {
    cout << pi(20) << endl;
    new_pi(50);
}