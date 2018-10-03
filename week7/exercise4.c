/*
  EXERCISE DESCRIPTION:
    Write your own realloc() function using malloc() and free()
      – realloc() changes the size of the memory block pointed to by ptr to size bytes. The contents will be unchanged
        to the minimum of the old and new sizes
      – Newly allocated memory will be uninitialized
      – If ptr is NULL, the call is equivalent to malloc(size)
      – If size is equal to zero, the call is equivalent to free(ptr)
      – Unless ptr is NULL, it must have been returned by an earlier call to malloc(), calloc() or realloc()
      
*/
