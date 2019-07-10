#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

int main()
{
	int fd[2];
	char msg[100];
	char buf[100];
	int status,r,i;

    struct timeval t;

    fd_set rfds;

	status=pipe(fd);

	if(status==-1)
	{
		perror("pipe");
		return 0;
	}

	i=fork();

	if(i<0)
	{
		perror("fork");
		return 0;
	}

	if(i==0)
	{
		printf("CHILD PROCESS\n");
		printf("enter the message to send\n");
		scanf("%s",msg);
		write(fd[1],msg,100);
		close(fd[1]);
	}

	if(i>0)
	{
		printf("PARENT PROCESS\n");

		t.tv_sec=3;
		t.tv_usec=0;
		FD_ZERO(&rfds);
		FD_SET(fd[0],&rfds);

		r=select(fd[0]+1,&rfds,NULL,NULL,&t);

		if(r==0)
		{
			printf("timeout\n");
		}

		if(r<0)
		{
			perror("select");
		}

		read(fd[0],buf,100);
		printf("the message read is %s\n",buf );


	}
}







