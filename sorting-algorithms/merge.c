#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
    printf("\n");
  };
};

// arr being the array to be sorted, start, mid and end the indexes
// of the array to be subdivided at
void merge(int arr[], int start, int mid, int end){

  // initial indexes
  int i, j, k;

  // size of temp arrays
  int lengthl = mid - 1 + 1;
  int lengthr = end - mid;

  // temp arrays
  int left[lengthl];
  int right[lengthr];


// populate the temporary arrays
  for(i=0; i<lengthl; i++){
    left[i] = arr[start + i];
  };
  for(j=0; j<lengthr; j++){
    right[j] = arr[mid + j];
  };
  // printArray(left, 7);
  // printArray(right, 7);
  // printf("%d\n", lengthr);

//starting indexes for merging
  i = 0; // first subarray
  j = 0; // second subarray
  k = start; // merged subarray
//add smallest item from the sub-arrays to the sorted array
  while(i < lengthl && j < lengthr){
    if(left[i] <= right[j]){
      arr[k] = left[i];
      i++;
    }else{
      arr[k] = right[j];
      j++;
    };
    k++;
  };
//handle for leftover elements when one sub-array is out of elements
  while(i < lengthl){
    arr[k] = left[i];
    i++;
    k++;
  };

  while(j < lengthr){
    arr[k] = right[j];
    j++;
    k++;
  };
  printArray(arr, 7);
};

void sort(int arr[], int low, int high){
  int mid;
  if(low < high){
    mid = low + (high - low) / 2;
    sort(arr, low, mid);
    sort(arr, mid+1, high);
    merge(arr, low, mid, high);
  };
};

int main(){
  int arr[] = {1,4,2,6,9,8,5};
  printf("array is: \n");
  printArray(arr, 7);
  sort(arr, 0, 6);
  // merge(arr, 0, 4, 7);
  printf("sorted array is: \n");
  printArray(arr, 7);
  return 0;
};
