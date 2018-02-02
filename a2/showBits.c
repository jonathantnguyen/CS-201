#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

void check(int argc, char ** argv);
void hToD(int argc, char ** argv);


int main(int argc, char ** argv)
{
	check(argc, argv);
	hToD(argc, argv);
	printf("end here\n");
	
	exit(0); 
}

void check(int argc, char ** argv)
{
	if(argc != 3)
	{
		printf("Must enter two arguments.\n");
		exit(0);
	}
}

void hToD(int argc, char ** argv)
{
	char * end;
	*argv = end;

	for(int j = 1; j < argc; j++)
	{
		if(errno != 0)
			exit(0);

		unsigned int bin = (long unsigned)strtoul(argv[j], &end, 16);
		printf("Argument: %d Value: %u \n",j, bin);
	}
	printf("Outside For Loops \n");

}
