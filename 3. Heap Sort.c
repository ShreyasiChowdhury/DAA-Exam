#include<stdio.h>
void heapadjust(int arr[],int i,int n)
{
	int j=2*i;
	int key=arr[i];
	while(j<=n)
	{
		if(j<n && arr[j]<arr[j+1])
			j++;
		if(key>=arr[j])
			break;
		arr[j/2]=arr[j];
		j=2*j;
	}
	arr[j/2]=key;
}
void makeheap(int arr[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		heapadjust(arr,i,n);
	}
}
void heapsort(int arr[],int n)
{
	int i,temp;
	makeheap(arr,n);
	for(i=n;i>=2;i--)
	{
		temp=arr[i];
		arr[i]=arr[1];
		arr[1]=temp;
		heapadjust(arr,1,i-1);
	}
}
void print(int arr[],int size)
{
	int i;
	for(i=1;i<=size;i++)
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
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array before swapping:\n");
	print(arr,n);
	heapsort(arr,n);
	printf("Array after swapping:\n");
	print(arr,n);
	return 0;
}
