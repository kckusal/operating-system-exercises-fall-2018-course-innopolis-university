/*
  EXERCISE DESCRIPTION:
    Write a C program that declares signal handlers for SIGKILL, SIGSTOP and SIGUSR1 (refer to Exercise 3).
      • Compile and run the program in background
      • Use kill command to send SIGUSR1 signal to the process you have started: kill -SIGUSR1 <pid>
      
*/

/* A C program declaring signal handlers for SIGKILL, SIGSTOP, SIGUSR1 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int signum) {
  if (signum == SIGUSR1) {
    printf("SIGUSR1 intercepted.\n");
  } else if (signum == SIGKILL) {
    printf("SIGKILL intercepted.\n");
  } else if (signum == SIGSTOP) {
    printf("SIGSTOP intercepted.\n");
  }
}

int main() {
    if (signal(SIGUSR1, sigHandler) == SIG_ERR) {
      printf("\ncan't catch SIGUSR1\n");
    }

    if (signal(SIGKILL, sigHandler) == SIG_ERR) {
      printf("\ncan't catch SIGKILL\n");
    }

    if (signal(SIGSTOP, sigHandler) == SIG_ERR) {
      printf("\ncan't catch SIGSTOP\n");
    }

    // A long long wait so that we can easily issue a signal to this process
    while(1) {
      sleep(1);
    }

    return 0;
}


/* NATURE OF OUTPUT:
  - The program will print "can't catch SIGKILL" and "can't catch SIGSTOP" respectively, as it is not possible to
    handle the two signals, KILL and STOP.
  - Trying to pass signal USR1 using the kill command, say, $ kill -USR1 2678 will print "SIGUSR1 intercepted." in
    the terminal, assuming there's a process running with id 2678.
  
*/
