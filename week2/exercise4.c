/*
  EXERCISE DESCRIPTION:
  • Write a program that asks user to input two integers and swaps them using a separate function.
  • Hint: you will need to pass parameters by reference.
*/

#include <stdio.h>

/* Gets arguments by reference and exchanges their values. */
void swapNumbers(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

int main(void) {
  
  // Get two numbers
  int x, y;
  scanf("%d%d", &x, &y);

  // Print before swapping
  printf("Before swapping, x is %d and y is %d\n", x, y);

  // Swap the numbers
  swapNumbers(&x, &y);

  // Print after swapping
  printf("After swapping, x is %d and y is %d", x, y);
  return 0;
}
