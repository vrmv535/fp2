#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char*argv[])   //after ./a.out
{

struct stat *buf; //contains the stats of file
char *fd;           //name of file(text.c)

int i;
for(i=0;i<argc;i++)
{
	buf=(struct stat*)malloc(sizeof(struct stat));
	fd=argv[i];
	lstat(fd,buf);    //lstat is a function that will determine information about a file based on its file name.
	printf("filename:%s\n",fd);
	printf("filesize:%ld\n",buf->st_size);

	if(S_ISREG(buf->st_mode)) 
		printf("Regular File\n");

	else if(S_ISLNK(buf->st_mode))
		printf("Symbolic Link File\n");

	else if(S_ISDIR(buf->st_mode))
		printf("Directory File\n");

	else if(S_ISBLK(buf->st_mode))
		printf("Block File\n");

	else if(S_ISCHR(buf->st_mode))
		printf("Character File\n");

	free(buf);     //very important to free the buf
}
return 0;
}


