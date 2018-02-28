#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

void swap(int *xp, int *yp){
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
        swap(&arr[j], &arr[j+1]);
      };
    };

  };
};

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
void functionCaller(int size){
  int random[size];
  createArray(random, size);        // create an array random, populated with random numbers of a given length size
  // printArray(random, 1000000);

// initiate variables to keep track of time
  struct timeval start, stop;
  double secs = 0;

// function to wrap selectionSort in a timer and run selectionSort on a array random of a given length - size
  gettimeofday(&start, NULL);
  bubbleSort(random, size);
  gettimeofday(&stop, NULL);

// Output the time time taken
  secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
  FILE *f = fopen("bubble.txt", "a");
  fprintf(f, "time taken for array size %d: %f\n", size, secs);           // write output to file
  printf("time taken for array size %d: %f\n", size, secs);
  // printf("Sorted array: \n");
  // printArray(random, n);
}

int main(){
  int i;
  int n = 0;
  int size = 0;
  //int n = 100;            // number of times sort function is run
  // int size = 100;         // size is the size of the random array
  printf("please enter the number of random arrays you would like to generate and sort:\n");
  scanf("%d", &n);
  printf("you chose %d\n", n);
  printf("please enter the size of the arrays you would like to generate: \n");
  scanf("%d", &size);
  printf("you chose %d\n", size);
  srand(time(NULL));      // seed random number generator
  for (i=0; i<n; i++){
    functionCaller(size);  // create a random array, sort it, and output the time taken
  }
  return 0;
};
