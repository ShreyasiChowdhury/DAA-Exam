#include<stdio.h>
int n,m;
struct items
{
	char id;
	int profit;
	int weight;
	double frac;
};
struct items item[100];
double x[100]={0.0};
void input_items()
{
	int i;
	for(i=0;i<n;i++)
	{
		item[i].id=(char)(65+i);
		printf("\nFor item %c:",item[i].id);
		printf("\nEnter the profit: ");
		scanf("%d",&item[i].profit);
		printf("Enter the weight: ");
		scanf("%d",&item[i].weight);
		item[i].frac=item[i].profit/item[i].weight;
	}
}
void merge(int low,int mid,int high)
{
	int i=low,j=mid+1,k=0;
	struct items b[high-low+1];
	while(i<=mid && j<=high)
	{
		if(item[i].frac>=item[j].frac)
		{
			b[k++]=item[i++];
		}
		else
		{
			b[k++]=item[j++];
		}
	}
	while(i<=mid)
	{
		b[k++]=item[i++];
	}
	while(j<=high)
	{
		b[k++]=item[j++];
	}
	k=0;
	int a;
	for(a=low;a<=high;a++)
	{
		item[a]=b[k++];
	}
}
void mergesort(int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}
void fractional_knapsack()
{
	int i;
	int u=m;
	printf("\nItems included are:");
	for(i=0;i<n;i++)
	{
		if(item[i].weight<=u)
		{
			x[i]=1.0;
			u=u-item[i].weight;
			printf("\n%c %0.2lf%% in the knapsack",item[i].id,x[i]*100);
		}
		else
		{
			x[i]=(double)u/item[i].weight;
			printf("\n%c %0.2lf%% in the knapsack",item[i].id,x[i]*100);
			break;
		}
	}
}
void calculate_profit()
{
	int i;
	double p=0.0;
	for(i=0;i<n;i++)
	{
		p=p+(item[i].profit*x[i]);
	}
	printf("\n\nThe total profit is Rs : %0.2lf\n",p);
}
int main()
{
	printf(":FRACTIONAL KNAPSACK:\n");
	printf("\nEnter the number of items: ");
	scanf("%d",&n);
	printf("Enter the knapsack size: ");
	scanf("%d",&m);
	input_items();
	mergesort(0,n-1);
	fractional_knapsack();
	calculate_profit();
	return 0;
}
