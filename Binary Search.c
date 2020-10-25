#include<stdio.h>
int main()
{
	int a[50],i,lower,upper,mid,search,n;
	printf("\nEnter size of array:");
	scanf("%d",&n);
	printf("\nEnter %d elements in Ascending order: ",n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	printf("\nEnter Element to search:");
	scanf("%d",&search);
	
	lower=0;
	upper=n-1;
	mid=(upper+lower)/2;
	
	while(lower<=upper){
		if(a[mid]<search) lower=mid+1;
		else if(a[mid]==search){
			printf("\n%d found at location %d",search,mid+1);
			break;
		}
		else upper=mid-1;
		mid=(upper+lower)/2;
	}
	if(lower>upper) printf("\n\nElement Not Found\n\n");
	return 0;
}
