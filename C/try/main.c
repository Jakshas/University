#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct node
{
    bool czy_liczba;
    double liczba;
    char oper;
    struct node *lewy, *prawy;
} Node;
Node* liczba(double liczba)
{
    Node* lisc=(struct node*)malloc(sizeof(struct node));
    if(lisc==NULL)
    {
        printf("brak pamieci");
        exit(1);
    }
    lisc->czy_liczba=1;
    lisc->liczba=liczba;
    return lisc;
}
Node* nowa_operacja(char op, Node* prawy, Node*lewy)
{
    Node* wezel=(struct node*)malloc(sizeof(struct node));
    if(wezel==NULL)
    {
        printf("brak pamieci");
        exit(1);
    }
    wezel->lewy=lewy;
    wezel->prawy=prawy;
    wezel->czy_liczba=0;
    wezel->oper=op;

    return wezel;
}
void wypisz(Node *drzewo)
{
    if(drzewo->czy_liczba==1)
    {
        printf("%f",drzewo->liczba);
    }
    else
    {
        printf("(");
        wypisz(drzewo->lewy);
        printf("%c", drzewo->oper);
        wypisz(drzewo->prawy);
        printf(")");
    }
}
int main()
{
    Node *stos[1000];
    int wierzcholek=0;
    char czar;
    double liczb;
    //tworzymy drzewo

    do
    {
        if(scanf(" %c", &czar)==1)
        {
            if(isdigit(czar))
            {
                ungetc(czar,stdin);
                scanf("%lf",&liczb);
                stos[wierzcholek]=liczba(liczb);
                wierzcholek+=1;
            }
            else if (czar!='=')
            {
                wierzcholek-=1;
                stos[wierzcholek-1]=nowa_operacja(czar,stos[wierzcholek-1],stos[wierzcholek]);
            }
        }
    }
    while(czar!='=');
    wypisz(stos[0]);

    return 0;
}
