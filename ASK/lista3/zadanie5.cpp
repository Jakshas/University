int main(int argc, char const *argv[])
{
    int x = 1 ,y =2;
    (((x&(1<<31)==0x80000000)&(y&(1<<31)==0000000)) |
    ((x&(1<<31)==0)&(y&(1<<31)==0)&(x-y>>31==1))|
    (x&(1<<31)>>31==1)&(y&(1<<31)>>31==1)&
    ((y-x)>>31==1))&((x|y)&0x80000000);

    (((~(x | y) & (x - y)) | (x & y & (y - x)) | (x & ~y)) & 0x80000000) != 0 & ((x | y) != 0x80000000);

    return 0;
}
