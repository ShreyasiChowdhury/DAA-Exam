#include<stdio.h>
int max,min;
void maxmin(int arr[],int i,int j)
{
	int max_one,min_one,mid;
	if(i==j)
	{
		max=arr[i];
		min=arr[i];
	}
	else if(i==j-1)
	{
		if(arr[i]<arr[j])
		{
			max=arr[j];
			min=arr[i];
		}
		else
		{
			max=arr[i];
			min=arr[j];
		}
	}
	else
	{
		mid=(i+j)/2;
		maxmin(arr,i,mid);
		max_one=max;
		min_one=min;
		maxmin(arr,mid+1,j);
		if(max<max_one)
			max=max_one;
		if(min>min_one)
			min=min_one;
	}
}
int main()
{
	int n,i,j,l;
	printf("Enter array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter array elements:\n");
	for(l=0;l<n;l++)
	{
		scanf("%d",&arr[l]);
	}
	i=0,j=n-1;
	max=min=arr[0];
	maxmin(arr,i,j);
	printf("\nMaximum element of the array is: %d\n",max);
	printf("Minimum element of the array is: %d",min);
	return 0;
}
