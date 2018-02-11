#include <stdio.h>


void insertionSort(int arr[], int n){
  int i, x, j;
  for (i = 1; i < n; i++){
    x = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > x){
      arr[j+1] = arr[j];
      j -= 1;
    };
    arr[j+1] = x;
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
  insertionSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
};
