#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    bool czy_liczba;
    double liczba;
    char oper;
    struct node *lewy,*prawy;
} Node;
Node *nowaoper(char op,Node *lewy,Node *prawy);
Node *nowylisc(double liczba);
Node *czytajonp(void);
void wypisz(Node *p,bool nawias);
int wierzcholek=0;
Node *stos[1000];
int main()
{
    czytajonp();
    wypisz(stos[0],0);
}

Node *nowylisc(double liczba)
{
    Node *p=(struct node *)malloc(sizeof(struct node));
    if(p == NULL)
        return 1;
    p->czy_liczba=1;
    p->liczba=liczba;
    p->oper='*';
    return p;
}
Node *nowaoper(char op,Node *lewy,Node *prawy)
{
    Node *p=(struct node *)malloc(sizeof(struct node));
    if(p == NULL)
        return 1;
    p->lewy=lewy;
    p->prawy=prawy;
    p->czy_liczba=0;
    p->oper=op;
    return p;
}
Node *czytajonp(void)
{
    char op=0;
    double licz;
    do
    {
        if(scanf(" %c", &op)==1)
            if(isdigit(op))
            {
                ungetc(op,stdin);
                scanf("%lf",&licz);
                stos[wierzcholek]=nowylisc(licz);
                wierzcholek++;
            }
            else  if(op!='=')
            {
                wierzcholek--;
                stos[wierzcholek-1]=nowaoper(op,stos[wierzcholek-1],stos[wierzcholek]);
            }

    }
    while(op!='=');

}
void wypisz(Node *p,bool nawias)
{
    int l=0;
    int o=0;
    int pr=0;
    if(p->czy_liczba==1)
    {
        printf("%f",p->liczba);
    }
    else
    {
        if(nawias==1)
        {
            if(p->oper=='*'||p->oper=='/')
            {
                o=1;
            }
            if(p->lewy->oper=='*'||p->lewy->oper=='/')
            {
                l=1;
            }
            if(p->prawy->oper=='*'||p->prawy->oper=='/')
            {
                pr=1;
            }
            if(l<o)
            {
                nawias=1;
            }
            else
            {
                nawias=0;
            }
            printf("(");
            wypisz(p->lewy,nawias);
            printf("%c", p->oper);
            if(pr<=o)
            {
                nawias=1;
            }
            else
            {
                nawias=0;
            }
            wypisz(p->prawy,nawias);
            printf(")");
        }
        else
        {
            if(p->oper=='*'||p->oper=='/')
            {
                o=1;
            }
            if(p->lewy->oper=='*'||p->lewy->oper=='/')
            {
                l=1;
            }
            if(p->prawy->oper=='*'||p->prawy->oper=='/')
            {
                pr=1;
            }
            if(l<o)
            {
                nawias=1;
            }
            else
            {
                nawias=0;
            }
            wypisz(p->lewy,nawias);
            printf("%c", p->oper);
            if(pr<=o)
            {
                nawias=1;
            }
            else
            {
                nawias=0;
            }
            wypisz(p->prawy,nawias);
        }
    }
}
//Jakub Szajner
