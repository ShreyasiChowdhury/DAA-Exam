#include<stdio.h>
#define inf 999
#define size 6
int n,k=0,eno=0;
int graph[size][size];
int d[size],p[size];
struct node
{
	int u;
	int v;
	int w;
};
struct node edge[size];
void shortest_path(int i)
{
	if(i==0)
	{
		printf("A -->");
	}
	if(p[i]==-1)
	{
		return;
	}
	shortest_path(p[i]);
	printf(" %c -->",i+65);
}
void bellford()
{
	int i,j,u,v,w;
	for(i=0;i<n;i++)
	{
		d[i]=inf;
		p[i]=-1;
	}
	d[0]=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<eno;j++)
		{
			u=edge[j].u;
			v=edge[j].v;
			w=edge[j].w;
			if(d[u]!=inf && d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				p[v]=u;
			}
		}
	}
	for(j=0;j<eno;j++)
	{
		u=edge[j].u;
		v=edge[j].v;
		w=edge[j].w;
		if(d[u]!=inf && d[u]+w<d[v])
		{
			printf("\nNegative weight cycle detected!\n\n");
			return;
		}
	}
	printf("\n\nThe shortest path from source vertex A is:");
	for(i=0;i<n;i++)
	{
		printf("\nShortest path for %c vertex is : ",i+65);
		shortest_path(i);
		printf("\ncost : %d\n",d[i]);
	}
}
int main()
{
	int i,j;
	FILE *fp;
	fp=fopen("input_bellford.txt","r");
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
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	printf("\nInputs are:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(graph[i][j]!=0)
			{
				edge[k].u=i;
				edge[k].v=j;
				edge[k].w=graph[i][j];
				printf("\n%c -- %c : %d",edge[k].u+65,edge[k].v+65,edge[k].w);
				k++;
				eno++;
			}
		}
	}
	bellford();
	fclose(fp);
	return 0;
}
