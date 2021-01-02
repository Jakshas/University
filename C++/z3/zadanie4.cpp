#include <iostream>
#include <type_traits>
using namespace std;


template<typename T1,typename T2>
void przenies2(T1 &cel,T2 skad, true_type){
            if constexpr(is_convertible<T2,T1>()==true_type()){
            cel=move(static_cast<T1>(skad));
        }else
        {
            throw new std::logic_error("Typy niekonwertowalne");
        }
}

template<typename T1,typename T2>
void przenies2(T1 &cel,T2 skad, false_type){
        if constexpr(is_convertible<T2,T1>()==true_type()){
            cel=move(static_cast<T1>(skad));
        }else
        {
            throw new std::logic_error("Typy niekonwertowalne");
        }
}

template<typename T1,typename T2>
void przenies(T1 &cel,T2 skad){
    przenies2(cel , skad,is_pointer<T2>());
}

int main(int argc, char const *argv[])
{
    char src = 0;
    int dest;
    int src2 = 1;
    int *dest2;
    try {
        przenies(dest , src);
        std::cout << dest << std::endl;
        przenies(dest2 , &src2);
        std::cout << *dest2 << std::endl;
    }
    catch(std::logic_error x) {
        std::cout << x.what();
    }
    return 0;
}
//Poproawione zostało przeniesienie wskażnika dodałem move i static cast