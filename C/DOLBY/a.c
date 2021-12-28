// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char * solution(int N, int K) {
    // write your code in C99 (gcc 6.2.0)
    char * word = (char*)calloc(N,sizeof(char));

    char a = 'a';
    int i = 0;
    for(; i < K; i++){
        word[i] = a;
        word[N - i - 1] = a;
        if(i+1<K)
            a = a + 1;
    }
    int half = N/2 + N%2;
    for(;i < half;i++){
        word[i] = a;
        word[N - i - 1] = a;
    }
    return word;
}
int main(int argc, char const *argv[])
{
    printf("%s\n",solution(1,1));
    return 0;
}

