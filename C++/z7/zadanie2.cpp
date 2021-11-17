#include<iostream>
#include<fstream>
#include<random>
using namespace std;

random_device gen;

void jednostajny()
{
    uniform_real_distribution<double> distribution(0, 100);
    ofstream plik;
    plik.open("jednostajny.csv");
    for(int i = 0; i < 1000; i++)
    {
        plik << distribution(gen) << '\n';
    }
    plik.close();
}

void dwumianowy()
{
    binomial_distribution<int> distribution(1000, 0.2);
    ofstream plik;
    plik.open("dwumianowy.csv");
    for(int i = 0; i < 1000; i++)
        plik << distribution(gen) << '\n';

    plik.close();
}

void normalny()
{
    normal_distribution<double> distribution(10, 1.0);
    ofstream plik;
    plik.open("normalny.csv");
    for(int i = 0; i < 1000; i++)
        plik << distribution(gen) << '\n';

    plik.close();
}

int main()
{
    jednostajny();
    dwumianowy();
    normalny();
}