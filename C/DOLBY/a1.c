// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char * solution(char *S) {
    // write your code in C99 (gcc 6.2.0)
    int tab[26];
    for(int i = 0; i<26;i++){
        tab[i] = 0;
    }
    int i = 0;
    while(true){
        char c = S[i];
        if(tab[c - 97] == 1){
            char* s= (char *)calloc(1,sizeof(char));
            s[0] = c;
            return s;
        }else{
            tab[c - 97] = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("%s\n",solution("codility"));
    return 0;
}

