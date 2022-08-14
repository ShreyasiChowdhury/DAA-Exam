#include<stdio.h>
#include<stdlib.h>
#define size 6
int stack[size];
int graph[size][size];
int visited[size]={0};
int top=-1;
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(top==size-1)
		return 1;
	else
		return 0;
}
void push(int item)
{
	if(isfull())
		printf("\nOVERFLOW!!\n\n");
	else
	{
		top++;
		stack[top]=item;
	}
}
int pop()
{
	int x=-1;
	if(isempty())
		printf("\nUNDERFLOW!!\n\n");
	else
	{
		x=stack[top];
		top--;
	}
	return x;
}
void DFS_ITR(int vertex)
{
	int u,w;
	push(vertex);
	visited[vertex]=1;
	while(!isempty())
	{
		u=pop();
		printf("%c\t",u+65);
		for(w=0;w<size;w++)
		{
			if(graph[u][w]==1 && visited[w]==0)
			{
				push(w);
				visited[w]=1;
			}
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
	DFS_ITR(0);
	fclose(fp);
	return 0;
}
