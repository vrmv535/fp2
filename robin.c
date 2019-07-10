//ROBIN
#include<stdio.h> 

int main() 
{ 
	int st[10],bt[10],wt[10],tat[10],n,tq; 
	int i,count=0,swt=0,stat=0,temp,sq=0; 
	float awt=0.0,atat=0.0; 
	printf("Enter number of processes:"); 
	scanf("%d",&n); 
	printf("Enter burst time for sequences:"); 
	for(i=0;i<n;i++) 
	{ 
		scanf("%d",&bt[i]); 
		st[i]=bt[i]; 
	} 
	printf("Enter time quantum:"); 
	scanf("%d",&tq); 
	
	while(1) 
	{ 
		for(i=0,count=0;i<n;i++) 
		{ 
			temp=tq; 
			if(st[i]==0) 
			{ 
				count++; 
				continue; 
			} 
			if(st[i]>tq) 
				st[i]=st[i]-tq;
				 
			else if(st[i]>=0) 
			{ 
				temp=st[i]; 
				st[i]=0; 
			} 
			sq=sq+temp; 
			tat[i]=sq; 
		} 
		if(n==count) 
			break; 
	} 
	for(i=0;i<n;i++) 
	{ 
		wt[i]=tat[i]-bt[i]; 
		swt=swt+wt[i]; 
		stat=stat+tat[i]; 
	} 
	awt=(float)swt/n; 
	atat=(float)stat/n; 
	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
	printf("\n\nAvg wait time is %f\nAvg turn around time is %f",awt,atat); 
}
______________________________________________________________________________________________________________________________

#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
	return 0;
}
