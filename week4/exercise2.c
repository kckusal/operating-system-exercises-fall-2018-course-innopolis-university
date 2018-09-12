/* EXERCISE DESCRIPTION:
    Write a program that calls fork() in a loop 3 times and sleeps for 5 seconds. Run the program in background
    and run pstree command several times.
    
*/

#include <stdio.h>
#include <unistd.h>

#define TIMESTOFORK 3
#define TIMETOSLEEP 5

int main(){
  // call fork() defined number of times
  for (int i=1; i<=TIMESTOFORK; i++) {
    fork();
  }
  
  // sleep for a defined time
  sleep(TIMETOSLEEP);
  
  return 0;
}
