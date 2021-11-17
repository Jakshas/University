#include<iostream>
#include<random>

using namespace std;

random_device gen;

template<typename T, int k>
void permutacja(T(&inp)[k])
{  
    int rozmiar = sizeof(inp)/sizeof(inp[0]);
    for(int i = rozmiar - 1; i > 0; i--)
    {
        uniform_int_distribution<int> distribution(0, i);
        int liczba = distribution(gen);
        swap(inp[liczba], inp[i]);
    }
}

int main()
{
    int foo[5]{0, 1, 2, 3, 4};
    for(int k = 0; k < 5; k++)
    {
        permutacja(foo);
        for(int i :foo)
        {
        cout << i << " ";
        }
    cout << endl;
    }
}
