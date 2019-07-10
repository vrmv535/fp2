#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	
	int fd1;
	mkfifo("/home/ranjith/1RV17IS010/myfifo1",0666);
	char str1[100],str2[100];
	while(1)
	{
	fd1=open("/home/ranjith/1RV17IS010/myfifo1",O_WRONLY);
	fgets(str2,100,stdin);
	write(fd1,str2,strlen(str2)+1);
	close(fd1);


	fd1=open("/home/ranjith/1RV17IS010/myfifo1",O_RDONLY);
	read(fd1,str1,100);
	printf("%s\n",str1);
	close(fd1);
    }
}	

_____________________________________________________________________________

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>

int main(int argc,char **argv[])
{
	int which=PRIO_PROCESS;
	int id,i;
	int prio,set;
	id=getpid();
	printf("Previous Requested Assigned\n");
	for(i=-20;i<20;i+=4)
	{
		prio=getpriority(which,id);
		printf("%5d\n",prio);
		printf("         %d\n",i);

		setpriority(which,id,i);
		prio=getpriority(which,id);
		printf("                            %d\n",prio);
	}
	return 0;
}
