#include <stdio.h>
 
int main() {
    
    int liczba1;
    int liczba2;
    scanf("%d %d", &liczba1, &liczba2);

    if (liczba1 > liczba2)
    {
        int pom = liczba2;
        liczba2 = liczba1;
        liczba1 = pom;
    }
    for (int i = liczba1; i <= liczba2; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}