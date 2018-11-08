/* EXERCISE DESCRIPTION:
    Write a program that will generate and display a random string of 20 symbols using /dev/random file.
    Save the code to ex1.c and the output to ex1.txt
*/

#include <stdio.h>
#include <fcntl.h>

#define BYTE_SIZE 20

int main() {
  char data[BYTE_SIZE];

  FILE *inp, *out;                    // create file pointers to input and output files
  inp = fopen("/dev/urandom", "r");   // open /dev/random file to generate random chars
  out = fopen("ex1.txt", "w");        // open ex1.txt as output file

  // read from the input file stream
  fread(&data, 1, BYTE_SIZE, inp);  
  
  // write to the output file stream
  fprintf(out, data);

  // close files
  fclose(inp);
  fclose(out);

	return 0;
}
