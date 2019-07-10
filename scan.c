#include <stdio.h>

int fifo(int *a,int start,int n)
{
	int cost=0,i;
	cost=abs(a[0]-start);  //or |a[0]-start|
	for(i=1;i<n;i++)
	{
		cost=cost+abs(a[i]-a[i-1]);
	}
	return cost;
}
int scanalgo(int *a,int start,int n)
{
	int cost=0,i,j,tmp,next;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i]<=start)
		{
			next=i;
		}
		else
		{
			break;
		}
	}
	cost=abs(a[next]-start);   //this is the cost to travel to the closest element to the starting element and to find the cost to travel till there
	for(i=next;i>0;i--)
	{
		cost=cost+abs(a[i]-a[i-1]);  //from the start element we go to left sub tree (refer notes)
	}

	cost=cost+abs(a[0]);  //cost of traveling from left end (after finishing it) to start(0)

	cost=cost+abs(a[next+1]);
	for(i=next+2;i<n;i++)
	{
		cost=cost+abs(a[i]-a[i-1]);
	}
	return cost;
}
void main()
{
	int n,i,start,cost;
	int a[100];
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the start point or place\n");
	scanf("%d",&start);
	cost=fifo(a,start,n);
	printf("FIFO:%d\n",cost);
	cost=scanalgo(a,start,n);
	printf("SCAN:%d\n",cost);
}
