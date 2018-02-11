#include <stdio.h>

void swap(int *xp, int *yp){
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
};

void selectionSort(int arr[], int n){
  int i, j, min_index;
  for (i = 0; i < n-1; i++){
    min_index = i;
    for (j = i + 1; j < n; j++){
      if (arr[j] < arr[min_index]){
        min_index = j;
      };
    swap(&arr[min_index], &arr[i]);
    };
  };
};

void printArray(int arr[], int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
  };
};

int main(){
  int arr[] = {54, 25, 33, 18, 4, 45, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
};
