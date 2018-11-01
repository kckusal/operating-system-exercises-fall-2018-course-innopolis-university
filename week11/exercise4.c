/* EXERCISE DESCRIPTION:
    Write a C program (ex4.c) to copy the content of ex1.txt to ex1.memcpy.txt using memory mappings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

int main() {
  int src_file, dest_file;
  char *src_addr, *dest_addr;
  size_t f_size;

  /* SOURCE FILE */
  src_file = open("ex1.txt", O_RDONLY);
  f_size = lseek(src_file, 0, SEEK_END);

  src_addr = mmap(NULL, f_size, PROT_READ, MAP_PRIVATE, src_file, 0);

  /* DESTINATION FILE */
  dest_file = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);

  ftruncate(dest_file, f_size);

  dest_addr = mmap(NULL, f_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest_file, 0);

  /* COPY */
  memcpy(dest_addr, src_addr, f_size);

  munmap(src_addr, f_size);
  munmap(dest_addr, f_size);

  close(src_file);
  close(dest_file);

  return 0;
}
