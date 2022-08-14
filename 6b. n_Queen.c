#include<stdio.h>
#include<math.h>
int count=0,flag=0;
void print(int n,int x[])
{
	int i,j;
	count++;
	printf("\nSolution No. %d:\n",count);
	printf("Array Representation:\t");
	for(i=1;i<=n;i++)
		printf("%d\t",x[i]);
	printf("\nChessboard Representation:\n");
	for(i=1;i<=n;i++)
		printf("\t%d",i);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",i);
		for(j=1;j<=n;j++)
		{
			if(i==0||j==0)
				continue;
			else
			{
				if(j==x[i])
					printf("Q\t");
				else
					printf("--\t");
			}	
		}
		printf("\n");
	}
}
int place(int k,int i,int x[])
{
	int j;
	for(j=1;j<k;j++)
	{
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
			return 0;
	}
	return 1;
}
void NQueen(int k,int n,int x[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(place(k,i,x))
		{
			x[k]=i;
			if(k==n)
			{
				flag=1;
				print(n,x);
			}
			else
				NQueen(k+1,n,x);
		}
	}
}
int main()
{
	int n;
	printf(":N-Queen Problem:\n");
	printf("\nEnter number of Queens: ");
	scanf("%d",&n);
	int x[n];
	NQueen(1,n,x);
	if(flag==0)
		printf("\nNo solution exists");
	return 0;
}
