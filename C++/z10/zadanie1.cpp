#include <iostream>
#include <iterator>
#include <vector>
#include <functional>
#include <numeric>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    vector<double> v;
    istream_iterator<double> eos;
    istream_iterator<double> iit (cin);
    while(iit != eos) {
        v.push_back(*iit);
        iit++;
    }

    cout << fixed << setprecision(3);
    double srednia = accumulate(v.begin(), v.end(), 0.0, [] (double &acc, double &el) {return acc += el;}) / v.size();
    cout << srednia << endl;

    double odchylenie = sqrt(accumulate(v.begin(), v.end(), 0.0, [&] (double &acc, double &el) {return acc += pow(el - srednia, 2.0);}) / v.size());
    cout << odchylenie << endl;

}