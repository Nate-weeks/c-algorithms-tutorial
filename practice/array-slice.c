#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int arr[], int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
  };
};

int *slice_array(int *array, int start, int end){
  int numberElements = (end - start + 1);
  int numberBytes = sizeof(int) * numberElements;

  int *slice = malloc(numberBytes);
  memcpy(slice, array + start, numberBytes);

  // printArray(slice, 6);

  return slice;
}

// void mergeSort(int arr[], int n){
//   int mid = n/2;
//   int *leftHalf = slice_array(arr, 0, mid-1);
//   int *rightHalf = slice_array(arr, mid, n-1);
//   printf("left half: ");
//   printArray(leftHalf, mid + 4);
//   printf("right half: ");
//   printArray(rightHalf, mid + 4);
// }

int main(){
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int *x = slice_array(arr, 2, 6);
  printArray(x, 6);
  return 0;
}
