/* EXERCISE DESCRIPTION:
      Write a C program that runs for 10 seconds. Every second it should:
        – allocate 10 MB of memory
        – fill it with zeros
        – sleep for 1 second
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	
  // converts 10 MB to bytes
  int bytes = (10 * 1024 * 1024);

  int * arr;  // placeholder array

  for(int i=1; i<=10; i++) {
    arr = (int *) malloc(bytes);  // allocate 10 mb to the array
    memset(arr, 0, bytes);        // fill it with zeros
    sleep(1);                     // continue execution from next second
  }

	return 0;
}
