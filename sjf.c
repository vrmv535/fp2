FCFS
#include <stdio.h>
#include <stdlib.h>
#define N 3


struct process {
	int pid,at,bt,st,ct,wt,tat;
};

int main()
{
	int i,j,k;
	int time=0;
	int nproc=0; //number of process completed
	struct process *tmp;
	struct process *proc[N];

	printf("enter the %d process with pid,at,bt\n",N);
	for(i=0;i<N;i++)
	{
		proc[i]=(struct process *)malloc(sizeof(struct process));
		scanf("%d %d %d",&proc[i]->pid,&proc[i]->at,&proc[i]->bt);
	}
	printf("before sorting\n");

	for(i=0;i<N;i++)
	{
		printf("%d %d %d\n",proc[i]->pid,proc[i]->at,proc[i]->bt);
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<(N-i-1);j++)
		{
			if(proc[j]->bt>proc[j+1]->bt)
			{
				tmp=proc[j];
				proc[j]=proc[j+1];
				proc[j+1]=tmp;
			}
		}
	}
	printf("after sorting");
	for(i=0;i<N;i++)
	{
		printf("%d %d %d\n",proc[i]->pid,proc[i]->at,proc[i]->bt);
	}

	for(i=0;i<N;i++)
	{
		if(time>=proc[i]->at)
		{
			proc[i]->st=time;
		}
		else
		{
			time=proc[i]->at;
			proc[i]->st=time;
		}
		proc[i]->ct=time+proc[i]->bt;
		time=time+proc[i]->bt;
		proc[i]->wt=proc[i]->st-proc[i]->at;
		proc[i]->tat=proc[i]->ct-proc[i]->at;
	}
	printf("After compiling\n");
	for(i=0;i<N;i++){
		printf("%d %d %d %d %d %d %d\n",proc[i]->pid,proc[i]->at,proc[i]->bt,proc[i]->st,proc[i]->ct,proc[i]->wt,proc[i]->tat);
	}
}
____________________________________________________



#include <stdio.h>
#include <stdlib.h>
#define N 4

struct process{
	int pid,at,bt,st,ct,tat,wt;
};

int main()
{
	int i,j,k;
	int time=0;
	int nproc=0;  //number of processes completed
	struct process *tmp;
	struct process *proc[N];
	printf("enter %d processes with pid, arival time and burst time\n",N);
	for(i=0;i<N;i++)
	{
		proc[i]= (struct process*)malloc(sizeof(struct process));
		scanf("%d %d %d",&proc[i]->pid,&proc[i]->at,&proc[i]->bt);
		proc[i]->ct=-1;
	}

	for(i=0;i<N;i++){
		printf("%d %d %d\n",proc[i]->pid,proc[i]->at,proc[i]->bt);
	}
	time=0;
	nproc=0;
	
	while(nproc!=N)
	{
		int pchoose=-1;
	    int pchoose_bt=99999;

		for(i=0;i<N;i++)
		{
			if(proc[i]->ct==-1 && pchoose_bt>proc[i]->bt && proc[i]->at<=time)
			{
				pchoose=i;
				pchoose_bt=proc[i]->bt;
			}
			if(pchoose!=-1)
			{
				nproc++;
				proc[pchoose]->st=time; ////NEW
				proc[pchoose]->ct=time+proc[pchoose]->bt;
			    time=time+proc[pchoose]->bt;
			    proc[pchoose]->wt = proc[pchoose]->st-proc[pchoose]->at;
			    proc[pchoose]->tat = proc[pchoose]->ct-proc[pchoose]->at;
			}
			else
			{
				time++; //NEWWWW
			}
		}
	}


	printf("after sorting\n");
	for(i=0;i<N;i++){
		printf("%d %d %d %d %d %d %d\n",proc[i]->pid,proc[i]->at,proc[i]->bt,proc[i]->st,proc[i]->ct,proc[i]->wt,proc[i]->tat);
	}

}



