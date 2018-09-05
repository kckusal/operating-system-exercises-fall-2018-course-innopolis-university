/*
  EXERCISE DESCRIPTION:
    Write a function bubble_sort() which will accept an array of integers and sort it in place using Bubble sort algorithm.
    
  EXERCISE SOLUTION:
    The following program has bubble sort implementation both by using pointers and without. It takes a number of input values
    and sorts them using Bubble sort method.
    
*/

#include <stdio.h>

/* Utility method to print array elements as a list. */
void printArray(int *arr, int length) {
  printf("%i", *arr);
  for (int k=1; k<length; k++) {
    printf(" %i", *(arr+k));
  }
}

/* Bubble sort without using pointers. */
void bubble_sort(int list[], int length) {
  int swapped=1, i=0;
  int temp=-1;
  
  // loop through the following until no more swaps needed
  while (swapped==1) {
    swapped = 0;  // '0' value corresponds to boolean 'false'
    for (int j=0; j<(length-i-1); j++) {
      if (list[j] > list[j+1]) {
        // swap if the numbers are in wrong orde
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
        swapped = 1;  // '1' value corresponds to boolean 'true'
      }
    }
    i++;  // go to next iteration
  }
  
  // print the array elements once sorting is done.
  printf("The sorted array is: ");
  printArray(list, length);
}

/* Bubble sort using pointers. */
void bubble_sort_using_pointers(int *list, int length) {
  int swapped=1,i=0;
  int temp=-1;

  // loop through the following until no more swaps needed
  while (swapped==1) {
    swapped = 0;  // '0' value corresponds to boolean 'false'
    for (int j=0; j<(length-i-1); j++) {
      if (*(list+j) > *(list+j+1)) {
        // swap if the numbers are in wrong orde
        temp = *(list + j);
        *(list+j) = *(list+j+1);
        *(list+j+1) = temp;
        swapped = 1;  // '1' value corresponds to boolean 'true'
      }
    }
    i++;  // go to next iteration
  }
  
  // print the array elements once sorting is done.
  printf("The sorted array is: ");
  printArray(list, length);
}

int main(){
  /* Get the size of array to be sorted. */
  int length;
  printf("Enter the number of elements in the array: ");
  scanf("%i", &length);
  
  /* Get the array elements based on size provided. */
  int arr[length];
  printf("Enter the elements of the array: ");
  for (int i=0; i<length; i++) {
    scanf("%i", &arr[i]);
  }
  
  // Print original array
  printf("The original array is: ");
  printArray(&arr, length);
  printf("\n");

  /* Apply one of the bubble sorting methods. */
  //bubble_sort(arr, length);
  bubble_sort_using_pointers(&arr, length);
  
  return 0;
}
