#include <stdio.h>
#include <unistd.h>
#include <time.h>

void main(void)

{

        int pid,status;
        time_t tt;
        int zarodek = time(&tt);
        srand(zarodek);
        for (int i = 0; i < 5; i++)
        {       
                int r= rand()%5+1;
                if((pid = fork()) == 0) 
                {
                        printf(" Potomny = %d ,%d \n",getpid(),r);
                        sleep(r);
                        exit(0);
                }
        }
        while ((pid = wait(&status)) > 0);
        printf("Macierzysty = %d \n",getpid());
        printf("Proces %d zakończony status: %d\n",pid,status);

}