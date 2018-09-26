/*
  EXERCISE DESCRIPTION:
    Create a program that intercepts SIGINT signal (Ctrl+C) and notifies user.
    • Hint: use signal() or sigaction() system calls to handle the signal.
*/

/* A C program that intercepts the SIGINT signal when Ctrl+C is pressed */
#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
  
/* Signal Handler for SIGINT */
void sigintHandler(int sig_num) { 
    signal(SIGINT, sigintHandler);    // Reset handler to catch SIGINT next time
    
    printf("\n Ctrl+C pressed. The program will terminate in 5 seconds now. \n");
    sleep(5);
    exit(0);
} 
  
int main () {
    // Set the SIGINT (Ctrl+C) signal handler to sigintHandler
    signal(SIGINT, sigintHandler); 
  
    /* Infinite loop waiting to catch SIGINT (Ctrl+C) */
    while(1) {         
    } 
    
    return 0; 
} 
