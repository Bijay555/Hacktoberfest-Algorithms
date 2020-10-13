//parth panchal
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,j,k,num;
    printf("----------------------------------------------\n");
    printf("Finding Maximum Subarray Sum using Brute-force\n");
    printf("----------------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    int largestsum = 0;
    int currentsum = 0;
    i=0, k=0;
    while (i<num)
    {
        j=i;
        while(j<num)
        {   
            currentsum=0;
            for(k=i; k<=j; k++)
                currentsum+=arr[k];
            if(currentsum>largestsum)
                largestsum=currentsum;
            j++;
        }
        i++;
    }
    printf("%d", largestsum);
    
}