/*
* Implementation of singly-linked list
* Nate Weeks, April 2018
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

// function to print a linked nost starting at node n
void printList(struct Node *n){
  while(n != NULL){
    printf(" %d ", n->data);
    n = n->next;
  };
};

int main(){
  // initiate 3 nodes
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
  // allocate memory for the nodes
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
  // define each node
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;
  // print the data in each node seperated by spaces starting with the node head
  printf("this linked list contains: \n");
  printList(head);

  return 0;
};
