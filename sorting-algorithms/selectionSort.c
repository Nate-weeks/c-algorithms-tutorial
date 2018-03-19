#include <stdlib.h>

#include "sorting.h"

// function to swap 2 values
void swap(int *xp, int *yp){
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
};
// sort an array of length n
void selectionSort(int arr[], int n){
  int i, j, min_index;              // i = index, j = sub-index
  for (i = 0; i < n-1; i++){
    min_index = i;                  // set the index to be compared with the rest of the array to i
    for (j = i + 1; j < n; j++){    // loop through the indices greater than i
      if (arr[j] < arr[min_index]){
        min_index = j;                // shift the min_index to j if arr[j] is smaller than arr[min_index]
      };
    swap(&arr[min_index], &arr[i]);   // swap the value at arr[min_index] and arr[i]
    };
  };
};
