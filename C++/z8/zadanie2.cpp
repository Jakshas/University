#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>

using namespace std;

complex<double> Riemann(complex<double> z, int n) {
    complex<double> suma(0.0, 0);
    complex<double> jeden(1.0, 0);
    for(double i = 1; i <= n; i++) {
        complex<double> znak=pow(-1,i+1);
        complex<double> k(i, 0);
        suma += znak / pow(k, z);
    }
    return (complex<double>(1,0)/(complex<double>(1,0)-pow(2,complex<double>(1,0)-z)))*suma;
}
void liczenie(){
    ofstream plik("Riemann.csv");
    for(double i = -10; i < 10; i += 0.1) {
        complex<double> s(0.5, i);
        complex<double> wartosc = Riemann(s, 10000);
        plik << i << "," << wartosc.imag() << "," << wartosc.real() << '\n';
    }
    plik.close();
}
int main() {
    liczenie();
}

