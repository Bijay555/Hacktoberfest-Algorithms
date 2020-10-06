//Hemant Sirsat

#include<stdio.h>

//function to find minimum of two elements
int min(int a,int b)
{
            if(a>b)
                        return b;
            else return a;
}

//function to find maximum of two elements 
int max(int a,int b)
{
            if(a>b)
                        return a;
            else return b;
}

//Divide and Conquer Approach 
void minmax(int a[], int i, int j, int *fmin, int *fmax)
{
            int m,gmin,gmax,hmin,hmax;
            //if only one element present
            if(i==j)
            {
                        *fmin=*fmax=a[i];
                        return;
            }
            //if two elements present
            if(i==j-1)
            {
                        *fmin = min(a[i],a[j]);
                        *fmax = max(a[i],a[j]);
                        return;
            }
            //if more than 2 elements present
            m = (i+j)/2; //Finding mid
            minmax(a,i,m,&gmin,&gmax);      //Divide&Conquer approach for elements from 0 to m
            minmax(a,m+1,j,&hmin,&hmax);    //Divide&Conquer approach for elements from m+1 to n-1    
            *fmin = min(hmin,gmin);  //fmin has minimum element
            *fmax = max(hmax,gmax);  //fmax has maximum element 
            return;
}
 
void main()
{
            int i,a[100],n,fmin,fmax;
            printf("Enter no. of integers:");
            scanf("%d",&n);
            for(i=0;i<n;i++)
                        scanf("%d",&a[i]);
            minmax(a,0,n-1,&fmin,&fmax);
            printf("maximum = %d\nminimum = %d\n",fmax,fmin);
}
