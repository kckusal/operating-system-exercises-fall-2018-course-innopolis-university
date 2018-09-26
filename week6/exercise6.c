/*
  EXERCISE DESCRIPTION:
    • Manual for waitpid() system call says:
        “All of these system calls are used to wait for state changes in a child of the calling process,
         and obtain information about the child whose state has changed. A state change is considered to be:
          – the child terminated;
          – the child was stopped by a signal;
          – or the child was resumed by a signal”
    
    • Check whether this description is true by writing a program that forks two child processes:
      – After forking the second child, main process should send its (2nd child’s) pid to the first child by
        any means you know so far.
      – Then it should wait for state changes in second child
      – First child should wait a couple of seconds and send SIGSTOP to the second child
      – All the other actions are on your choice
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include <sys/wait.h>

int main() {
  pid_t p1;
  
  int PIPE[2];
  // if pipe creation unsuccessful, exit the program
  if (pipe(PIPE)<0) exit(1);

  p1 = fork();
  if (p1<0) {
    printf("First fork() failed!\n");
  }
  else if (p1>0) {    // parent process
    pid_t p2 = fork();

    if (p2<0) {
      printf("Second fork() failed!\n");
    }
    else if (p2>0) {  // first-child process OR parent of second-child
      /* write the pid of second-child process to the pipe */
      close(PIPE[0]);   // close reading end
      write(PIPE[1], &p2, sizeof(p2));
      close(PIPE[1]);   // close writing end

      printf("First-child is waiting for status change.\n");
      int st; // status
      waitpid(p2, &st, 0);
    }
    else {  // second-child process
      printf("I represent the second-child process.");
    }

  }
  else {    // first-child process
    pid_t p2;

    /* read the pid of second-child process from the pipe */
    close(PIPE[1]);   // close writing end
    read(PIPE[0], &p2, sizeof(p2));
    close(PIPE[0]);   // close reading end

    sleep(2);
    kill(p2, SIGSTOP);
  }

  return 0;
}
