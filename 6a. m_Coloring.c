#include<stdio.h>
#define max 20
int graph[max][max],x[max];
int n,m,false=0,count=0;
void NextValue(int k)
{
	int j;
	do{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=1;j<=k-1;j++)
		{
			if(graph[k][j]==1 && x[j]==x[k])
				break;
		}
		if(j==k)
			return;
	}while(!false);
}
void mColoring(int k)
{
	int i;
	do{
		NextValue(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			count++;
			printf("\nSolution No. %d:\n",count);
			for(i=1;i<=n;i++)
			{
				printf("%d\t",x[i]);
			}
			printf("\n");
		}
		else
		{
			mColoring(k+1);
		}
	}while(!false);
}
int main()
{
	int i,j,k=1;
	FILE *fp;
	printf(":m-Coloring Problem:\n");
	printf("\nEnter number of Colors: ");
	scanf("%d",&m);
	//fp=fopen("input_mcoloring.txt","r");
	fp=fopen("new.txt","r");
	if(fp==NULL)
	{
		printf("Error to open the file\n\n");
		return;
	}
	fscanf(fp,"%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	printf("\nThe graph in matrix format:\n\t");
	for(i=1;i<=n;i++)
	{
		printf("%c\t",i+64);
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%c\t",i+64);
		for(j=1;j<=n;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	printf("\nSOLUTIONS:\n");
	mColoring(k);
	if(count==0)
		printf("DOES NOT EXIST");
	fclose(fp);
	return 0;
}
