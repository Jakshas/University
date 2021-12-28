#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <typeinfo>

template<typename T1, typename T2>
class Po_kolei {
private:
    typedef typename T2::argument_type res2;
    T1 f1;
    T2 f2;
public:
    typedef res2 argument_type;
    Po_kolei(T1 x, T2 y) : f1(x), f2(y) {}    
    void operator () (res2 x) { 
        f1(x);
        f2(x);
    }
};

template<typename F1, typename F2>
Po_kolei<F1, F2> po_kolei(F1 f1, F2 f2){
    return Po_kolei<F1, F2>(f1, f2);
}

int main() {
    std::function<int(double)> f1 = [](double x) {return x+x;};
    std::function<int(double)> f2 = [](double x) {return x*x;};
    std::function<int(int)> f3 = [](int x) {return x-1;};
    po_kolei(f1, f2)(5.0);
    po_kolei(po_kolei(f1, f2), f3)(10.0);
}   