/* EXERCISE DESCRIPTION:
     Write a C program that dynamically allocates memory for an array of N integers,
     fills the array with incremental values starting from 0, prints the array and deallocates the memory.
     
     Program should prompt the user to enter N before allocating the memory.
     
     Note: The following C program uses the utility function sleep() for pause-and-see effect while printing.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int N;
  printf("Enter the value of N: ");
  scanf("%i", &N);

  printf("\nMemory being allocated for the array.\n\n");

  int * my_array = malloc(N * sizeof(int));
  sleep(2);

  // Because malloc might not be able to service the request, it might return a null pointer
  if (my_array == NULL) {
    fprintf(stderr, "malloc failed\n");
    return(-1);
  }

  // filling the array
  for (int i=0; i<N; i++) {
    my_array[i] = i;
  }

  // printing the array
  for (int i=0; i<N; i++) {
    printf("Array Item %i: %i\n", i+1, my_array[i]);
    sleep(1);
  }

  printf("\nThis memory will be deallocated in 4 seconds.\n");
  sleep(4);

  // deallocating the array
  free(my_array);
  printf("\nArray memory successfully deallocated!");

  return 0;
}
