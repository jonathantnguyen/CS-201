#include <stdlib.h>
#include <stdio.h>

void check(int argc, char ** argv);
void strtol_func(int argc, char ** argv);

int main(int argc, char ** argv)
{
	printf("segfault 0\n");
	strtol_func(argc, argv);
	printf("segfault end\n");
	//check(argc, argv);
exit(0);
}

void strtol_func(int argc, char ** argv)
{
	char * end;

	for (int i = 1; i <= 4; i++)
	{
		*argv = end;
		printf("segfault 1\n");
		*argv[i] = (unsigned long) strtol(argv[i], &end, 10);
		printf("segfault 2\n");
		printf("Value: %i \n", *argv[i]);

	}


}/*
void check(int argc, char ** argv)
{
	int flag_error = 0;

	if(argc != 4)
	{
		flag_error = 1;
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
	}

	if(( *argv[1] <= 2) || ( *argv[1] >= 10))
	{
		flag_error = 1;
		printf("Number of fraction bits between 2 and 10\n");

	}
	if(( *argv[2] <= 3) || ( *argv[2] >=5))
	{
		flag_error = 1;
		printf("Number of exponent bits (k) between 3 and 5\n");
	}

	if(flag_error != 0)
		exit(0);
}
*/