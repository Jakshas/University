long neigh(long a[], long n, long i, long j) {
    i--;
    long p1 = j-1;
    j++;
    i = i * n;
    n = i + n*2;
    long p2 = p1 + i;
    i += j;
    long ret = *(a + (i*8));
    i = n;
    n = n - j;
    ret = ret + *(a + (p2 * 8));
    i -= p1;
    ret +=*(a + (i*8));
    ret +=*(a + (n*8));
    return ret;
}

long neigh(long a[], long n, long i, long j) {
    long p1 = (i-1)*n; 
    long p2 = p1 + (2*n); 
    long p3 = (j-1);
    long p4 = p3 + 2;
    long ret = a[p1+p3];
    ret += a[p1+p4];
    ret += a[p2+p4];
    ret += a[p2+p3];
    return ret;
}