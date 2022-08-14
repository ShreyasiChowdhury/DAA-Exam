#include<stdio.h>
#include<stdlib.h>
#define inf 999
#define size 6
int n;
int graph[size][size];
int minkey(int key[],int mstset[])
{
	int i,min=inf,min_index;
	for(i=0;i<n;i++)
	{
		if(mstset[i]==0 && key[i]<min)
		{
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}
void print(int parent[])
{
	int i,sum=0;
	printf("\n:Prim's Algorithm:\n\n");
	printf("Edges\tWeight\n");
	for(i=1;i<n;i++)
	{
		printf("%c <--> %c : %d\n",parent[i]+65,i+65,graph[i][parent[i]]);
		sum=sum+graph[i][parent[i]];
	}
	printf("\nMinimum cost is : %d\n",sum);
}
void prims()
{
	int i,u,v;
	int parent[n],key[n],mstset[n];
	for(i=0;i<n;i++)
	{
		key[i]=inf;
		parent[i]=-1;
		mstset[i]=0;
		key[0]=0;
	}
	for(i=0;i<n-1;i++)
	{
		u=minkey(key,mstset);
		mstset[u]=1;
		for(v=0;v<n;v++)
		{
			if(graph[u][v] && mstset[v]==0 && graph[u][v]<key[v])
			{
				key[v]=graph[u][v];
				parent[v]=u;
			}
		}
	}
	print(parent);
}
int main()
{
	int i,j,k;
	FILE *fp;
	fp=fopen("input_prims.txt","r");
	if(fp==NULL)
	{
		printf("Error to open the file\n\n");
		return;
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	printf("The graph in matrix format:\n\t");
	for(k=0;k<n;k++)
	{
		printf("%c\t",k+65);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t",i+65);
		for(j=0;j<n;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	prims();
	fclose(fp);
	return 0;
}
