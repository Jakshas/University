#include<iostream>
template<unsigned long a, unsigned long b>
constexpr unsigned long nwd() {
    if constexpr(b==0){
        return a;
    }else
    {
        return nwd<b,a%b>();
    }
    }

int main()
{
    constexpr auto n = nwd<4,8>();
    std::cout << n << std::endl;
}