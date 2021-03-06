/*    selection.c - a sorting algorithm
      by Nate Weeks
*/

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#include "sorting.h"

typedef void(*sort_function_ptr)(int aptr[], int n);


void printArray(int arr[], int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
  };
};

//populate an array of a given length with randomly generated numbers
void createArray(int arr[], int size){
  int i;
  for(i=0; i<size; i++){
    arr[i] = rand();
  }
}

/* function to call every other function and output the time taken to sort an
array from least to greatest */
double functionCaller(sort_function_ptr sorter, int size){
  int random[size];
  createArray(random, size);        // create an array random, populated with random numbers of a given length size
  // printArray(random, 1000000);

// initiate variables to keep track of time
  struct timeval start, stop;
  double secs = 0;

// function to wrap selectionSort in a timer and run selectionSort on a array random of a given length - size
  gettimeofday(&start, NULL);
  (*sorter)(random, size);
  gettimeofday(&stop, NULL);

// Output the time time taken
  secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
  // FILE *f = fopen("insertion.txt", "a");
  // fprintf(f, "time taken for array size %d: %f\n", size, secs);           // write output to file
  // printf("time taken for array size %d: %f\n", size, secs);
  // printf("Sorted array: \n");
  // printArray(random, n);
  return secs;
}

int main(){
  int i;
  double selection = 0; // counter for seconds selectionsort takes
  double insertion = 0; // counter for seconds insertionSort takes
  double bubble = 0;    // counter for seconds bubbleSort takes
  int n = 100;
  int size = 100;
  //int n = 100;            // number of times sort function is run
  // int size = 100;         // size is the size of the random array
  // printf("please enter the number of random arrays you would like to generate and sort:\n");
  // scanf("%d", &n);
  // printf("you chose %d\n", n);
  // printf("please enter the size of the arrays you would like to generate: \n");
  // scanf("%d", &size);
  // printf("you chose %d\n", size);
  srand(time(NULL));      // seed random number generator
  for (size=10; size<100; size=size*3){    // loop that calls functionCaller with each function
    for (i=0; i<n; i++){                   // for arrays under 100 size each 3 times bigger than last
      selection += functionCaller(&selectionSort, size);  // add to a counter the amount of seconds each sort took
      insertion += functionCaller(&insertionSort, size);
      bubble += functionCaller(&bubbleSort, size);
    }
    printf("selection,%d,%f\n", size, selection/n);  // print the average time over 100 tries running the sort
    printf("insertion,%d,%f\n", size, insertion/n);
    printf("bubble,%d,%f\n", size, bubble/n);
  }
  return 0;
};
