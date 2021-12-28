#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Podaj wymiary i tablice ");
    scanf("%d %d",&a,&b);
    int tablica[a][b];
    int z;
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            scanf("%d",&z);
            tablica[i][j]=z;
        }
    }
    int wyniki[a][b];
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            wyniki[i][j]=1;
        }
    }
   for(int j=0; j<b-1; j++)
    {
        int pozycja=0;
        int w=1;
        while(tablica[a-1][j+pozycja]!=tablica[a-1][j+pozycja+1]&&pozycja<a)
        {
            w++;
            pozycja++;
        }
        wyniki[a-1][j]=w;
    }
    for(int j=b-1; j>=0; j--)
        {
            int pozycja=0;
            int w=1;
            while(tablica[a-1][j-pozycja]!=tablica[a-1][j-pozycja-1])
            {
                w++;
                pozycja++;
            }
            if(w>wyniki[a-1][j]){
                wyniki[a-1][j]=w;
            }
        }

    for(int i=a-2; i>=0; i--)
    {
        for(int j=0; j<b; j++)
        {
            int pozycja=0;
            int w=1;
            if (tablica[i][j]!=tablica[i+1][j]){
                    w=w+wyniki[i+1][j];
                }
            while(tablica[i][j+pozycja]!=tablica[i][j+pozycja+1]&&pozycja<=a)
            {
                w++;
                pozycja++;

            }
            if(w>wyniki[i][j]){
                wyniki[i][j]=w;
            }
        }
       for(int j=b-1; j>=0; j--)
        {
            int pozycja=0;
            int w=1;
            if (tablica[i][j]!=tablica[i+1][j]){
                    w=w+wyniki[i+1][j];
                }
            while(tablica[i][j-pozycja]!=tablica[i][j-pozycja-1]&&pozycja>=0)
            {
                w++;
                pozycja++;

            }
            if(w>wyniki[i][j]){
                wyniki[i][j]=w;
            }
        }

    }
    //////////////////////
    for(int i=a-2; i>=0; i--)
    {
        for(int j=0; j<b; j++){


    }
}
        //////////////////////////
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            z=wyniki[i][j];
            printf("%d ",z);
        }
        printf("\n");
    }
    int www=0;
for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
           if(wyniki[i][j]>www){
            www=wyniki[i][j];
           }
        }
    }
    printf("%d",www);
}
