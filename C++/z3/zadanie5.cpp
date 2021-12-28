#include <iostream>
#include <time.h>
#include <chrono>
#include <random>

using namespace std;
std::mt19937 gen{std::random_device{}()};
template<typename T>
T random(T min, T max) {
    using dist = std::conditional_t<
        std::is_integral<T>::value,
        std::uniform_int_distribution<T>,
        std::uniform_real_distribution<T>
    >;
    return dist{min, max}(gen);
}


struct Matrix {
    double *m;
    int N;
    Matrix(const int N): m(new double[N*N]) {
        this->N=N;
    }
    
    double* operator[](const int i) {return m+i*N;}
    void operator=(Matrix m1){
        m=m1.m;
    }
};


Matrix wypelnij(int rozmiar){
    srand(time(NULL));
    Matrix mul(rozmiar);
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            mul[i][j]=random(0.5,2.0);
        }
    }
    return mul;
}


void powr(Matrix matrix,int rozmiar){
    Matrix mul(rozmiar);
    for(int i=0;i<rozmiar;i++)    
    {    
        for(int j=0;j<rozmiar;j++)    
            {          
                for(int k=0;k<rozmiar;k++)    
                    {    
                        mul[i][j] += matrix[i][k] * matrix[k][j];    
                    }    
            }    
    } 
    matrix=mul;
}


int main(int argc, char const *argv[])
{
    Matrix matri100(100);
    Matrix matri1000(1000);
    Matrix matri10000(10000);
    auto start = chrono::high_resolution_clock::now();
    for(int i{0}; i < 100; i++)
    {
        matri100 = wypelnij(100);
        powr(matri100,100);
    }
    auto koniec = chrono::high_resolution_clock::now();
    chrono::duration<double> roznica = koniec - start;
    cout << roznica.count() / 100 << endl;
    start = chrono::high_resolution_clock::now();
    matri100 = wypelnij(1000);
    powr(matri100,1000);
    koniec = chrono::high_resolution_clock::now();
    roznica = koniec - start;
    cout << roznica.count()  << endl;
    start = chrono::high_resolution_clock::now();
    matri10000 = wypelnij(10000);
    powr(matri10000,10000);
    koniec = chrono::high_resolution_clock::now();
    roznica = koniec - start;
    cout << roznica.count()<< endl;
    return 0;
}
//poprawiłem deklaracje tablicy działą o sekunde szybciej drugi przykład