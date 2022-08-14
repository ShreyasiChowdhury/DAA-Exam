#include<stdio.h>
int n;
struct jobs
{
	int id;
	int profit;
	int deadline;
};
struct jobs job[100];
int min(int a,int b)
{
	if(a<=b)
		return a;
	else
		return b;
}
void input_jobs()
{
	int i;
	for(i=0;i<n;i++)
	{
		job[i].id=i+1;
		printf("\nFor job %c:\n",64+job[i].id);
		printf("Enter the profit: ");
		scanf("%d",&job[i].profit);
		printf("Enter the deadline: ");
		scanf("%d",&job[i].deadline);
	}
}
void merge(int low,int mid,int high)
{
	int i=low,j=mid+1,k=0;
	struct jobs b[high-low+1];
	while(i<=mid && j<=high)
	{
		if(job[i].profit>=job[j].profit)
		{
			b[k++]=job[i++];
		}
		else
		{
			b[k++]=job[j++];
		}
	}
	while(i<=mid)
	{
		b[k++]=job[i++];
	}
	while(j<=high)
	{
		b[k++]=job[j++];
	}
	k=0;
	int a;
	for(a=low;a<=high;a++)
	{
		job[a]=b[k++];
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
void JSD()
{
	int i,j;
	int slot[n],x[n];
	for(i=0;i<n;i++)
	{
		slot[i]=-1;
		x[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=(min(job[i].deadline,n))-1;j>=0;j--)
		{
			if(slot[j]==-1)
            {
                slot[j]=1;
                x[j]=i;
                break;
        	}
		}
	}
	int sum=0;
	printf("\nOrder is:\n");
	for(i=0;i<n;i++)
	{
		if(slot[i]!=-1)
		{
			sum=sum+(job[x[i]].profit);
			printf("%c\t",(job[x[i]].id)+64);
		}
	}
	printf("\n\nTotal Profit: %d\n",sum);
}
int main()
{
	printf(":JOB SEQUENCING DEADLINE:\n");
	printf("\nEnter total number of jobs: ");
	scanf("%d",&n);
	input_jobs();
	mergesort(0,n-1);
	JSD();
	return 0;
}
