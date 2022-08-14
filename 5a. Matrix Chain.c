#include<stdio.h>
#define inf 99999
#define max 10
int m[max][max],s[max][max];
void printmat(int n)
{
	int i,j;
	printf("\nM matrix:\n");
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(m[i][j]!=0)
				printf("%d\t",m[i][j]);
			else
				printf("0\t");
		}
		printf("\n");
	}
	printf("\nS matrix:\n");
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(s[i][j]!=0)
				printf("%d\t",s[i][j]);
			else
				printf("0\t");
		}
		printf("\n");
	}
}
void print_optimal_parents(int i,int j,int n)
{
	if(i==j)
		printf("A%d ",i);
	else
	{
		printf("( ");
		print_optimal_parents(i,s[i][j],n);
		print_optimal_parents(s[i][j]+1,j,n);
		printf(") ");
	}
}
void matrix_chain_order(int p[],int n)
{
	int i,j,k,len,cost;
	for(i=1;i<n;i++)
	{
		m[i][i]=0;
		s[i][i]=0;
	}
	for(len=2;len<n;len++)
	{
		for(i=1;i<n-len+1;i++)
		{
			j=i+len-1;
			m[i][j]=inf;
			for(k=i;k<=j-1;k++)
			{
				cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(cost<m[i][j])
				{
					m[i][j]=cost;
					s[i][j]=k;
				}
			}
		}
	}
	printmat(n);
	printf("\nCost of total multiplication: %d",cost);
	printf("\nFinal Optimal Parenthesization is:\n");
	print_optimal_parents(1,n-1,n);
}
int main()
{
	int n,i;
	printf("Enter size of representation array: ");
	scanf("%d",&n);
	int p[n];
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	printf("Entered matrices are:\n");
	for(i=1;i<n;i++)
	{
		printf("Order of (A%d) : %d*%d\n",i,p[i-1],p[i]);
	}
	matrix_chain_order(p,n);
	return 0;
}
