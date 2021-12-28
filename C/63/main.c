#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int m, n,num_blocks;
    scanf("%d %d %d",&m, &n,&num_blocks);
    int tetris[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tetris[i][j]=0;
        }
    }
    int bloki[80][10]={0};
    char z;
    int danebl[9][2];
    int rzadwb=0;
    getchar();
    char f=getchar();
    getchar();
    char s=getchar();
    getchar();
    char t=getchar();
    int k=0;
    danebl[k][0]=0;
    danebl[k][1]=0;
    while(k<num_blocks){
            int wys, szer;
            if(k>0){
        danebl[k][0]=danebl[k-1][0]+wys;}
        wys=f-'0';szer=s-'0';
        danebl[k][1]=szer;
        for(int i=0;i<szer;i++){
            for(int j=0;j<wys;j++){
                if(t=='#'){
                    bloki[rzadwb][j]=1;
                }else{
                    bloki[rzadwb][j]=0;
                }
                t=getchar();
            }
        rzadwb++;
        t=getchar();
        }
        k++;
        if(k==num_blocks){
            danebl[k][0]=wys+danebl[k-1][0];
            break;
        }
    f=t;
    getchar();
    s=getchar();
    getchar();
    t=getchar();
    }
    int operacje=t-'0';
    int permutacje[operacje][k];
    for(int i=0;i<operacje;i++){
        char c;
        int z=0;
        while((c=getchar())!='\n'){
            if(c!=' '){
                permutacje[i][z]=c-'0';
                z++;
            }
        }
    }
    for(int i=0;i<operacje;i++){
        for(int j=0;j<k;j++){

        }
    }
}
