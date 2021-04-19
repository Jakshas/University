#include<iostream>

template<int N>
constexpr int lucas(){
    return lucas<N-1>() + lucas<N-2>();
}

template<>
constexpr int lucas<1>(){
    return 1;
}

template<>
constexpr int lucas<0>(){
    return 2;
}

int main()
{
    constexpr auto l = lucas<3>();
    std::cout << l << std::endl;
}