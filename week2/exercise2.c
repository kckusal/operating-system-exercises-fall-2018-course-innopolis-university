/*
  EXERCISE DESCRIPTION:
  • Write a program that prompts the user for a string, and prints its reverse
  • Hints:
    – a string in C is an array of chars (more about arrays next week)
    – use strlen() function to get the length of a string
    – you can use printf(), puts() or even putchar() functions to print    
*/

#include <stdio.h>
#include <string.h>

int main(void) {
  // A string is defined as an array of characters, max-length here is 1000 characters
  char myString[1000];
  // Takes an entire line as an input
  scanf("%[^\n]%*c", myString);
  
  char temp;    // Temporary variable to help in swapping characters
  int str_size = strlen(myString);    // Size of the string
  
  // Loop from beginning of string to the middle...
  // swapping first character with last, second character with second-last, and so on...
  // hence reversing the characters array or reversing the string
  for(int i=0; i<str_size/2; i++) {
    temp = myString[str_size-1-i];
    myString[str_size-1-i] = myString[i];
    myString[i] = temp;
  }

  // Print the string that's been reversed.
  printf("%s", myString);
  return 0;
}
