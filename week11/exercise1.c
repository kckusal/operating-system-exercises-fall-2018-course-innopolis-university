/* EXERCISE DESCRIPTION:
    Create a file ex1.txt with a random string in it. Write a C program (ex1.c) that changes the string
    in ex1.txt to “This is a nice day” by using mmap().
    
    • Hints:
      – Open the file in O_RDWR mode
      – Use stat() or fstat() to get the size of the file
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(){
  // opens the file for read and write purposes
  int myFile = open("ex1.txt", O_RDWR);
  
  if(myFile < 0){
    printf("open error\n");
  }
  
  // get file stats including its size
  struct stat myStat = {};
  if (fstat(myFile, &myStat)){
    printf("fstat error\n");
  }

  off_t size = myStat.st_size;  // size of the file
  char *addr;
  addr = mmap(NULL, strlen(str), PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);

  if (addr == MAP_FAILED){
    printf("mmap error\n");
  }

  // copy new string into the memory location mapped by addr
  strcpy(addr, "This is a nice day");
  return 0;
} 
