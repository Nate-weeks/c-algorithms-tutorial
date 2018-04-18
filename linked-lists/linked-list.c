/*
* Implementation of singly-linked list
* Nate Weeks, April 2018
*/

#include <stdio.h>
#include <stdlib.h>

// defining node as a pointer to a Node struct
typedef struct Node *node;
struct Node{
  int data;
  struct Node *next;
};

//defining list as a pointer to a struct node_list
typedef struct node_list *list;
struct node_list{
  int length;
  struct Node *first;
  struct Node *last;
};

// typedef struct binary_tree_node *bt_node;
// struct binary_tree_node{
//   int data;
//   struct binary_tree_node *left;
//   struct binary_tree_node *right;
// };

// function to print a linked list l starting at the first node
void printList(list l){
  node n = l->first;    // n = first node
  while(n != NULL){
    printf(" %d ", n->data);
    n = n->next;
  };
};

// function to return a list struct with first and last node initiated as NULL and length 0
list createList(){
  list new_list = (list)malloc(sizeof(struct node_list));
  new_list->length = 0;
  new_list->first = NULL;
  new_list->last = NULL;
  return new_list;
};

// function to return a node object storing data of a given int number
node createNode(int number){
  node n = (node)malloc(sizeof(struct Node));
  n->data = number;
  n->next = NULL;
  return n;
};

// function to push a given node n into the end of a given list l
void push(list l, node n){
  if(l->length == 0){
    l->first = n;
    l->last = n;
    l->length = 1;
  } else {
    l->last->next = n;
    l->last = n;
    l->length++;
  }
}

// insert a new node n, with data - int data- after node prev
void insertAfter(node prev, int data){
  node n = createNode(data);
  n->next = prev->next;
  prev->next = n;
}

// void insert_tree(list l){
//   count = 0;
//   l->first = n;
// }

int main(){
  // create and allocate memory for the linked-list
  list new_list = createList();
  // create and allocate memory for the nodes
  node head = createNode(1);
  node second = createNode(2);
  node third = createNode(4);
  // push each node into a list
  push(new_list, head);
  push(new_list, second);
  push(new_list, third);
  // insert a node after the second node
  insertAfter(second, 3);
  // print the data in each node seperated by spaces starting with the node head
  printf("this linked list contains: \n");
  printList(new_list);

  return 0;
};
