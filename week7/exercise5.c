/* EXERCISE DESCRIPTION:
    Find and fix all the code in the following C program that generates segmentation faults:
          
          #include <stdio.h>
          int main() {
            char **s;
            char foo[] = "Hello World";
            *s = foo;
            printf("s is %s\n”,s);
            s[0] = foo;
            printf("s[0] is %s\n",s[0]);
            return(0);
          } 
*/

/* A corrected C program that fixes segmentation faults by allocating memory to the pointers. */

#include <stdio.h>

int main() {
  // memory allocation for the pointer that points to another pointer pointing to characters.
  char **s=(char**)malloc(sizeof(char*));
  
  // Because malloc might not be able to service the request, it might return a null pointer
  if (s == NULL) {
    fprintf(stderr, "malloc failed\n");
    return(-1);
  }
  
  char foo[] = "Hello World";
  *s = foo;
  
  // deferencing the value at the pointer correctly
  printf("s is %s\n",*s);
  s[0] = foo;
  printf("s[0] is %s\n",s[0]);
  return(0);
}
