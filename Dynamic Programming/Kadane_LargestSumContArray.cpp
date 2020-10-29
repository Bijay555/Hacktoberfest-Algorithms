// Largest Sum Contiguous Subarray

// Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum. A contiguous subarray is a subset of the array that includes the elements in a sequenced manner, without skipping any element in between.
// Example of contiguous subarrays for the array [1,2,3,4,5]
// [2,3,4]
// [4,5]
// [1,2,3,4,5]
// [1,2,3]

// Sample Input:
// 6
// 1 -2 1 1 -2 1

// Output:
// 2

// Explanation: 
// The max contiguous sum in the above array will be 2, starting from index 2 and ending at index 3. All other contiguous array sums will be less than 2.

#include <iostream>
using namespace std;

int kadaneAlgo(int arr[], int n)
{
    int globalMax,maxEndingHere,i;
    globalMax = arr[0];
    maxEndingHere = arr[0];
    for(i=1;i<n;i++)
    {
        maxEndingHere = max(maxEndingHere + arr[i], arr[i]);
        if(maxEndingHere > globalMax)
            globalMax = maxEndingHere;
    }
    return globalMax;
}

int main() 
{
    int arr[] = {1, 3, -4, 2, 1, -1, 3, -5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = kadaneAlgo(arr, n);
    
    cout<<"Max subarray sum = "<<result<<endl;
}
