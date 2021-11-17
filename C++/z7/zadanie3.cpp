#include<iostream>
#include<fstream>
#include<random>
using namespace std;

random_device gen;

void writeFile(string plikn, int dlugosc)
{
    ofstream plik;
    plik.open(plikn);
    discrete_distribution<int> dis{14810, 2715, 4943, 7874, 21912, 4200, 3693, 10795, 13318, 188, 1257, 7253, 4761, 12666, 14003, 3316, 10977, 11450, 16587, 2019, 3819, 315, 3853, 128};
    binomial_distribution<int> dlugoscsl(11, 0.5);
    int licznik = 0;
    while( licznik < dlugosc)
    {
        int pom = dlugoscsl(gen) + 1;

        while( licznik + pom > dlugosc )
            pom = dlugoscsl(gen) + 1;

        for(int i = 0; i < pom; i++)
        {
            plik <<(char)(dis(gen) + 'a');
        }

        licznik =licznik + pom;
        if(licznik < dlugosc) 
        {
            plik << ' ';
            licznik++;
        }
    }
}

int main(int argc, char *argv[])
{

    writeFile(argv[1], atoi(argv[2]));
}