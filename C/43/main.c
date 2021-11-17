#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    int tablica[a][b];
    printf("Podaj wymiary i tablice ");
    scanf("%d %d",&a,&b);
    int z;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)
            z =tablica[i][j];
            scanf("%d",z);
    }
}
