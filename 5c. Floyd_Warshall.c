#include<stdio.h>
#define inf 999
#define nil -99
#define max 4
int d[max][max],p[max][max];
int n;
void printmat()
{
	int i,j;
	printf("\nSolution graph:\n\t");
	for(i=0;i<n;i++)
	{
		printf("%c\t",i+65);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t",i+65);
		for(j=0;j<n;j++)
		{
			if(d[i][j]==inf)
				printf("%s\t","inf");
			else
				printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
}
void floydwar(int graph[][n])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[i][j]=graph[i][j];
			if(graph[i][j]==0 || graph[i][j]==inf)
				p[i][j]=nil;
			else
				p[i][j]=i;
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((d[i][j]>d[i][k]+d[k][j]) && (d[k][j]!=inf && d[i][k]!=inf))
				{
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=p[k][j];
				}
			}
		}
	}
	printmat();
}
void shortpath(int i,int j)
{
	if(i==j)
		printf("%c --> ",i+65);
	else if(p[i][j]==nil)
		printf("No path between %c and %c\n",i+65,j+65);
	else
	{
		shortpath(i,p[i][j]);
		printf("%c --> ",j+65);
	}
}
int main()
{
	int i,j;
	FILE *fp;
	fp=fopen("input_floydwar.txt","r");
	if(fp==NULL)
	{
		printf("Error to open the file\n\n");
		return;
	}
	fscanf(fp,"%d",&n);
	int graph[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	printf("The graph in matrix format:\n\t");
	for(i=0;i<n;i++)
	{
		printf("%c\t",i+65);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t",i+65);
		for(j=0;j<n;j++)
		{
			if(graph[i][j]==inf)
				printf("%s\t","inf");
			else
				printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	floydwar(graph);
	for(i=0;i<n;i++)
	{
		printf("\nAll pair of shortest paths from node %c to others:\n",i+65);
		for(j=0;j<n;j++)
		{
			if(i==j)
				printf("The node itself");
			else
				shortpath(i,j);
			printf("\n");
		}
	}
	fclose(fp);
	return 0;
}
