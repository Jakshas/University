#include <stdio.h>
#include <stdlib.h>

typedef struct dod{
int wart;
struct dod *nast;
}Dodaj;
Dodaj *pierwsza();
Dodaj ddodaj(Dodaj *a);
int main()
{
Dodaj *pierwsz=pierwsza();
ddodaj(pierwsz);
printf("%d",pierwsz->wart);
}

Dodaj *pierwsza(){
    Dodaj *p=malloc(sizeof(struct dod));
    p->nast=NULL;
    p->wart=5;
    return p;
}

Dodaj ddodaj(Dodaj *pierwsz){
Dodaj *p=malloc(sizeof(struct dod));
p->nast=NULL;
p->wart=5;
pierwsz->wart=pierwsz->wart+p->wart;
}
