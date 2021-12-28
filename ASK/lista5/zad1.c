long puzzle(long n, long *p)
{
    long result = 0;                   //3
    if(n > 0)                          //8, 9
    {
        long tmp;                      //10
        result = puzzle(2*n, &tmp);    //11, 12
        result += tmp;                 //13
        n += result;                   //14
    }
    *p = n;                            //15
    return result;                     //19
}

int main(int argc, char const *argv[])
{
    long t[10];
    for(int i= 0; i<10;i++)
        t[i]=i;
    puzzle(3,t);
    return 0;
}
