/*
  EXERCISE DESCRIPTION:
    Write a program that creates a linked list containing integers and uses the next functions:
      – a function print_list() that will print out the value of each element
      – a function insert_node() which will insert a new element after some existing element
      – a function delete_node() which will delete a certain element
      
  EXERCISE SOLUTION:
    The following C program implements the above mentioned functions with following specifications:
      - print_list(): This will take head pointer as argument and prints the list in following format:
          HEAD -> 8 -> 2 -> 5 -> 1 -> 3 -> ... -> 12 -> NULL
      
      - insert_node(): This will take head pointer and an integer value as arguments and adds to the end of the list.
      Adding 10 in above list and printing will produce following output:
          HEAD -> 8 -> 2 -> 5 -> 1 -> 3 -> ... -> 12 -> 10 -> NULL
          
      - delete_node(): This will take head pointer and an integer value as arguments and removes the node with data value
      matching the integer argument. Removing node with data value 1 and printing the above list will produce:
          HEAD -> 8 -> 2 -> 5 -> 3 -> ... -> 12 -> 10 -> NULL
          
*/

#include <stdio.h>
#include <stdlib.h>

/* One 'node' struct represents a data value and a pointer to the next data. */
struct node {
  int data;
  struct node *next;
};

/* Inserts a new element at the end of the list */
void insert_node(struct node *head, int value) {
  struct node *current=head;
  
  // the loop is executed until broken from inside.
  while (1) {
    if (!current->next) {
      break;  // break loop as there's no element next to the current, i.e. this is the end of list
    }
    current = current->next;  // go to next element in the list.
  }
  
  current->next = malloc(sizeof(struct node));  // allocate memory for the new data value
  current->next->data = value;
  current->next->next = NULL;
}

/* Deleting an element with specified value, assuming such an element exists in the list. */
void delete_node(struct node *head, int value) {
  struct node *current=head;
  
  // continue checking the elements from beginning
  while (current->next) {
    if (current->next->data == value) {
      // since the node has the data value to be deleted, free that space
      free(current->next);
      
      // remove pointer to it by pointing previous element to the next, thus skipping the current
      current->next = current->next->next;
      
      break;  // exit the loop.
    }
    current = current->next;
  }
}

/* Prints the list elements in the format: HEAD -> 4 -> 5 -> ... -> 7 -> 2 -> NULL */
void print_list(struct node *head) {
  if (head) {
    struct node *current;
    printf("HEAD -> ");
    for (current=head->next; current!=NULL;) {
      printf("%d -> ", current->data);
      current = current->next;
    }
    printf("NULL");
  } else {
    printf("The list is empty!");
  }
}

int main(){
  // Any linked list will have with a HEAD at the front and a NULL at the end.
  struct node *head=NULL;
  head = malloc(sizeof(struct node));

  // Insert elements one by one at the end of the list.
  insert_node(head, 9);
  insert_node(head, 5);
  insert_node(head, 10);
  
  // Remove element with given data value, if found; ignore otherwise.
  delete_node(head, 5);
  
  insert_node(head, 19);
  insert_node(head, 2);
  
  // Print the list elements
  print_list(head);

  return 0;
}
