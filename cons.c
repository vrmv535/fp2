#include <stdio.h>
#include <stdlib.h>

int mutex=1,full=0,empty=3,x=0;   //global

int main()
{
	int n;
	void producer();
	void consumer();
    int wait(int);
	int signal(int);
	printf("1.producer 2.consumer 3.exit\n");
	while(1)
	{
	printf("enter ure choice\n");
	scanf("%d",&n);

	switch(n)
	{
		case 1:
		if((mutex==1) && (empty!=0))
		{
			producer();
			break;
		}
		else{
			printf("FULL\n");
			break;
		}

		case 2:
		if((mutex==1) && (full!=0))
		{
			consumer();
			break;
		}
		else{
			printf("EMPTY\n");
			break;
		}
		case 3:
		exit(0);
		break;
	}
    }
    return 0;
}

int wait(int s)
{
	return(--s);
}

int signal(int s)
{
	return(++s);
}

void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("produced item %d\n",x);
	mutex=signal(mutex);
}

void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("consumed item %d\n",x);
	x--;
	mutex=signal(mutex);
}


