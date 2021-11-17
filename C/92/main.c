#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct fold
{
    char nazwa[256];
    struct fold *nad;
    int ilepod;
    struct fold *pod[256];
} Folder;

void nowy(char c[256],Folder* wsk);
Folder *kozen();
void mkdir(char c[256],Folder* wsk);
Folder *cd(char c[256],Folder* wsk);
void pwd(Folder* wsk);

void nowy(char c[256],Folder* wsk)
{
    Folder *nowy= malloc(sizeof(struct fold));
    strcpy(nowy->nazwa,c);
    nowy->ilepod=0;
    wsk->pod[wsk->ilepod]=nowy;
    wsk->ilepod++;
    nowy->nad=wsk;
}

Folder *kozen()
{
    Folder *nowy=malloc(sizeof(struct fold));
    strcpy(nowy->nazwa,"");
    nowy->ilepod=0;
    return nowy;
}

void mkdir(char c[256],Folder* wsk)
{
    if(wsk->ilepod<256)
    {
        int x=0;
    for(int i=0; i<wsk->ilepod; i++)
{
            if(strcmp(wsk->pod[i]->nazwa,c)==0)
            {
                x++;
            }
        }
        if(x==0)
        {
            nowy(c,wsk);
        }
    }
}

Folder *cd(char c[256],Folder* wsk)
{
    if(strcmp(c,"..")==0&&strcmp(wsk->nazwa,"..")!=0)
    {
        if(strcmp(wsk->nazwa,"")!=0){
        return wsk->nad;
    }else{
    return wsk;
    }}
    else
    {
        int i=0;
        while(strcmp(wsk->pod[i]->nazwa,c)!=0)
        {
            i++;
        }if(i>wsk->ilepod){
        return wsk;
        }
        return wsk->pod[i];
    }
}

void pwd(Folder* wsk){
if(strcmp(wsk->nazwa,"")==0){
    printf("/");
}else{
pwd(wsk->nad);
printf("%s/",wsk->nazwa);
}
}

int main()
{
    Folder *aktualny=kozen();
    char c;
    while((c=getchar())!=EOF)
    {
        if(c=='m')
        {
            getchar();
            getchar();
            getchar();
            getchar();
            getchar();
            char nazwa[256];
            scanf("%s",nazwa);
            mkdir(nazwa,aktualny);
            getchar();
        }
        if(c=='c')
        {
            getchar();
            getchar();
            char nazwa[256];
            scanf("%s",nazwa);
            aktualny=cd(nazwa,aktualny);
            getchar();
        }
        if(c=='p'){
            getchar();
            getchar();
            getchar();
            pwd(aktualny);
            printf("\n");
        }
    }
}
