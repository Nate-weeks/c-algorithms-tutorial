#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printKids(char *kids[], int length){
  int i;
  for (i=0;i<length;i++){
    printf("%s \n", kids[i]);
  }
}

int main(){
  char *kids[] = {"Option 1", "Option 2"};
  int length = 2;
  printKids(kids, length);
  return 0;
}

node addChild(node person, char *title[], int amount){
  int i;
  for (i=0;i<amount;i++){
    node child = newNode(title[i]);
    person->children[i] = child;
    person->children[i]->father = person;
    person->children[i]->mother = person->spouse;
  }
  person->child_amount += amount;
}
//
// char *kids[] = {"kid1", "kid2", "kid3"};
// int amount = 3;
// addChildren(nate, kids, amount);

// void printFamily(node patriarch){
//   printf("name: %s ", patriarch->name);
//   printf("spouse: %s children: ", patriarch->spouse->name);
//   // printf("child: %s", patriarch->children[patriarch->child_amount - 1]->name);
//   int i = patriarch->child_amount;
//   if(i > 0){
//     printFamily(patriarch->children[i - 1]);
//     i = i - 1;
//   }
// }
