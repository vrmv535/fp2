#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	int pid;
	pid=fork();
	char a[100];
	int status;
	
	if(pid<0)
	{
		printf("no child process is created\n");
		exit(-1);
	}

	if(pid==0)
	{
		printf("child process is created\n");
		printf("parent process id is %d",getpid());
		printf("return value is %d",pid);
		printf("enter the command\n");
		
		scanf("%s",a);
		system(a);
		return 0;
	}
	else
	{
	wait(&status);
	printf("parent process id is %d\n",getpid());
	printf("return value is %d\n",pid);
	printf("the status value is %d\n",status);
	printf("i am ure parent\n");
	return 0;
	}
	}
	
	
______________________________________________________________________________________________


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	pid_t pid=0;
	pid_t sid=0;

	pid=fork();

	if(pid<0)
	{
		exit(1);
	}

	if(pid>0)
	{
		printf("child process id is: %d\n",pid);
		exit(0);
	}

	umask(0);
	sid=setsid();

	if(sid<0)
	{
		exit(0);
	}

	chdir("/");
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	fp=fopen("/home/ranjith/1RV17IS008/LOG1.txt","w+");

	while(1)
	{
		sleep(2);
		fprintf(fp,"LOGGING\n");
		fflush(fp);
	}

	fclose(fp);




	return 0;
}
