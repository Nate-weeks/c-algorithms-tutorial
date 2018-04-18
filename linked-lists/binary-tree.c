/*
*  implementation of a binary tree
*  Nate Weeks, April 2018
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* newNode(int data)
{
  // Allocate memory for new node
  struct node* node = (struct node*)malloc(sizeof(struct node));

  // Assign data to this node
  node->data = data;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

// function to traverse and print a binary tree starting at root node
void leftToRight(struct node* node){
// base case - return if node == NULL
  if (node == NULL){
    return;
  };
// call on left node
  leftToRight(node->left);
// print data in nodes
  printf("%d ", node->data);
// call on right node
  leftToRight(node->right);
}

int main()
{
  /*create root node*/
  struct node *root = newNode(1);


  root->left        = newNode(2);
  root->right       = newNode(3);
  // 2 and 3 become left and right children of 1



  root->left->left  = newNode(4);
  // 4 becomes left child of 2

  printf("binary in order left to right: \n");
  // print the binary tree from left to right
  leftToRight(root);

  return 0;
}
