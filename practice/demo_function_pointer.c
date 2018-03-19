/*
 * demo_function_pointer.c
 */

#include <stdio.h>

/* A pointer to a sorting function */
typedef void (*sort_function_ptr)(int iptr[], int n);

void do_sort(int array[], int n){
  printf(" n is %i \n", n);
  printf(" array[0], array[1] are %i, %i \n", array[0], array[1]);
}

void call_sort(sort_function_ptr sorter, int n, int numbers[]){
  (*sorter)(numbers, n);
}


int main(){

  int n=10;
  int numbers[] = {1,2,3,4,5,6,7,8,9,10};

  call_sort(&do_sort, n, numbers);

  return 0;
}
