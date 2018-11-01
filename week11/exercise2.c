/* EXERCISE DESCRIPTION:
    Write a C program (ex2.c) using line buffer. Write your code according to the instructions:
    • Each of the 5 characters of “Hello” string should be put in separate printf().
    • Add a 1 sec sleep after every printf()
    
   OUTPUT: A 5 sec wait and then “Hello” printed instantaneously.
*/

#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int main(){
  char buffer[BUFFER_SIZE];

  // returns non-zero value on error
  if (setvbuf(stdout, buffer, _IOLBF, BUFFER_SIZE) !=0) {
    printf("error setting line buffer!");
  }

  printf("H");
  sleep(1);

  printf("E");
  sleep(1);

  printf("L");
  sleep(1);

  printf("L");
  sleep(1);

  printf("O");
  sleep(1);

  putchar('\n');

  return 0;
} 
