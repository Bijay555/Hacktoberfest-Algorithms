/*
SELECTION SORT:
#include<stdio.h>
int main()
{
   int i, j, r, temp, num[25];
   printf("Enter the number of intervals: ");
   scanf("%d",&r);
   printf("Enter %d Price: \n", r);
   for(i=0;i<r;i++)
    {
        scanf("%d",&num[i]);
    }  
   for(i=0;i<r;i++)
   {
      for(j=i+1;j<r;j++)
      {
        if(num[i]>num[j])
         {
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
            swap=swap+1;
         }
      }
   }
   printf("Sorted Price: ");
   for(i=0;i<r;i++)
    {
      printf("%d\t",num[i]);
    }
}
*/


/*
INSERTION SORT:
#include<stdio.h>
int main()
{
   int i, j,swap=0, r, temp, num[25];
   printf("Enter the number of intervals: ");
   scanf("%d",&r);
   printf("Enter %d Price: \n", r);
   for(i=0;i<r;i++)
    {
        scanf("%d",&num[i]);
    }  
    
    for(i=1;i<r;i++)
    {
      temp=num[i];
      j=i-1;
      while((temp<num[j])&&(j>=0))
        {
            num[j+1]=num[j];
            j=j-1;
            swap=swap+1;
        }
      num[j+1]=temp;
   }
   printf("Sorted Price: ");
   for(i=0;i<r;i++)
    {
      printf("%d\t",num[i]);
    }
    printf("\nSwaps:%d",swap);
}
*/

/*
MERGE SORT
#include <stdio.h> 
#include <stdlib.h> 
int merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	int L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		{L[i] = arr[l + i];}
	for (j = 0; j < n2; j++) 
		{R[j] = arr[m + 1 + j]; }
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else
 { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
int mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) { 
		int m = l + (r - l) / 2; 
		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 
		merge(arr, l, m, r); 
	} 
} 
int show(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
	{
		printf("%d ", A[i]); 
	}
	printf("\n"); 
} 
int main() 
{ 
	 
	int n;
	int arr[100];
	printf("Range: ");
	scanf("%d",&n);
	printf("Enter The Values: ");
	for(int i=0; i<n; i++)
	{
	    scanf("%d",&arr[i]);
	}
	
	printf("Value Given is: \n"); 
	show(arr, n); 
	mergeSort(arr, 0, n - 1); 
	printf("\nMerge Sorted Values is: \n"); 
	show(arr, n); 
}
*/

/*
QUICK SORT
#include<stdio.h> 
int swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
int pt(int arr[], int low, int high) 
{ 
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++;
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 
int qs(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = pt(arr, low, high); 
		qs(arr, low, pi - 1); 
		qs(arr, pi + 1, high); 
	} 
} 
int show(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 
 
int main() 
{ 
	int n;
	int arr[100];
	printf("Range: ");
	scanf("%d",&n);
	printf("Enter The Values: ");
	for(int i=0; i<n; i++)
	{
	    scanf("%d",&arr[i]);
	}
	printf("Value Given is: \n"); 
	show(arr, n); 
	qs(arr, 0, n-1); 
	printf("Quick Sorted : \n"); 
	show(arr, n); 
	return 0; 
}
*/
