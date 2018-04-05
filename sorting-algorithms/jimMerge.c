/***********
 * in_class_merge.c
 *
 * Re-written during Nate's tutorial, based on his work in merge.c.
 *
 * Changes include :
 *   - all function calls take a pointer to the start of an array and its length
 *   - temporary space is declared once, outside of any function
 *   - printing of all parameters to each function call
 *   - compilation and output placed here in the header.
 *
 * Running it looks like this :
 *
 *   $ make in_class_merge
 *   cc     in_class_merge.c   -o in_class_merge
 *   $ ./in_class_merge
 *    main - initial array : [1 4 3 3 2 ]
 *
 *    sort(0x7ffeecbd92c0, 5)
 *      input array: [1 4 3 3 2 ]
 *      left array: [1 4 ]
 *      right array: [3 3 2 ]
 *
 *    sort(0x7ffeecbd92c0, 2)
 *      input array: [1 4 ]
 *      left array: [1 ]
 *      right array: [4 ]
 *
 *    sort(0x7ffeecbd92c0, 1)
 *      input array: [1 ]
 *      size <= 1
 *
 *    sort(0x7ffeecbd92c4, 1)
 *      input array: [4 ]
 *      size <= 1
 *
 *    merge(0x7ffeecbd92c0, 1, 0x7ffeecbd92c4, 1, 0x7ffeecbd92c0, 2)
 *      left = [1 ]
 *      right = [4 ]
 *      destination = [1 4 ]
 *
 *    sort(0x7ffeecbd92c8, 3)
 *      input array: [3 3 2 ]
 *      left array: [3 ]
 *      right array: [3 2 ]
 *
 *    sort(0x7ffeecbd92c8, 1)
 *      input array: [3 ]
 *      size <= 1
 *
 *    sort(0x7ffeecbd92cc, 2)
 *      input array: [3 2 ]
 *      left array: [3 ]
 *      right array: [2 ]
 *
 *    sort(0x7ffeecbd92cc, 1)
 *      input array: [3 ]
 *      size <= 1
 *
 *    sort(0x7ffeecbd92d0, 1)
 *      input array: [2 ]
 *      size <= 1
 *
 *    merge(0x7ffeecbd92cc, 1, 0x7ffeecbd92d0, 1, 0x7ffeecbd92cc, 2)
 *      left = [3 ]
 *      right = [2 ]
 *      destination = [2 3 ]
 *
 *    merge(0x7ffeecbd92c8, 1, 0x7ffeecbd92cc, 2, 0x7ffeecbd92c8, 3)
 *      left = [3 ]
 *      right = [2 3 ]
 *      destination = [2 3 3 ]
 *
 *    merge(0x7ffeecbd92c0, 2, 0x7ffeecbd92c8, 3, 0x7ffeecbd92c0, 5)
 *      left = [1 4 ]
 *      right = [2 3 3 ]
 *      destination = [1 2 3 3 4 ]
 *
 *   main - sorted array : [1 2 3 3 4 ]
 *
 * Jim Mahoney | March 29 2018
 ***********/

#include <stdio.h>
#include <stdlib.h>

#define half_max_size 10000

int temp1[half_max_size];
int temp2[half_max_size];

void printArray(int* array, int size){
  // print array[0] through array[size-1] e.g. "[10 11 12 ]"
  int i;
  printf("[");
  for(i=0; i<size; i++){
    printf("%d ", array[i]);
  }
  printf("]\n");
};

void merge(int* left_array, int left_size,
	   int* right_array, int right_size,
	   int* destination_array, int destination_size){
  // merge two already-sorted arrays left & right into the destination array,
  // using temp1 and temp2 buffers as temporary space.
  // It's OK if destination overlaps left and/or right in memory.

  int i, j, k;  // (left, right, destination) indices.

  printf(" merge(%p, %i, %p, %i, %p, %i) \n",
    left_array, left_size,
    right_array, right_size,
    destination_array, destination_size);
  printf("   left = ");
  printArray(left_array, left_size);
  printf("   right = ");
  printArray(right_array, right_size);

  // copy left and right to temporary storage
  for (i=0; i<left_size; i++){ temp1[i] = left_array[i]; }
  for (j=0; j<right_size; j++){ temp2[j] = right_array[j]; };

  i = j = k = 0;

  // move smallest item from either left or right to destination.
  while(i < left_size && j < right_size){
    if (temp1[i] <= temp2[j]){
      destination_array[k] = temp1[i];
      i++;
    } else {
      destination_array[k] = temp2[j];
      j++;
    };
    k++;
  };

  // move remaining elements in left or right.
  while(i < left_size){
    destination_array[k] = temp1[i];
    i++;
    k++;
  };
  while(j < right_size){
    destination_array[k] = temp2[j];
    j++;
    k++;
  };

  printf("   destination = ");
  printArray(destination_array, destination_size);
  printf("\n");
};

void sort(int* array, int size){
  // sort in place [array[0] ... array[size-1]]
  int left_size, right_size;
  int *left_array, *right_array;

  printf(" sort(%p, %i)\n", array, size);
  printf("   input array: ");
  printArray(array, size);

  if (size > 1){
    left_size = size / 2;
    left_array = array;
    printf("   left array: ");
    printArray(left_array, left_size);

    right_size = size - left_size;
    right_array = array + left_size;    //   <==  pointer arithmetic !
    printf("   right array: ");
    printArray(right_array, right_size);

    printf("\n");

    sort(left_array, left_size);
    sort(right_array, right_size);

    merge(left_array, left_size,
	  right_array, right_size,
	  array, size);
  }
  else {
    printf("   size <= 1\n\n");
  }
};

int main(){
  int size = 5;
  int array[] = {1, 4, 3, 3, 2};

  printf("main - initial array : ");
  printArray(array, size);
  printf("\n");

  sort(array, size);

  printf("main - sorted array : ");
  printArray(array, size);
  printf("\n");

  return 0;
};
