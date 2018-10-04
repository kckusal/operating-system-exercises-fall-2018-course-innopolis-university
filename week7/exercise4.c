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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Custom realloc function. */
void *custom_realloc(void *ptr, size_t malloc_size, size_t size) {
  void *temp;
  
  if (ptr==NULL) {
    temp = malloc(size);
    if (temp == NULL) goto error;
  } else {
    if (size==0) {
      free(ptr);
    } else {
      if (malloc_size < size) {
        temp = malloc(size);
        
        if (temp == NULL) goto error;
        
        memcpy(temp, ptr, malloc_size);
        free(ptr);
      } else {
        temp = ptr;
      }
    }
  }
  
  return temp;
  
  error:
    return NULL;
}

/* Main driver function */
int main(){
	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

  size_t malloc_size = n1 * sizeof(int);
	//Create a new array of n1 ints
	int* a1 = malloc(malloc_size); /* Fill in*/
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;  /*Fill in*/
		
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i] ); /*Fill in*/
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = custom_realloc(a1, malloc_size, n2 * sizeof(int));  /* Fill in*/

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

  if (n2>n1) {
    for(i=n1; i<n2; i++) {
      a1[i] = 0;
    }
  }
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);  /*Fill in*/
	}
	printf("\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
