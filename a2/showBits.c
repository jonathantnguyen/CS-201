#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

void check(int argc, char ** argv);
void hToD(int argc, char ** argv);
void compare(int num_one, int num_two);



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

	int num_one = (long unsigned)strtoul(argv[1], &end, 16);
	int num_two = (long unsigned)strtoul(argv[2], &end, 16);
	//printf("Number 1: %i, Number 2: %i\n", num_one, num_two );
	compare(num_one, num_two);
	
}

void compare(int num_one,int num_two)
{
	printf("Bits: ");
	for(int i = 0; i < 31; i++)
	{
		if((num_one & 1) && (num_two & 1))
		{
			printf("%i,\n",i);
		}
		
		num_one >> 1;
		num_two >> 1;
	}

}