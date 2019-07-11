#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writefile();
void readfile();

char FileName[]="data.txt";

int main()
{
	printf("\n");
	writefile();
    readfile();

}


void writefile()
{
	FILE * fp=fopen(FileName,"w");

	if(fp!=NULL)
	{
		int i=10;
		char ch='A';
		char *str1="STRING";
		long loc;

		printf("writing the string %s to the file\n",str1);
		fprintf(fp,"%s\n",str1);

		printf("writing char %c to file\n",ch);
		putc(ch,fp);                           //putc() to print charecter

		printf("writing int %d to file\n",i);
		putw(i,fp);                            //putw() to print integer

		loc=ftell(fp);
		printf("the file pointer location %ld\n",loc);
		fclose(fp);

	}
	else
	{
		printf("ERRORR\n");
	}
}

void readfile()
{
	FILE * fp=fopen(FileName,"r");
	if(fp!=NULL)
	{
		int i=10;
		char ch='A';
		char str1[100];
		long loc;

		fscanf(fp,"%s\n",str1);
		printf("reading %s\n",str1);

		ch=getc(fp);
		printf("reading %c\n",ch);

		i=getw(fp);
		printf("reading %d\n",i);

		loc=ftell(fp);
		printf("the file pointer location %ld\n",loc);

		printf("rewinding file pointer");
		rewind(fp);
		loc=ftell(fp);
		printf("the file pointer location %ld\n",loc);
		fclose(fp);
	}
		else
		{
			printf("ERROR\n");
		}



}
