#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int b=3;
    int n=16;
    for(b=3;b<11;b++){
            n=16;
            int j=0;
            while(j!=n){
            n++;
            int k=n;
            int liczba =0;
            int i=1;
            double db=(double)b;
        while(k>0){
           liczba=liczba+k%b*i;
           i=i*10;
           k=k/b;
        }
        j=0;
        int il=liczba;
        while(liczba>0){
            int smiec=liczba%10;
            double dsmiec= (double)smiec;
            j=j+pow(dsmiec,db);
            liczba=liczba/10;
        }
        if(j==n){
            printf("%i %i %i /n",b,n,il);
        }
    }
}
}
//Jakub Szajner
