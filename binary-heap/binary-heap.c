/*
*  implementation of a binary heap
*  Nate Weeks, April 2018
*/

#include <stdio.h>
#include <stdlib.h>

// definitions for left child, right child and parent nodes
#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct node{
  int data;
} node;

typedef struct minHeap {
  int size;
  node *elem;
} minHeap;

// initialize minHeap with default values
minHeap initMinHeap() {
  minHeap hp;
  hp.size = 0;
  return hp;
}

// insert node into minHeap with int data
void insertNode(minHeap *hp, int data){
  // allocating space
  if(hp->size){
    hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node));
  } else{
    hp->elem = malloc(sizeof(node));
  }

  // initializing the node with value
  node nd;
  nd.data = data;

  // positioning the node at the right position in the min heap
  int i = (hp->size)++ ;  // i++ because we are adding an element - last index
  while(i && nd.data < hp->elem[PARENT(i)].data) {
    hp->elem[i] = hp->elem[PARENT(i)] ;  // move node up the line until it fits
    i = PARENT(i) ;
  }
  hp->elem[i] = nd;  // set node
}

// function to swap two nodes
void swap(node *n1, node *n2) {
  node temp = *n1;
  *n1 = *n2 ;
  *n2 = temp ;
}

// recursive function to check which of parent, LCHILD and RCHILD are smaller, then swap
void heapify(minHeap *hp, int i) {
  // set smallest to equal the smaller number between parent and LCHILD - i = index of parent
  int smallest = (LCHILD(i) < hp->size && hp->elem[LCHILD(i)].data < hp->elem[i].data) ? LCHILD(i) : i;
  // set smallest to equal the smaller number between smallest and RCHILD
  if(RCHILD(i) < hp->size && hp->elem[RCHILD(i)].data < hp->elem[i].data) {
    smallest = RCHILD(i);
  }
  // if smallest is not the parent, swap and run heapify on the swapped index
  if(smallest != i) {
    swap(&(hp->elem[i]), &(hp->elem[smallest]));
    heapify(hp, smallest);
  }
}

// function to delete first element in minHeap
void deleteNode(minHeap *hp) {
  // if the minHeap has a size, delete first element
  if(hp->size) {
    printf("Deleting node %d\n\n", hp->elem[0].data);
    hp->elem[0] = hp->elem[--(hp->size)]; // set first elem to equal the last elem
    hp->elem = realloc(hp->elem, hp->size * sizeof(node)); // reallocate memory 1 less
    heapify(hp, 0);  // call heapify on the new root element
  } else {
    printf("\nMin Heap is empty!\n");
    free(hp->elem);   // free if empty
  }
}

// function to traverse the minHeap by printing the array
void levelOrderTraversal(minHeap *hp) {
  int i;
  printf("min heap: ");
  for(i = 0; i<hp->size; i++) {
    printf("%d ", hp->elem[i].data);
  }
  printf("\n");
}

int main(){
  //initialize minheap
  minHeap hp = initMinHeap();
  // insert some elements
  insertNode(&hp, 1);
  insertNode(&hp, 7);
  insertNode(&hp, 2);
  insertNode(&hp, 3);
  insertNode(&hp, 8);
  insertNode(&hp, 4);
  insertNode(&hp, 6);
  // print and delete all elements 1 by 1
  levelOrderTraversal(&hp);
  deleteNode(&hp);
  levelOrderTraversal(&hp);
  deleteNode(&hp);
  levelOrderTraversal(&hp);
  deleteNode(&hp);
  levelOrderTraversal(&hp);
  deleteNode(&hp);
  levelOrderTraversal(&hp);
  deleteNode(&hp);
  levelOrderTraversal(&hp);
  deleteNode(&hp);
  levelOrderTraversal(&hp);
  deleteNode(&hp);
  levelOrderTraversal(&hp);
  deleteNode(&hp);

  return 0;
}
