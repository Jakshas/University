#include <iostream>
#include <cmath>
using namespace std;

double a(double x) {
    return pow(x,3) - sqrt(pow(x,6) + 2020);
}

double new_a(double x) {
    return -2020 / (pow(x,3) + sqrt(pow(x,6) + 2020));
}

double b(double x) {
    double coss = cos(x) -1;
    double dzielenie = pow(x,2) / 2;
    return pow(x,-4) * (coss + dzielenie);
}

long long int silnia(int n) {
    long long int sum = 1;
    for(int i = 1; i <= n; i++) {
        sum *= i;
    }
    return sum;
}

double new_b(double x, int n) {
    double sum = 0.0;
    long long int k = 4;
    for(int i = 2; i < n; i++) {
        sum += pow(-1,i) * (pow(x, k - 4) / silnia(k));
        k += 2;
    }
    return sum;
}

double c(double x) {
    return log(x) / log(5) - 6;
}

double new_c(double x) {
    return log(x/pow(5,6)) / log(5);
}

int main() {
    cout << a(100000000.0) << endl;
    cout << new_a(100000000.0) << endl;
    cout << b(0.000000001) << endl;
    cout << new_b(0.000000001, 20) << endl;
    cout << c(pow(5,6)) << endl;
    cout << new_c(pow(5,6)) << endl;
}