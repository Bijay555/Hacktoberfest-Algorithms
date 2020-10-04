// Quick sort algorithm...
// Contributor Debarshi Mitra...

#include<stdio.h> 

/*Swap Function-
It takes two values by reference and swap them so that the changes made by this function 
gets reflected out of the scope of this function...
*/
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/*Partition Function -
This function takes the last element of the array and assign it to a variable called pivot
and places all the smaller elements compared to pivot to the lef of the pivot and all 
the greater elements to the right of the pivot...
*/
int partition (int arr[], int low, int high) 
{ 
    // Taking the last as the pivot...
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

/*Quick sort Function - 
This function takes the array and the first and last index of the array.
This function divides the array such that all the smaller elements are at the left of the pivot and 
all the greater elements are at the right of the pivot...
This function calls the partition function to divide the array into two parts...
and then this function runs quik sort algorithm on the subarrays using tail recursion...
*/
void quick_sort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		
		int p = partition(arr, low, high); 
 
		quick_sort(arr, low, p - 1); 
		quick_sort(arr, p + 1, high); 
	} 
} 

// Main method to call the quick sort function... 
int main() 
{ 
    // Number of elements in the array...
	int n = 5; 

    // Elements of the array...
    int arr[] = {5,3,2,1,4}; 
	
    // Calling the quick sort function to sort the array...
	quick_sort(arr, 0, n-1); 

	// Printing the array after sorting it using quick sort...
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);

	printf("\n"); 
	return 0; 
} 
