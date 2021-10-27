//Selection Sort //dontbeasalad
#include <stdio.h>
int selectionSort(int arr[], int n){
  int i, j, posisi, swap;
  for(i = 0; i < (n-1); i++){
    posisi = i;
    for (j = i + 1; j < n; j++){
      if(arr[posisi] > arr[j]){
        posisi = j;
      }
    }
    if(posisi != i){
      swap = arr[i];
      arr[i] = arr[posisi];
      arr[posisi] = swap;
    }
  }
}
int main(){
  int array[100], n, i, j;
  printf("Masukkan banyaknya jumlah data: ");
  scanf("%d", &n);
  printf("Masukkan data sebanyak %d :\n", n);
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  selectionSort(array, n);
  printf("Hasil pengurutan sebagai berikut:\n");
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}
