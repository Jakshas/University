#include <stdio.h>
#include <stdlib.h>

char tablica[64];
int main()
{
int i=0;
char c=48;
while(i<10){
    tablica[i]=c;
    i++;c++;
}
c=65;
while(i<36){
    tablica[i]=c;
    i++;c++;
}
c=97;
while(i<62){
    tablica[i]=c;
    i++;c++;
}
tablica[62]=' ';
tablica[63]=',';
char p=getchar();
if(p=='e'){
    int k=0;
    while(k<7){
        getchar();
        k++;
    }
    int tablicap[64];
    for(int i=0;i<64;i++){
        scanf("%d",&tablicap[i]);
    }
    char klucz[256],c; int dk=0;
    getchar();
    while((c=getchar())!='\n'){
        klucz[dk]=c;
        dk++;
    }
    int dk1=0, iklucz[256];
    while(dk1<dk){
        for(int k=0;k<64;k++){
            if(klucz[dk1]==tablica[k]){
                iklucz[dk1]=tablicap[k];
            }
        }
        dk1++;
    }
    char wynik[256];
    int dlugoscwkluczu =0;
    int p=0;
    while((c=getchar())!='\n'){
            int x=-1;
        for(int k=0;k<64;k++){
            if(c==tablica[k]){
                x=k;
            }
        }
        if(x==-1){
            printf("UNSUPPORTED_ALPHABET");
            return 0;
        }
        x=x+iklucz[dlugoscwkluczu];
        if(x>63){
            x=(x)%64;
        }
        dlugoscwkluczu++;
        if(dlugoscwkluczu>dk-1){
            dlugoscwkluczu=0;
        }
        wynik[p]=tablica[x];
        p++;
}
for(int z=0;z<p;z++){
    putchar(wynik[z]);
}
}
if(p=='d'){
    int k=0;
    while(k<7){
        getchar();
        k++;
    }
    int tablicap[64];
    for(int i=0;i<64;i++){
        scanf("%d",&tablicap[i]);
    }
    char klucz[256],c; int dk=0;
    getchar();
    while((c=getchar())!='\n'){
        klucz[dk]=c;
        dk++;
    }
    int dk1=0, iklucz[256];
    while(dk1<dk){
        for(int k=0;k<64;k++){
            if(klucz[dk1]==tablica[k]){
                iklucz[dk1]=tablicap[k];
            }
        }
        dk1++;
    }
    char wynik[256];
    int dlugoscwkluczu =0;
    int p=0;
    while((c=getchar())!='\n'){
            int x=-1;
        for(int k=0;k<64;k++){
            if(c==tablica[k]){
                x=k;
            }
        }
        if(x==-1){
            printf("UNSUPPORTED_ALPHABET");
            return 0;
        }
        x=x-iklucz[dlugoscwkluczu];
        if(x<0){
            x=x+64;
        }
        dlugoscwkluczu++;
        if(dlugoscwkluczu>dk-1){
            dlugoscwkluczu=0;
        }
        wynik[p]=tablica[x];
        p++;
}
for(int z=0;z<p;z++){
    putchar(wynik[z]);
}
}}
