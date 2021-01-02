#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>

template<typename F, typename G, typename H>
class compose_f_gx_hy {
private:
    typedef typename F::result_type res;    
    typedef typename G::argument_type st_arg;
    typedef typename H::argument_type nd_arg;
    F _f;
    G _g;
    H _h;
public:
    compose_f_gx_hy(F x, G y, H z) : _f(x), _g(y), _h(z) {}    
    res operator () (st_arg x, nd_arg y) { 
        return _f(_g(x), _h(y));
    }
};

int main() {
    compose_f_gx_hy<std::function<int(int, int)>, std::function<int(int)>, std::function<int(int)>> func
    ([](int x, int y){ return y * x;}, [](int x){ return  x + 1;}, [](int x){ return x - 2;});

    std::cout << func(5,4);
}   