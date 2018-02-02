#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

void check(int argc, char ** argv);
void hToD(int argc, char ** argv);


int main(int argc, char ** argv)
{
	printf("Before 'Check'\n");
	check(argc, argv);
	printf("After 'Check', Before 'hToD'\n");
	hToD(argc, argv);
	printf("After 'hToD' \n");
	exit; 
}

void check(int argc, char ** argv)
{
	if((argc == 1)  || (argc >=4))
	{
		printf("No arguments, execute with arguments.\n");
		exit;
	}
}

void hToD(int argc, char ** argv)
{
	char * end;
	*argv = end;

	printf("Inside 'hToD' before for loop\n");

	for(int j = 0; j <= argc; j++)
	{
		if(errno != 0)
			exit;

		printf("Inside 'hToD' for loop\n");
		int bin = (long unsigned)strtoul(argv[j], &end, 16);
		printf("Inside after 'bin'\n");
		printf("Value: %d \n", bin);
	}

}
