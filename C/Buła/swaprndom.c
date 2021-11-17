#include <stdlib.h>
#include <time.h>
void swaprandom(char* arr , int n, char c){
    srand(time(NULL));
    int r = rand() % (n - 1);
    arr[r] = c;
}