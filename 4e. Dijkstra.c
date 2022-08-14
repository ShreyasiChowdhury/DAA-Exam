#include<stdio.h>
#include<stdlib.h>
#define inf 999
#define size 5
int n;
int graph[size][size];
int mindist(int dist[],int sptset[])
{
	int i,min=inf,min_index;
	for(i=0;i<n;i++)
	{
		if(sptset[i]==0 && dist[i]<min)
		{
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}
void print(int pred[],int v,int src)
{
	if(v<0)
		return;
	print(pred,pred[v],src);
	if(v!=src)
		printf(" --> ");
	printf("%c",v+65);
}
void dijkstra(int src)
{
	int i,u,v;
	int dist[n],pred[n],sptset[n];
	for(i=0;i<n;i++)
	{
		dist[i]=inf;
		pred[i]=-1;
		sptset[i]=0;
	}
	dist[src]=0;
	for(i=0;i<n;i++)
	{
		u=mindist(dist,sptset);
		sptset[u]=1;
		for(v=0;v<n;v++)
		{
			if(!sptset[v] && graph[u][v] && dist[u]!=inf &&
			dist[u]+graph[u][v]<dist[v])
			{
				dist[v]=dist[u]+graph[u][v];
				pred[v]=u;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
			continue;
		print(pred,i,0);
		printf(", cost : %d\n",dist[i]);
	}
}
int main()
{
	int i,j,k;
	FILE *fp;
	fp=fopen("input_dijkstra.txt","r");
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
	printf("\n:Dijkstra's Algorithm:\n");
	dijkstra(0);
	fclose(fp);
	return 0;
}
