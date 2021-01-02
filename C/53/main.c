#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char tablicay[2][16]= {{},{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',}};
    char tablicax[2][16]= {{},{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}};
    int itablicay[16];
    int itablicax[16];
    char negacja[3][100];
    for(int i=0; i<16; i++)
    {
        tablicay[0][i]='y';
    }
    for(int i=0; i<16; i++)
    {
        itablicay[i]=-1;
    }for(int i=0; i<16; i++)
    {
        itablicax[i]=-1;
    }
    for(int i=0; i<16; i++)
    {
        tablicax[0][i]='x';
    }
    char p=getchar();
    if(p=='e')
    {
        for(int iii=0; iii<6; iii++)
        {
            getchar();
        }
        getchar();
        int pozycja=0;
        char z=getchar();
        do
        {
            if(z=='y')
            {
                char g=getchar();
                for(int i=0; i<16; i++)
                {
                    if(g==tablicay[1][i])
                    {
                        itablicay[i]=pozycja;
                    }
                }
            }
            else
            {
                char g=getchar();
                for(int i=0; i<16; i++)
                {
                    if(g==tablicax[1][i])
                    {
                        itablicax[i]=pozycja;
                    }
                }
            }
            pozycja++;
            getchar();
        }while((z=getchar())!='_');
            getchar();
            getchar();
            getchar();

        z=getchar();
        int negacje=0;
        int negz=0;
        while((z)!='\n')
        {
            if(z==' '){
                z=getchar();
            }
            negacje++;
            z=getchar();
            z=getchar();
            z=getchar();
            negacja[0][negz]=getchar();
            negacja[1][negz]=getchar();
            z=getchar();
            negz++;
            negacja[0][negz]=getchar();
            negacja[1][negz]=getchar();
            z=getchar();
            negacja[2][negz]=getchar();
            negz++;
            z=getchar();
            z=getchar();
        }
        int x,y;
        getchar();
        z=getchar();
        if(z=='y'){
        scanf(",x)=(%d,%d)",&y,&x);
        }else{
        scanf(",y)=(%d,%d)",&x,&y);
        }
        int binx[16];
        for(int i=0; i<16; i++)
    {
        binx[i]=0;
    }
        int biny[16];
        for(int i=0; i<16; i++)
    {
        biny[i]=0;
    }
        int k=0;
        while(x>0)
        {
            binx[k]=x%2;
            x=x/2;
            k++;
        }
        k=0;
        while(y>0)
        {
            biny[k]=y%2;
            y=y/2;
            k++;
        }
        for(int i=0;i<negacje;i++){
        if(negacja[0][(2*i)+1]=='y'){
                int neg3=negacja[1][2*i]-'0';
                int neg1=negacja[1][2*i+1]-'0';
                int neg2=negacja[2][2*i+1]-'0';
                if(biny[neg1]==(neg2)){
                    if(negacja[0][(2*i)]=='x'){
                   if(binx[(neg3)]==0){
                    binx[(neg3)]=1;
                   }else{
                    binx[(neg3)]=0;
                   }}else{
                   if(negacja[0][(2*i)]=='y'){
                    if(biny[(neg3)]==0){
                    biny[(neg3)]=1;
                   }else{
                    biny[(neg3)]=0;
                   }
                   }
                }
        }}
        if(negacja[0][2*i+1]=='x'){
                int neg3=negacja[1][2*i]-'0';
                int neg1=negacja[1][2*i+1]-'0';
                int neg2=negacja[2][2*i+1]-'0';
                if(binx[neg1]==(neg2)){
                   if(negacja[0][(2*i)]=='x'){
                   if(binx[(neg3)]==0){
                    binx[(neg3)]=1;
                   }else{
                    binx[(neg3)]=0;
                   }}else{
                   if(negacja[0][(2*i)]=='y'){
                    if(biny[(neg3)]==0){
                    biny[(neg3)]=1;
                   }else{
                    biny[(neg3)]=0;
                   }
                   }
                }
        }
    }}
        int koncowa[32];
        for(int i=0; i<32; i++)
    {
        koncowa[i]=0;
    }
    for(int i=0;i<=pozycja;i++){
        for(int j=0;j<=pozycja;j++){
        if(itablicax[j]==i){
            koncowa[i]=binx[j];
        }
        if(itablicay[j]==i){
            koncowa[i]=biny[j];
        }
        }
    }
    z=negacja[0][1];
    double wynik=0;
    for(int j=0,i=pozycja-1;i>=0;i--,j++){
       double dkoncowa=(double)koncowa[i];
        wynik=wynik+dkoncowa*pow(2,(double)j);
    }
    printf("%d",(int)wynik);
    }
    if(p=='d')
    {
        {
        for(int iii=0; iii<6; iii++)
        {
            getchar();
        }
        getchar();
        int pozycja=0;
        char z=getchar();
        do
        {
            if(z=='y')
            {
                char g=getchar();
                for(int i=0; i<16; i++)
                {
                    if(g==tablicay[1][i])
                    {
                        itablicay[i]=pozycja;
                    }
                }
            }
            else
            {
                char g=getchar();
                for(int i=0; i<16; i++)
                {
                    if(g==tablicax[1][i])
                    {
                        itablicax[i]=pozycja;
                    }
                }
            }
            pozycja++;
            getchar();
        }while((z=getchar())!='_');
            getchar();
            getchar();
            getchar();

        z=getchar();
        int negacje=0;
        int negz=0;
        while((z)!='\n')
        {
            if(z==' '){
                z=getchar();
            }
            negacje++;
            z=getchar();
            z=getchar();
            z=getchar();
            negacja[0][negz]=getchar();
            negacja[1][negz]=getchar();
            z=getchar();
            negz++;
            negacja[0][negz]=getchar();
            negacja[1][negz]=getchar();
            z=getchar();
            negacja[2][negz]=getchar();
            negz++;
            z=getchar();
            z=getchar();
        }
        int x;
        int biny[16],binx[16];
        scanf("%d",&x);
        int koncowa[32];
        for(int i=0; i<32; i++)
    {
        koncowa[i]=0;
    }
    for(int i=0; i<32; i++)
    {
        binx[i]=0;
    }
    for(int i=0; i<32; i++)
    {
        biny[i]=0;
    }
        int k=pozycja-1;
        while(x>0)
        {
            koncowa[k]=x%2;
            x=x/2;
            k--;
        }
        for(int i=0;i<=pozycja;i++){
            for(int j=0;j<=pozycja;j++){
                if(itablicax[j]==i){
            binx[j]=koncowa[i];
        }
        if(itablicay[j]==i){
            biny[j]=koncowa[i];
        }
            }
        }
        int dlx=16;
        int dly=16;
        while(itablicax[dlx-1]==-1){
            dlx--;
        }
        while(itablicay[dly-1]==-1){
            dly--;
        }
        for(int i=negacje;i>=0;i--){
        if(negacja[0][(2*i)+1]=='y'){
                int neg3=negacja[1][2*i]-'0';
                int neg1=negacja[1][2*i+1]-'0';
                int neg2=negacja[2][2*i+1]-'0';
                if(neg3+dly<dly+dlx){
                if(biny[neg1]==(neg2)){
                    if(negacja[0][(2*i)]=='x'){
                   if(binx[(neg3)]==0){
                    binx[(neg3)]=1;
                   }else{
                    binx[(neg3)]=0;
                   }}else{
                   if(negacja[0][(2*i)]=='y'){
                    if(biny[(neg3)]==0){
                    biny[(neg3)]=1;
                   }else{
                    biny[(neg3)]=0;
                   }
                   }
                }
        }}}
        if(negacja[0][2*i+1]=='x'){
                int neg3=negacja[1][2*i]-'0';
                int neg1=negacja[1][2*i+1]-'0';
                int neg2=negacja[2][2*i+1]-'0';
                if(neg3+dlx<dly+dlx){
                if(binx[neg1]==(neg2)){
                   if(negacja[0][(2*i)]=='x'){
                   if(binx[(neg3)]==0){
                    binx[(neg3)]=1;
                   }else{
                    binx[(neg3)]=0;
                   }}else{
                   if(negacja[0][(2*i)]=='y'){
                    if(biny[(neg3)]==0){
                    biny[(neg3)]=1;
                   }else{
                    biny[(neg3)]=0;
                   }
                   }
                }
        }}
    }}
    double wynikx=0;
    for(int i=0;i<pozycja;i++){
       double dbinx=(double)binx[i];
        wynikx=wynikx+dbinx*pow(2,(double)i);
    }
    double wyniky=0;
    for(int i=0;i<pozycja;i++){
       double dbiny=(double)biny[i];
        wyniky=wyniky+dbiny*pow(2,(double)i);
    }
    printf("(y,x)=(%d,%d)",(int)wyniky,(int)wynikx);
    }
    }
}
