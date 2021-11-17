#include <stdlib.h>

int main(int argc, char const *argv[])
{
    void* p = NULL;
    int pid = fork(),status;
    if (pid == 0)
    {
        printf("Dziecko %p\n", (void*)&p);
    }else{
        waitpid(pid, &status, 0);
        printf("Rodzic  %p\n", (void*)&p);
    }
    
    return 0;
}
