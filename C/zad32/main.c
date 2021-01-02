#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void czytanie();
void wypisanie();
void zmiana();
int main()
{
    int a=0,b=0;
    scanf("%d %d",&a,&b);
    bool tablica1[a][b];
   czytanie(a,b,tablica1);
   wypisanie(a,b,tablica1);
   zmiana(a,b,tablica1);
}
 void czytanie(int a, int b ,bool tablica1[a][b]){
     char c;
     getchar();
    for(int i=0;i<b;i++){
        for(int j=0;j<=a;j++){
            if((c=getchar())=='X'){
                tablica1[i][j]=true;
            }else{
                if(c=='\n'){
                }else{
                tablica1[i][j]=false;
            }}
        }
    }
 }int j,i;
 void wypisanie(int a,int b, bool tablica1[a][b]){
     for(i=0;i<b;i++){
        for(j=0;j<a;j++){
            if(tablica1[i][j]==true){
                printf('X');
            }else{
                tablica1[i][j]=false;
                putchar(' ');
            }
        }putchar('\n');
    }
 }
 void zmiana(int a,int b,const bool tablica1[a][b]){
     int kat=0,ab,ba;
     bool tablica2[a][b];
 scanf("%d",&kat);
 if(kat==90){
        ab=i-1;
        ba=j-1;
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            tablica2[ab][j]=tablica1[i][j];
        }
        ab--;
    }
 }
  if(kat==180){
        ab=i-1;
        ba=j-1;
    for(int i=0;i<b;i++){
           ba=j-1;
        for(int j=0;j<a;j++){
            tablica2[ab][ba]=tablica1[i][j];
            ba--;
        }
        ab--;
    }
 }
 if(kat==270){
        ab=0;
        ba=j-1;
    for(int i=0;i<b;i++){
           ba=j-1;
        for(int j=0;j<a;j++){
            tablica2[ab][ba]=tablica1[i][j];
            ba--;
        }
        ab++;
    }
 }
 }

