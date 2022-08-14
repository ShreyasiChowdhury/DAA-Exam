#include<stdio.h>
#include<stdlib.h>
#define size 6
int graph[size][size];
int visited[size]={0};
void DFS_REC(int vertex)
{
	int w;
	visited[vertex]=1;
	printf("%c\t",vertex+65);
	for(w=0;w<size;w++)
	{
		if(graph[vertex][w]==1 && visited[w]==0)
		{
			DFS_REC(w);
		}
	}
}
int main()
{
	int n,i,j,k;
	FILE *fp;
	fp=fopen("ex_graph.txt","r");
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
	printf("\nDFS traversal result:\n");
	DFS_REC(0);
	fclose(fp);
	return 0;
}
