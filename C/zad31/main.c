#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void pierwsze();
void druga();
void dodawanie();
char tab1pom[1000];
int tablica1[1000], tablica2[1000],tablica3[1000];
int main()
{
  pierwsze();
  druga();
  dodawanie();
}
void pierwsze(){
    int licz=0;
    char c;
    while((c=getchar())!='\n'){
            tablica1[0]='0';
        if(c!=' '){

            if(c=='-'){
                tablica1[0]='1';
            }else{
                tab1pom[licz]=c;
                licz++;


        }
    }
}
putchar(tablica1[0]);
int l=licz,k=2;
tablica1[1]=licz;
printf("%d",tablica1[1]);
int i;
for(i=0;licz>0;licz--,i++){
    tablica1[i+2]=tab1pom[licz-1];
}
tablica1[i+3]='\0';
while(k<l+2){
    putchar(tablica1[k]);
    k++;
}
putchar('\n');
}

void druga()
{
int licz=0;
    char c;
    while((c=getchar())!='\n'){
            tablica2[0]='0';
        if(c!=' '){

            if(c=='-'){
                tablica2[0]='1';
            }else{
                tab1pom[licz]=c;
                licz++;


        }
    }
}
putchar(tablica2[0]);
int l=licz,k=2;
tablica2[1]=licz;
printf("%d",tablica2[1]);
int i;
for(i=0;licz>0;licz--,i++){
    tablica1[i+2]=tab1pom[licz-1];
}
tablica1[i+3]='\0';
while(k<l+2){
    putchar(tablica1[k]);
    k++;
}putchar('\n');}
void dodawanie()
{
    int dlugosc;
    if(tablica1[0]==tablica2[0]){
    int roznica=tablica1[1]-tablica2[1];
    if(tablica1[1]>tablica2[1]){
        dlugosc=tablica1[1];
    }else{
    dlugosc=tablica2[1];
    }
    int i=2,x=0;
    while(i<dlugosc-roznica+2){
            printf("%d %d",tablica1[i],tablica2[i]);
            if((tablica1[i]+tablica2[i])>9){
                tablica3[i]=tablica1[i]+tablica2[i]-10+x;
                x=1;
                i++;
            }else{
        tablica3[i]=tablica1[i]+tablica2[i]+x;
        x=0;
        i++;
            }
    }
    i=0;
    while(i<dlugosc){
        tablica3[i]=tablica1[i]+x;
        x=0;
        i++;
    }
  }
int k=2;
  while(k<dlugosc+2){
    putchar(tablica3[k]);
    k++;
}
}
