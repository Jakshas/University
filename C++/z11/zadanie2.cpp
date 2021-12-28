#include<iostream>

template<unsigned long i>
constexpr unsigned long fac() {
    return (i<2) ? 1 : i*fac<i-1>();
    }

template<unsigned long n, unsigned long k>
constexpr unsigned long bin() {
    return fac<n>() / (fac<k>() * fac<n-k>());
    }

int main()
{
    constexpr unsigned long i = bin<3,2>();
    std::cout << i << std::endl;
}