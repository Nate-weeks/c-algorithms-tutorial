#include <stdlib.h>

#include "sorting.h"

// sort an array of length n
void insertionSort(int arr[], int n){
  int i, key, j;
  for (i = 1; i < n; i++){                // n = length
    key = arr[i];                         // key = number to be compared with j
    j = i - 1;                            // j = number to be swapped
    while(j >= 0 && arr[j] > key){        // swap the key down the array while arr[j] is less
      arr[j+1] = arr[j];
      j -= 1;
    };
    arr[j+1] = key;
  };
};
