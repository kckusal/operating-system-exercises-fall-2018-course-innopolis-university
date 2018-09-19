/*
  Exercise Description:
    • Create a program that runs N threads similar to one explained in the tutorial. Each thread should
      output its number and some text, then exit.
    • Main program should inform about thread creation
*/

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 

#define MAX_THREAD_COUNT 5

void *threadInit(void *vargp) {
  int *myid = (int *)vargp;   // take thread_id from argument
  
  sleep(2);
  printf("\nHello world!");

  // exit current thread and free any thread-specific resources it is taking
  pthread_exit(NULL);	
}

int main() {
  // integer value to identify the thread in the system
  pthread_t thread_id; 

  // take input N and check against maximum number of allowed threads as defined above
  int N;
  printf("Enter a value of N (<=%i): ", MAX_THREAD_COUNT);
  scanf("%i",&N);

  if (N>MAX_THREAD_COUNT) {
    printf("Maximum thread count exceeded. Enter a value not greater than %i.", MAX_THREAD_COUNT);
    return 0;
  }

  int rt; // int to store return value

  // creates N threads, each of which will call the function threadInit where the thread Id will be passed as argument
  for (int i=0; i<N; i++) {
    // create a new thread that will execute 'threadInit'
    rt = pthread_create(&thread_id, NULL, threadInit, (void *)&thread_id); 

    if (rt) {   // could not create thread
      printf("\n ERROR: return code from pthread_create is %d \n", rt);
      exit(1);
    }
    
    // main program informs about thread creation
    printf("\nCreated new thread with Id:%d",thread_id);
  } 
  
  // terminate the main program thread
  pthread_exit(NULL);  
  return 0;
}
