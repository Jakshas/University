#include <iostream>
#include <random>

using namespace std;


void shell(int* tab, int n, int o) {
    for (int i = o; i < n; i++)
    {
        int el = tab[i];
        int j = i - o;
        while (j >= 0 && tab[j] > el)
        {
            tab[j + o] = tab[j];
            j = j - o;
        }
        tab[j + o] = el;
    }
}
void shell(int* tab, int n) {
    shell(tab, n, 5);
    shell(tab, n, 3);
    shell(tab, n, 1);
}

int main(int argc, char const* argv[])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);
    int* tab = new int[10];
    for (int n = 0; n < 10; ++n) {
        tab[n] = dis(gen);
        tab[n] = 10 - n;
    }
    shell(tab, 10);
    for (int n = 0; n < 10; n++) {
        cout << tab[n] << " ";
    }
    return 0;
}
