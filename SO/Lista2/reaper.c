#include "csapp.h"

static pid_t spawn(void (*fn)(void)) {
  pid_t pid = Fork();
  if (pid == 0) {
    fn();
    printf("(%d) I'm done!\n", getpid());
    exit(EXIT_SUCCESS);
  }
  return pid;
}

static void grandchild(void) {
  printf("(%d) Waiting for signal!\n", getpid());
  /* TODO: Something is missing here! */
  pause();
  printf("(%d) Got the signal!\n", getpid());
}

static void child(void) {
  pid_t pid;
  /* TODO: Spawn a child! */
  Setpgid(getpid(), getpid());
  pid = spawn(grandchild);
  printf("(%d) Grandchild (%d) spawned!\n", getpid(), pid);
}

/* Runs command "ps -o pid,ppid,pgrp,stat,cmd" using execve(2). */
static void ps(void) {
  /* TODO: Something is missing here! */
  char* const argv[] = {"/usr/bin/ps", "-o", "pid,ppid,pgrp,stat,cmd", NULL};
  execve(argv[0], argv, NULL);
}

int main(void) {
  /* TODO: Make yourself a reaper. */
#ifdef LINUX
  Prctl(PR_SET_CHILD_SUBREAPER, 1);
#endif
  printf("(%d) I'm a reaper now!\n", getpid());

  pid_t pid, pgrp;
  int status;

  /* TODO: Start child and grandchild, then kill child!
   * Remember that you need to kill all subprocesses before quit. */
  pid = getpid();
  pgrp = spawn(child);
  Waitpid(pgrp, NULL, 0);

  pid_t ps_pid = spawn(ps);
  Waitpid(ps_pid, NULL, 0);

  Kill(-pgrp, SIGINT);

  printf("(%d) Sending SIGINT to group %d!\n", pid , pgrp);

  Wait(&status);

  printf("(%d) Grandchild exit code: %d!\n", pid , WEXITSTATUS(status));

  return EXIT_SUCCESS;
}
