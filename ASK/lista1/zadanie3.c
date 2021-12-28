#include <stdio.h>
#include <stdint.h>

struct A {
    void *b;
    int8_t a;
    int8_t c;
    int16_t d;
};

struct B {
    uint16_t a;
    double b;
    void *c;
};

int main(int argc, char const *argv[])
{
    printf("%d \n",sizeof(struct A));
    printf("%d",sizeof(struct B));
    return 0;
}
