#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

void check(int argc, char ** argv);
int hToD(int argc, char ** argv);
int compare(int num_one, int num_two);
void translate_num(int spec_num);



int main(int argc, char ** argv)
{
	check(argc, argv);
	translate_num(hToD(argc, argv));

	
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

int hToD(int argc, char ** argv)
{
	char * end;
	*argv = end;

	if(errno != 0)
		exit(0);

	int num_one = strtoul(argv[1], &end, 16);
	int num_two = strtoul(argv[2], &end, 16);
	//printf("Number 1: %i, Number 2: %i\n", num_one, num_two );
	return compare(num_one, num_two);
	
}

int compare(int num_one,int num_two)
{
	int spec_num = num_one & num_two;

	return spec_num;
}
void translate_num(int spec_num)
{
	printf("Unsigned: %u \n", (unsigned) spec_num);
	printf("Signed: %i \n", spec_num);
}