// Jakub Szajner
// 315700
// WJA

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int liczba1;
    int liczba2;
    scanf("%d %d", &liczba1, &liczba2);
    int l1podziel =  (liczba1 % 2021 == 0) ? liczba1 / 2021 : (liczba1 / 2021) + 1;
    int l2podziel = liczba2 / 2021;
    for (int i = l1podziel; i <= l2podziel ; i++)
    {
        printf("%d ",i * 2021);
    }
    return 0;
}
