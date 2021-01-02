#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char tablica1[1000]= {0};
    char c;
    int i=0, k,dl=0;
    c=getchar();
    while(c!='\n')
    {
        tablica1[i]=c;
        i++;
        c=getchar();
    }
    dl=i;
    i=0;
    for(int j=0; j<dl; j++)
    {
        if(tablica1[j]=='(')
        {
            j++;
            while(tablica1[j]==' ')
            {
                j++;
            }
            if(tablica1[j]=='+' || tablica1[j]=='-' || tablica1[j]=='*' || tablica1[j]=='/')
            {
                putchar(tablica1[j]);
                putchar('(');
            }
            else if((tablica1[j]>='a' && tablica1[j]<='z') || (tablica1[j]>='A' && tablica1[j]<='Z'))
            {
                {
                    while((tablica1[j]>='a' && tablica1[j]<='z') || (tablica1[j]>='A' && tablica1[j]<='Z'))
                    {
                        putchar(tablica1[j]);
                        j++;
                    }
                    putchar('(');
                }
            }
        }
        if((tablica1[j]>='0' && tablica1[j]<='9') || (tablica1[j]>='a' && tablica1[j]<='z') || (tablica1[j]>='A' && tablica1[j]<='Z'))
        {
            while((tablica1[j]>='0' && tablica1[j]<='9') || (tablica1[j]>='a' && tablica1[j]<='z') || (tablica1[j]>='A' && tablica1[j]<='Z'))
            {
                putchar(tablica1[j]);
                j++;
            }
            while(tablica1[j]==' ')
            {
                j++;
            }
            if(tablica1[j]!=')' && tablica1[j]!=0)
            {
                putchar(',');
                putchar(' ');
            }
            j--;
        }
        if(tablica1[j]==')')
        {
            while(tablica1[j]==')' || tablica1[j]==' ')
            {
                if(tablica1[j]==')')
                {
                    putchar(tablica1[j]);
                }
                j++;
            }
            k=j;
            j--;
            while(tablica1[k]==' ')
            {
                k++;
            }
            if(tablica1[k]!=0)
            {
                putchar(',');
                putchar(' ');
            }
        }
    }
}
