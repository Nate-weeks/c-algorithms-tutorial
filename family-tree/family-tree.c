/*
* Implementation of a family tree in c
* Nate Weeks, April 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// basic family tree structure with a pointer to an array of children
typedef struct _node *node;
struct _node{
  char name[20];
  int child_amount;
  struct _node *mother;
  struct _node *father;
  struct _node *spouse;
  struct _node **children;
};

// initiate a new node with the name of the person
node newNode(char *title){
  // set aside memory for the node and the child nodes
  node person = malloc(sizeof(struct _node));
  person->children = malloc(sizeof(struct _node) * 10);
  // initial values
  strncpy(person->name, title, 20);
  person->mother = NULL;
  person->father = NULL;
  person->spouse = NULL;
  int child_amount = 0;
  return(person);
};

// print each member of a family directly connected to one family node
void printNode(node person){
  int i = 0;
  printf("name: %s ", person->name);
  printf("father: %s ", person->father->name);
  printf("mother: %s ", person->mother->name);
  printf("wife: %s ", person->spouse->name);
  // loop through and print the children
  for(i=0;i<person->child_amount;i++){
    printf("kid: %s ", person->children[i]->name);
  };
};

// create a buncha nodes related to me and set up some relationships
int main(){
  // char title[] = "nate";
  node nate = newNode("nate");
  node laurie = newNode("laurie");
  node greg = newNode("greg");
  node wifey = newNode("wifey");
  node child1 = newNode("child1");
  node child2 = newNode("child2");
  nate->mother = laurie;
  nate->father = greg;
  nate->spouse = wifey;
  nate->children[0] = child1;
  nate->children[1] = child2;
  nate->child_amount = 2;
  printNode(nate);
  return 0;
}
