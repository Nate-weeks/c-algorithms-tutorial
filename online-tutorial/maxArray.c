#include <stdio.h>

// int max(int arr1[], int arr2[]);

int main(){

  int a[] = {5,7,9,3};
  int i;
  int j = 0;

  for (i = 0; i<sizeof(a)/sizeof(a[0]); i++){
    if (a[i] > j){
      j = a[i];
    };
  };

  printf("the largest number in this array is:  %d\n", j);
}
