void foobar(long a[], int n, long y, long z){
    if (n == 0)
    {
        return;
    }
    long x = y - z;
    long x1 = x*x;
    int i = n-1;
    long * a1 =  a+ 8 * n;
    while (a != a1)
    {
        *a1 = x1;
        x1 += 7;
    }
    return;
}