// by- Chidambar Joshi (Chidu2000)

/* Simple Merge Sort Program Using Functions and Array in C*/
// data structure

// header files
#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 5    // max. size of array as global declaration

// function declarations
void merge_sort(int, int);
void merge_array(int, int, int, int);

int arr_sort[MAX_SIZE];  // array initialization

// main function
int main() {
  int i;

  printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)    // taking input into array to apply sort
    scanf("%d", &arr_sort[i]);

  
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);      // printing the fed data
  }

  merge_sort(0, MAX_SIZE - 1);   // function call

  printf("\n\nSorted Data :");
  for (i = 0; i < MAX_SIZE; i++) {               // printing all sorted elements
    printf("\t%d", arr_sort[i]);
  }
  getch();

}

// merge sort implementation
void merge_sort(int i, int j) {
  int m;

  if (i < j) {
    m = (i + j) / 2;
    merge_sort(i, m);
    merge_sort(m + 1, j);
    // Merging two arrays
    merge_array(i, m, m + 1, j);
  }
}


// merge array function implementation
void merge_array(int a, int b, int c, int d) {
  int t[50];
  int i = a, j = c, k = 0;

  while (i <= b && j <= d) {
    if (arr_sort[i] < arr_sort[j])
      t[k++] = arr_sort[i++];
    else
      t[k++] = arr_sort[j++];
  }

  //collect remaining elements 
  while (i <= b)
    t[k++] = arr_sort[i++];

  while (j <= d)
    t[k++] = arr_sort[j++];

  for (i = a, j = 0; i <= d; i++, j++)
    arr_sort[i] = t[j];
}
