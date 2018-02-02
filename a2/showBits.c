#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

void check(int argc, char ** argv);
void hToD(int argc, char ** argv);
void compare(int argc, int * num_array);



int main(int argc, char ** argv)
{
	check(argc, argv);
	hToD(argc, argv);
	
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

		int k = sizeof(argv[j]);
		int * num_array[j-1] = (long unsigned)strtoul(argv[j], &end, 16);
		compare(argc, num_array);
	}
}

void compare(int argc, int * num_array)
{
	printf("Number 1: %u, Number 2: %u \n", num_array[0], num_array[1]);
}