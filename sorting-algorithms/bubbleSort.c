#include <stdlib.h>

#include "sorting.h"

// function to swap 2 values
void swap2(int *xp, int *yp){
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
};

// sort a given array arr[] with length n from least to greatest
void bubbleSort(int arr[], int n){
  int i, j;
  for (i = 0; i < n; i++){
    for (j = 0; j < n - i - 1; j++){   // iterate through array 1 less slot each loop
      if (arr[j] > arr[j+1]){          // swap the largest number from left to right
        swap2(&arr[j], &arr[j+1]);
      };
    };

  };
};
