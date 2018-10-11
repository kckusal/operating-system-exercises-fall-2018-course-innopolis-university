/* EXERCISE DESCRIPTION:
    Write a C program that runs for 10 seconds. Every second it should:
      – allocate 10 MB of memory
      – fill it with zeros
      – print memory usage with getrusage() function
      – sleep for 1 second
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
	
  // converts 10 MB to bytes
  int bytes = (10 * 1024 * 1024);

  void * arr;  // placeholder unallocated pointer
  
  for(int i=1; i<=10; i++) {
    arr = malloc(bytes);  // allocate 10 mb to the pointer
    memset(arr, 0, bytes);        // fill it with zeros
    
    // print memory usage using getrusage() function
    struct rusage *usage = malloc(sizeof(struct rusage));
    getrusage(RUSAGE_SELF, usage);
    printf("%ld KB\n", usage->ru_maxrss);
        
    sleep(1);       // continue execution from next second
  }

	return 0;
}
