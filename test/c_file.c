#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * file;

	if(file = fopen("hello.txt", "r"))
	{
			printf("File open succesfully in read mode\n");
	}
	else
	{
		printf("File not present\n");
		fclose(file);
	}

	return 0;
}
