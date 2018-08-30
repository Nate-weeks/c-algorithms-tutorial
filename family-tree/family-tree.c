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
  node mother;
  node father;
  node spouse;
  node *children;
};

// initiate a new node with the name of the person
node newNode(char *title){
  // set aside memory for the node and the child nodes
  node person = malloc(sizeof(struct _node));
  person->children = malloc(sizeof(node) * 10);
  // initial values
  strncpy(person->name, title, 20);
  person->mother = NULL;
  person->father = NULL;
  person->spouse = NULL;
  int child_amount = 0;
  return person;
};

// add a child to the tree and set parent/child relationships
void addChild(node father, node child){
  father->children[father->child_amount] = child;
  child->father = father;
  child->mother = father->spouse;
  father->child_amount = father->child_amount + 1;
}

// print each member of a family directly connected to one family node
void printNode(node person){
  int i = 0;
  printf("name: %s ", person->name);
  printf("father: %s ", person->father->name);
  printf("mother: %s ", person->mother->name);
  printf("wife: %s ", person->spouse->name);
  // loop through and print the children
  if(person->child_amount > 0){
    for(i=0;i<person->child_amount;i++){
      printf("kid: %s ", person->children[i]->name);
    };
  };
};

//function to traverse the family tree and print each member with a depth counter
void printFamily(node patriarch, int whitespace){
  int i, j;
  for(j=0;i<whitespace;i++){
    printf(" ");
  };
  printf("%s ", patriarch->name);
  if(patriarch->spouse != NULL){
    printf("Spouse: %s", patriarch->spouse->name);
  };
  printf("\n");
  if(patriarch->child_amount == 0){
    return;
  };
  // recursively call this function on each child
  for(i=0;i<patriarch->child_amount;i++){
    printFamily(patriarch->children[i], whitespace + 2);
  };
};


// create a buncha nodes related to me and set up some relationships
int main(){
  node nate = newNode("nate");
  node laurie = newNode("laurie");
  node greg = newNode("greg");
  node caitlin = newNode("caitlin");
  node wifey = newNode("wifey");
  node child1 = newNode("child1");
  node child2 = newNode("child2");
  node childOfChild1 = newNode("childOfChild1");
  caitlin->father = greg;
  greg->children[1] = caitlin;
  nate->mother = laurie;
  nate->father = greg;
  nate->father->spouse = laurie;
  greg->children[0] = nate;
  greg->child_amount = 2;
  nate->spouse = wifey;
  nate->children[0] = child1;
  nate->children[1] = child2;
  nate->child_amount = 2;
  child1->father = nate;
  child2->father = nate;
  child1->children[0] = childOfChild1;
  childOfChild1->father = child1;
  child1->child_amount = 1;
  node childOfChildOfChild1 = newNode("childOfChildOfChild1");
  addChild(childOfChild1, childOfChildOfChild1);
  // printNode(nate);
  printFamily(greg, 1);
  return 0;
}
