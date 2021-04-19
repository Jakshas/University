#include<iostream>

template<size_t N, typename T = double>
struct Iloczyn
{
    static T oblicz(T *a, T *b)
    {
        return *a * *b + Iloczyn<N-1, T>::oblicz(++a,++b);
    };
};

template<typename T>
struct Iloczyn<1, T>
{
    static T oblicz(T *a, T *b)
    {
        return *a * *b;
    };
};

template<size_t N, typename T = double> 
T inner(T *a, T *b)
{
    return Iloczyn<N, T>::oblicz(a, b);
}

int main()
{
    double a[] = {1,1,1,1};
    double b[] = {2,2,2,2};
    int iloczyn = inner<4>(a, b);
    std::cout << iloczyn << std::endl;
}