#include<stdio.h>
int n;
void merge(int arr[],int low,int mid,int high)
{
	int b[n];
	int k,i,j;
	k=low;
	i=low;
	j=mid+1;
	while(i<=mid&&j<=high)
	{
		if(arr[i]<arr[j])
		{
			b[k]=arr[i];
			i++;
		}
		else
		{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=arr[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=arr[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++)
	{
		arr[i]=b[i];
	}
}
void mergesort(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
void print(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int main()
{
	int i,j,l;
	printf("Enter array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter array elements:\n");
	for(l=0;l<n;l++)
	{
		scanf("%d",&arr[l]);
	}
	i=0,j=n-1;
	printf("\nArray before swapping:\n");
	print(arr,n);
	mergesort(arr,i,j);
	printf("Array after swapping:\n");
	print(arr,n);
	return 0;
}
