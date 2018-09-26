/*
  EXERCISE DESCRIPTION:
    Write a C program that forks a child process, waits for 10 seconds and then sends a SIGTERM signal to the child.
    • Child process should run an infinite loop and print “I’m alive” every second.
    • Hint: use kill() system call to send a signal

*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

pid_t child_pid = -1 ; // Global variable to store child process' id

void printEverySecond() {
  while (1) {
    printf("I'm alive\n");
    sleep(1);
  }
}

/* Kills child process when the method is called. */
void sigtermHandler() {
  kill(child_pid, 9);   
}

int main() {
  pid_t f;
  f = fork();

  if (f<0) {  // unsuccessful in creating child process
    printf("Error: can't create child process.\n");
  } else if (f>0) { // returned to parent process
    
    // The return value of fork() in parent's process is the pid of child process.
    child_pid = f;
    
    sleep(10);
    
    if (signal(SIGTERM, sigtermHandler) == SIG_ERR) {
      printf("can't catch SIGTERM.\n");
    }
    
  } else {  // returned to the child process
    printEverySecond();
  }
  return 0;
}
