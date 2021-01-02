#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct sl{
char slowo[1000];
};
char przepisz(int t[12][12],struct sl *slow);
void wypisz(struct sl *slow);
int tab[12][12];
char buf[10000];
int main()
{
    int x=0;
struct sl *slow=malloc(sizeof(struct sl));
for (int i=0;i<12;i++){
    for(int j=0;j<12;j++){
        tab[j][i]=x;
        x++;
    }
}przepisz(tab,slow);
wypisz(slow);

}

char przepisz(int t[12][12],struct sl *slow){
for (int i=0; i < 12; i++)
  for (int j=0; j < 12; j++)
    sprintf(buf+4*(i*12+j),"%3d ", tab[i][j]);
buf[4*(12*12+2)] = '\0';
}

void wypisz(struct sl *slow){

for (int i=0; i < 12; i++)
  for (int j=0; j < 12; j++)
    sscanf(buf+4*(i*12+j),"%d", &tab[i][j]);

    for (int i=0;i<12;i++){
    for(int j=0;j<12;j++){
        printf("%d ",tab[j][i]);
    }}
}
