#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low,int high)
{
	int j;
	int pivot=arr[high];
	int i=low-1;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	i++;
	swap(&arr[i],&arr[high]);
	return i;
}
void quicksort(int arr[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(arr,low,high);
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
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
	int n,i;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array before swapping:\n");
	print(arr,n);
	quicksort(arr,0,n-1);
	printf("Array after swapping:\n");
	print(arr,n);
	return 0;
}
