#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signalhan(int sig)
{
	printf("caught signal floating point error\n %d",sig);
	exit(0);
	}
	
int main()
{
	int a,b,div;
	signal(SIGFPE,signalhan);
	printf("enter 2 numbers\n");
	scanf("%d %d",&a,&b);
	div=a/b;
	printf("the quotient is %d\n",div);
	
	}

