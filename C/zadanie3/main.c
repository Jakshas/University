#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
    int n;
    scanf("%i", &n);
    int s=0;
    s=n;
    if(n>=INT_MAX){
        printf("BRAK");
        return 0;
    }
    int pierwsza=1;
    int druga=0;
    do{
        n++;
    pierwsza=1;
    double dn=(double)n;
    for(int i=2;i<sqrt(dn);i++){
        if(n%i==0){
            pierwsza=pierwsza+i+(n/i);
        }
    }
    druga=1;
    double dp= (double) pierwsza;
     for(int j=2;j<sqrt(dp);j++){
        if(pierwsza%j==0){
            druga=druga+j+(pierwsza/j);
        }
    }
    if(n==druga){
            if(pierwsza>=druga){
                printf("%i %i \n",druga,pierwsza);
            }else{
        printf("%i %i \n",pierwsza,druga);
        }
    }
 }while(n!=druga&&n<INT_MAX);
if(n==INT_MAX){
    printf("BRAK");
}
}
