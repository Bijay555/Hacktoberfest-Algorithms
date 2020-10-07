//Hemant Sirsat

#include<stdio.h>
long int arr[100000];

long int BinarySearch(long int arr[],long int first,long int last,long int e) 
{ 
    if (last >= first) 
    { 
        long int mid = first + (last - 1) / 2; 
        if (arr[mid] == e) 
            return 1; //if element found return bool 1

        if (arr[mid] > e) 
            return BinarySearch(arr, first, mid - 1, e); //if element is smaller tha element at center of array

        return BinarySearch(arr, mid + 1, last, e); //if element is greater tha element at center of array
    }
    return 0; 
} 

void main()
{
    long int n;
    scanf("%ld",&n); //Enter Number of Elements in Array
    for(long int i = 0;i<n;i++)
        scanf("%ld",&arr[i]);  //Enter elemets in array
    long int e;                         
    printf("\nEnter Element to Search: ");
    scanf("%ld",&e);
    if(BinarySearch(arr,0,e,n))
        printf("\nElement Present");
    else printf("\nElement not found");
}
