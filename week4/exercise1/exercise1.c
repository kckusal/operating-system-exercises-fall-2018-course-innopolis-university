/* EXERCISE DESCRIPTION:
    Create a program that declares a variable n, forks a new process and prints “Hello from parent [PID - n]” and
    “Hello from child [PID - n]” from parent and child processes respectively. Run it 10 times and explain the output.
    
    Hint: to run it N times you can write a shell script.
    
*/

#include <stdio.h>
#include <unistd.h>

int main() {
  int n;
  pid_t process_id;
  
  // fork() returns 0 in the child process and 1 in the parent process
  n = fork();
  process_id = getpid();
  
  if (n==0) {
    printf("Hello from child [PID - %d]\n", process_id);
  } else if (n>0) {
    printf("Hello from parent [PID - %d]\n", process_id);
  } else {
    printf("Error: creation of child process unsuccessful!\n");
  }

  return 0;
}
