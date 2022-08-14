#include<stdio.h>
#define inf 999
#define max 20
int n;
int graph[max][max],parent[max];
int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
void kruskal()
{
	int a,b,i,j,u,v,min,cost=0,count=1;
	printf("\n\nEdges considered in MST are:");
	while(count<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(graph[i][j]<min)
				{
					min=graph[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("\n%d. %c <--> %c : %d",count++,a+64,b+64,min);
			cost=cost+min;
		}
		graph[a][b]=graph[b][a]=inf;
	}
	printf("\n\nSpanning tree cost: %d",cost);
}
int main()
{
	int i,j;
	FILE *fp;
	fp=fopen("input_kruskal.txt","r");
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
			if(graph[i][j]==0)
				graph[i][j]=999;
		}
	}
	printf("The graph in matrix format:\n\t");
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
			if(graph[i][j]==inf)
				printf("0\t");
			else
				printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	kruskal();
	fclose(fp);
	return 0;
}
