#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc <= 1){
        printf("Brak argumentów"); return 1;
    }
    int m, n;
    sscanf(argv[1],"%d", &m); sscanf(argv[2],"%d", &n);
    int kolumna=0;
    int c=0;
    int cos =1;
    char slowo[200];
       while (cos>0&&c!=EOF){
            int i=0;
            while((c = getchar())!=' '&&c!=EOF){
                slowo[i]=c;
                i++;
            }
    if(kolumna==0){
        while(kolumna<m-1){
            putchar(' ');
            kolumna++;
        }
    }
            if(i>n-m+1){
                printf("za dlugie slowo");
                return 1;
            }
            if(kolumna+i>n){
                putchar('\n');
                kolumna=0;
                 while(kolumna<m-1){
            putchar(' ');
            kolumna++;
            }
                int j=0;
                while(j<i){
                    putchar(slowo[j]);
                    kolumna++;
                    j++;
                }putchar(' ');
            }else{int k=0;
            while(k<i){
                putchar(slowo[k]);
                kolumna++;
                k++;
            }putchar(' ');}
    kolumna++;
    if(kolumna>=n){
        kolumna=0;
        putchar('\n');
    }}
}
// Jakub Szajner
