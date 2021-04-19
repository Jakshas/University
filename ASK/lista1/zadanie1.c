#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 2, k = 0, x = 9;
    int pom1 = 1 << i;
    int pom2 = ~(1 << k);
    int wynik1 = x & pom1;
    int wynik2 = x & pom2;
    int wynik = wynik1 | wynik2;
    printf("%d", wynik);
    return 0;
}
