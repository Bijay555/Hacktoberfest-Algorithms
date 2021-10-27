#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int arr[50000];
void asc(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) 
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
    /*for(int k=0;k<n;k++)
        arr_asc[i]=arr[i];*/
}
void dsc(int arr[], int n) 
{ 
    for(int i=0;i<n/2;i++)
    {
        int c=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=c;
    }
}
int main() 
{ 
    clock_t start, end, t;
    double rtime;
    //int arr[50000];
    int n=5000;
    while(n<=50000){
    printf("For %d inputs\n",n);
    srand(time(0));
    for(int i=0;i<n;i++)
        arr[i]=1+rand()%n;
    start=clock();
    asc(arr,n);
    end=clock();
    t=end-start;
    rtime = ((double)t)/CLOCKS_PER_SEC;
    printf("Average Time = %2.4f s\n",rtime);
    //BEST
    start=clock();
    asc(arr,n);
    end=clock();
    t=end-start;
    rtime = ((double)t)/CLOCKS_PER_SEC;
    printf("Best Time = %2.4f s\n",rtime);
    //WORST
    dsc(arr,n);
    start=clock();
    asc(arr,n);
    end=clock();
    t=end-start;
    rtime = ((double)t)/CLOCKS_PER_SEC;
    printf("Worst Time = %2.4f s\n",rtime);
    n+=5000;
    }
}