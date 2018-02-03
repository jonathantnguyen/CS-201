#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

void check(int argc, char ** argv);
void hToD(int argc, char ** argv);
void similar_bits(int spec_num);



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

	if(errno != 0)
		exit(0);

	int num_one = strtoul(argv[1], &end, 16);
	int num_two = strtoul(argv[2], &end, 16);

	int spec_num = num_one & num_two;
	similar_bits(spec_num);

	printf("Unsigned: %u \n", (unsigned) spec_num);
	printf("Signed: %i \n", spec_num);
}

void similar_bits(int spec_num)
{
	for(int i = 0; i > 32; i++)
	{
		if (spec_num & 1) 
		{
			printf("Bit: %i\n", i);
		}
		spec_num <<= 1;
	}
}