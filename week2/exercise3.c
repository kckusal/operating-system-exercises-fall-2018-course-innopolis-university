/*
  EXERCISE DESCRIPTION:
  • Write a function that outputs a right-side-up triangle of height n and width 2n-1. Your program must accept n as a
    command line parameter; the output for n = 6 would be:
                 *
                ***
               *****
              *******
             *********
            *********** 
*/

#include <stdio.h>

int main(void) {
  // Get the value of n
  int n;
  scanf("%d", &n);

  for (int i=1; i<=n; i++) {
    // Print enough spaces before the star(s)
    for (int k=1; k<=(n-i); k++) {
      printf(" ");
    }
    
    // Print stars, number of which depends on the height
    for (int j=1; j<=(2*i-1); j++) {
      printf("*");
    }
    
    // Print enough spaces after the star(s)
    for (int m=1; m<=(n-i); m++) {
      printf(" ");
    }
    
    printf("\n");
  }

  return 0;
}
