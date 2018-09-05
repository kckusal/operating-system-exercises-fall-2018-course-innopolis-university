/*
  EXERCISE DESCRIPTION:
    Compile and run the following program: 
   
  EXERCISE SOLUTION:
    The following program can be compiled in many different ways, one of which is the use of GCC compiler. In a windows system
    with GCC installed, the source code in file named test.c can be compiled by executing the following commands in the command
    prompt:
                 gcc test.c -o test
    
    Note that it is necessary to set path environment variable to use 'gcc' directly, and also the source code file should be
    referenced using full directory name.
*/

#include <stdio.h>

int main(){
 int* pc;
 int c;
 c=22;
 
 printf("Address of c:%d\n",&c);
 printf("Value of c:%d\n\n",c);
 
 pc=&c;
 
 printf("Address of pointer pc:%d\n",pc);
 printf("Content of pointer pc:%d\n\n",*pc);
 
 c=11;
 
 printf("Address of pointer pc:%d\n",pc);
 printf("Content of pointer pc:%d\n\n",*pc);
 
 *pc=2;
 
 printf("Address of c:%d\n",&c);
 printf("Value of c:%d\n\n",c);
 return 0;
}

/* The output is similar to the following, where address values will differ for each execution:
    Address of c:1807936516
    Value of c:22

    Address of pointer pc:1807936516
    Content of pointer pc:22

    Address of pointer pc:1807936516
    Content of pointer pc:11

    Address of c:1807936516
    Value of c:2
*/
