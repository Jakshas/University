#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

complex<double> GammaEulera(complex<double> z, int n) {
    complex<double> iloczyn(1.0, 0);
    complex<double> jedynka(1.0, 0);
    for(int i = 1; i <= n; i++) {
        complex<double> k(i, 0);
        complex<double> num(pow((jedynka + jedynka/k), z));
        complex<double> den(jedynka + z/k);
        iloczyn *= (num/den);
    }
    return iloczyn/z;
}

complex<double> InverseGammaEulera(complex<double> z, int n) {
    complex<double> iloczyn(1.0, 0);
    complex<double> one(1.0, 0);
    complex<double> gamma (0.5772156649, 0);
    for(int i = 1; i <= n; i++) {
        complex<double> k(i, 0);
        iloczyn *= (one + z/k) * exp(-z/k);
    }
    return iloczyn * z * exp( gamma * z);
}

int main() {
    cout << GammaEulera(5, 100000) << endl;
    cout << InverseGammaEulera(5, 100000);
}