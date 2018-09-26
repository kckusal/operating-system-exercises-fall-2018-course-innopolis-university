/*
  EXERCISE DESCRIPTION:
    Exercise 1: Write a program that creates a pipe. Have two strings – one should contain some text, the other one should be empty.
      Transfer a text from the first string to another one using the pipe you created. Show the result.
    
    • Modify the exercise1 solution so that main process will fork a child and pass a string to it using pipe. Child process should
      print the string after reading it from the pipe.
      
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define STRING_SIZE 30

char* string = "This is our string.";

int main() {

  char buff[STRING_SIZE];
  int p[2];

  // if pipe creation unsuccessful, exit the program
  if (pipe(p)<0) exit(1);

  // fork the main process and get the return value
  int f=fork();
  if (f<0) {    // creation of child process unsuccessful
    printf("Fork Error: cannot create child process.");
  } else if (f>0) {   // returned to the parent process
    // write the pipe
    write(p[1], string, STRING_SIZE);
  } else {    // returned to the child process
    // read the pipe
    read(p[0], buff, STRING_SIZE);
    printf("This is 'child' process and the passed string is \"%s\".", buff);
  }

  return 0;
}
