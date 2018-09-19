/*
  Exercise Description:
    Write a producer-consumer problem that uses threads and shares a common buffer. However, do not use semaphores or
    any other synchronization primitives to guard the shared data structures. Just let each thread access them when it
    wants to. Use sleep and wakeup to handle the full and empty conditions. See how long it takes for a fatal race
    condition to occur.
    
    For example, you might have the producer print a number once in a while. Do not print more than one number every
    minute because the I/O could affect the race conditions.
   
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_BUFFER_SIZE 200

int buffer=0;  // buffer used between producer and consumer

pthread_mutex_t the_mutex;
pthread_cond_t condc,condp;   // used for signaling

// Produce data
void *producer() {
  int i;
  for (i=1; i<=MAX_BUFFER_SIZE; i++) {
    // get exclusive access to buffer
    pthread_mutex_lock(&the_mutex);

    while (buffer!=0) {
      pthread_cond_wait(&condp,&the_mutex);
    }
    
    // put item in buffer
    buffer = i;

    // print a number (change sleep value to 60 to print once a minute)
    printf("\ni = %i", i);
    sleep(3);

    // wake up consumer
    pthread_cond_signal(&condc);

    // release access to buffer
    pthread_mutex_unlock(&the_mutex);
  }
  pthread_exit(0);
}

// Consume data
void *consumer() {
  for (int i=1; i<=MAX_BUFFER_SIZE; i++) {
    // get exclusive access to buffer
    pthread_mutex_lock(&the_mutex);

    while (buffer==0) {
      pthread_cond_wait(&condc,&the_mutex);
    }

    // take item out of buffer
    buffer = 0;

    // wake up producer
    pthread_cond_signal(&condp);

    // release access to the buffer
    pthread_mutex_unlock(&the_mutex);
  }
  pthread_exit(0);
}

int main() {
  pthread_t prod_thread, cons_thread;
  
  pthread_mutex_init(&the_mutex, 0);
  pthread_cond_init(&condc, 0);
  pthread_cond_init(&condp, 0);

  pthread_create(&cons_thread, 0, consumer, 0);
  pthread_create(&prod_thread, 0, producer, 0);

  pthread_join(prod_thread, 0);
  pthread_join(cons_thread, 0);

  pthread_cond_destroy(&condc);
  pthread_cond_destroy(&condp);

  pthread_mutex_destroy(&the_mutex);

  return 0;
}
