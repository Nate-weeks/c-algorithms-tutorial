/*
 * time.c
 *
 * return time, eh?
 */

#include <time.h>
#include <stdio.h>

int main(){
  int t;
  t = time(NULL);
  printf(" The time is %i \n", t);
  return 0;
}
