/*
* Contributor: Jean Choi
* 
* To compile the program:     gcc -Wall merge_sort.c -o merge_sort
* To run the program:         ./merge_sort
*/

#include<stdio.h>
#include<math.h>

/*
* Function merges two sorted arrays together
*/
void merge(int array[], int lo, int mid, int hi){
  int left_pointer = lo;
  int right_pointer = mid + 1;
  int temp[hi - lo + 1];
  int temp_pointer = 0;

  while(left_pointer <= mid && right_pointer <= hi){
    if(array[left_pointer] <= array[right_pointer]){
      temp[temp_pointer] = array[left_pointer];
      temp_pointer++;
      left_pointer++;
    } else {
      temp[temp_pointer] = array[right_pointer];
      temp_pointer++;
      right_pointer++;
    }
  }

  while(left_pointer <= mid){
    temp[temp_pointer] = array[left_pointer];
    temp_pointer++;
    left_pointer++;
  }

  while(right_pointer <= hi){
    temp[temp_pointer] = array[right_pointer];
    temp_pointer++;
    right_pointer++;
  }

  temp_pointer = 0;
  for(int i = lo; i <= hi; i++){
    array[i] = temp[temp_pointer];
    temp_pointer++;
  }

}

/*
* Recursive function that sorts 1/2 of the original array
*/
void mergesort(int array[], int lo, int hi){
  if (lo >= hi)
    return;

  int mid = (lo + hi)/2;
  mergesort(array, lo, mid);
  mergesort(array, mid+1, hi);
  merge(array, lo, mid, hi);
}

/*
* Main program
*/
int main(){
  printf("To run the program, enter the number of data items and then the data items\n");
  printf("e.g.: 8 35 97 99 48 12 27 103 8\n");

  //get the array size
  int arraysize;
  scanf("%d", &arraysize); 

  //allocate the array, temp array,  and get the values
  int array[arraysize];
  for(int i = 0; i < arraysize; i++){
    scanf("%d", &array[i]);
  }

  printf("\n----- MERGE SORT -----");
  //print given array
  printf("\nHere's the given array:\n");
  for(int i = 0; i < arraysize; i++){
    printf("%d ", array[i]);
  }

  //merge sort
  mergesort(array, 0, arraysize-1);

  //print the sorted array
  printf("\nHere's the sorted array:\n");
  for(int i = 0; i < arraysize; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;  
}
