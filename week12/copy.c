/* EXERCISE DESCRIPTION:
    • Using the time built-in command of the shell, try timing the operation of the program in copy.c (time ./copy fileA fileB)
      – Experiment with different file and buffer sizes. You can set the buffer size using the -DBUF_SIZE=nbytes option when
        compiling the program.
      – Modify the open() system call to include the O_SYNC flag. How much difference does this make to the speed for various
        buffer sizes?
      – Save the results and explanation in file ex3.txt
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/* Set default buffer size. */
#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[]) {
  int inp, out, openFlags;
  mode_t filePerms;
  ssize_t numRead;
  char buf[BUF_SIZE];

  if (argc != 3 || strcmp(argv[1], "--help") == 0) {
    printf("%s old-file new-file\n", argv[0]);
  return 0;
  }

  /* Open input and output files */
  inp = open(argv[1], O_RDONLY);
  if (inp == -1) {
    printf("opening file %s", argv[1]);
  }

  openFlags = O_CREAT | O_WRONLY | O_TRUNC;

#ifdef SYNC
    openFlags |= O_SYNC;
#endif

  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;      /* rw-rw-rw- */
  
  out = open(argv[2], openFlags, filePerms);
  if (out == -1) {
    printf("opening file %s", argv[2]);
    return 0;
  }

  /* Keep copying until error or EOF */
  while ((numRead = read(inp, buf, BUF_SIZE)) > 0) {
    if (write(out, buf, numRead) != numRead) {
      printf("couldn't write whole buffer");
    }

    if (numRead == -1) {
      printf("read");
    }

    if (close(inp) == -1) {
      printf("close input");
    }

    if (close(out) == -1) {
      printf("close output");
    }
  }
  
  return (0);
}
