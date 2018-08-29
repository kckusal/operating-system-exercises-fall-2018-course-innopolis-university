/*
  EXERCISE DESCRIPTION:
  • Create a program that declares integer, float and double variables
  • Find out how to assign maximum values for each variable (hint: use INT_MAX for integer, etc.)
  • Print sizes and values of each variable
  • Discuss the results
*/

// Preprocessor directives requesting to include the necessary header files
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
  // Declare an integer, a float, and a double variable
  int p;
  float q;
  double r;

  // Assign maximum values to each variable according to their data types
  p = INT_MAX;
  q = FLT_MAX;
  r = DBL_MAX;
  
  // Print the sizes of each variables in bytes
  printf("The size of p (int) is %lu bytes, q (float) is %lu bytes, and r (double) is %lu bytes.\n", sizeof(p), sizeof(q), sizeof(r));

  // Print the values stored in each variables
  printf("The value of p is %d, q is %f, r is %f\n", p, q, r);

  return 0;
}
