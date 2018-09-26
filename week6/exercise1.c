/*
  EXERCISE DESCRIPTION:
    Write a program that creates a pipe. Have two strings – one should contain some text, the other one should be empty.
    Transfer a text from the first string to another one using the pipe you created. Show the result.
  
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define STRING_SIZE 10

char* str1 = "Apple";
char* str2 = "";

int main() {

  char buff[STRING_SIZE];
  int p[2],i;

  printf("Before:\n Str1='%s', Str2='%s'", str1, str2);
  
  // if pipe creation unsuccessful, exit the program
  if (pipe(p)<0) exit(1);

  // pipe creation successful, so write pipe
  write(p[1],str1,STRING_SIZE);
  
  // read value in the buffer
  read(p[0],buff,STRING_SIZE);
  
  // assign value from buffer to the string
  str2 = buff;

  printf("\nAfter:\n Str1='%s', Str2='%s'", str1, str2);

  return 0;
}
