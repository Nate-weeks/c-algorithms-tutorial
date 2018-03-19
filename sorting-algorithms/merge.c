#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

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
  int i, j, k;
  int lengthr = end - mid;
  int lengthl = mid - 1 + 1;
  int left[mid];
  int right[lengthr];


// populate the temporary arrays
  for(i=0; i<mid; i++){
    left[i] = arr[start + i];
  };
  for(j = 0; j < lengthr; j++){
    right[j] = arr[mid + start + j];
  };

//starting indexes for merging
  i = 0;
  j = 0;
  k = 0;
//add smallest item from the sub-arrays to the sorted array
  while(i < mid && j < lengthr){
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
  while(i < mid){
    arr[k] = left[i];
    i++;
    k++;
  };

  while(j < lengthr){
    arr[k] = right[j];
    j++;
    k++;
  };

};

void sort(int arr[], int low, int high){
  int mid;
  if(low < high){
    mid = (low +high) / 2;
    sort(arr, low, mid);
    sort(arr, mid+1, high);
    merge(arr, low, mid, high);
  };
};

int main(){
  int arr[] = {1,4,2,6,9,8,5};
  printArray(arr, 7);
  sort(arr, 0, 6);
  printArray(arr, 7);
  return 0;
};



// //populate an array of a given length with randomly generated numbers
// void createArray(int arr[], int size){
//   int i;
//   for(i=0; i<size; i++){
//     arr[i] = rand();
//   }
// }
//
// /* function to call every other function and output the time taken to sort an
// array from least to greatest */
// double functionCaller(int size){
//   int random[size];
//   createArray(random, size);        // create an array random, populated with random numbers of a given length size
//   // printArray(random, 1000000);
//
// // initiate variables to keep track of time
//   struct timeval start, stop;
//   double secs = 0;
//
// // function to wrap selectionSort in a timer and run selectionSort on a array random of a given length - size
//   gettimeofday(&start, NULL);
//   sort(random, 0, size);
//   gettimeofday(&stop, NULL);
//
// // Output the time time taken
//   secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
//   // FILE *f = fopen("insertion.txt", "a");
//   // fprintf(f, "time taken for array size %d: %f\n", size, secs);           // write output to file
//   // printf("time taken for array size %d: %f\n", size, secs);
//   // printf("Sorted array: \n");
//   // printArray(random, n);
//   return secs;
// }
//
// int main(){
//   int i, j;
//   double count = 0;
//   int n = 100;
//   int size = 10;
//   //int n = 100;            // number of times sort function is run
//   // int size = 100;         // size is the size of the random array
//   // printf("please enter the number of random arrays you would like to generate and sort:\n");
//   // scanf("%d", &n);
//   // printf("you chose %d\n", n);
//   // printf("please enter the size of the arrays you would like to generate: \n");
//   // scanf("%d", &size);
//   // printf("you chose %d\n", size);
//   srand(time(NULL));      // seed random number generator
//   for (size=10; size<22000; size=size*3){    // call functionCaller n times for each number size * 3 under 22,000
//     for (i=0; i<n; i++){
//       count += functionCaller(size);  // create a random array, sort it, and output the time taken
//     }
//   printf("selection,%d,%f\n", size, count/n);
//   }
//   return 0;
// };
