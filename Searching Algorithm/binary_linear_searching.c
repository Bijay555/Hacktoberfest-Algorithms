/*
BINARY SEARCH USING BUBBLE SORT
#include <stdio.h> 
#include <stdlib.h> 
int merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	
	int L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
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
int bs(int arr[], int l, int r, int x) 
{ 
    if (r >= l)
    {
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x)
        {
            return mid; 
        }
        if (arr[mid] > x)
        {
            return bs(arr, l, mid - 1, x); 
        }
        else
        {
            return bs(arr, mid + 1, r, x); 
        }
    } 
    return -1; 
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
    int x;
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
	printf("\nMerge Sorted : \n"); 
	show(arr, n);
	printf("\n");
	printf("The Item to be searched: \n");
    scanf("%d",&x);
	int sol = bs(arr, 0, n - 1, x); 
    (sol == -1) ? printf("Price is not in the Interval") 
                   : printf("Price in Interval: %d", 
                            sol+1); 
    return 0;
}
*/


/*
LINEAR SEARCH
#include<stdio.h>
int main()
{
    int num[20],i,x,n;
    printf("Enter the number of intervals: ");
    scanf("%d",&n);
     
    printf("Enter the Values:");
    for(i=0;i<n;++i)
        scanf("%d",&num[i]);
     
    printf("Enter Value to be searched:");
    scanf("%d",&x);
     
    for(i=0;i<n;++i)
    {
        if(num[i]==x)
            break;
    }
    if(i<n)
    {
        printf("Value found at interval %d",i+1);
    }
    else
    {
        printf("Value not found not found");
    }
    return 0;
}
*/
