#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

int k = 20;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    vector<int> v;
    for(int i = 1; i <= k; i++)
        v.push_back(phi(i));
    ofstream file("phi.txt");
    ostream_iterator<int> oit (file, "; ");
    copy(v.begin(), v.end(), oit);
}