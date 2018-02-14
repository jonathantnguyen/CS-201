#include <stdlib.h>
#include <stdio.h>

void check(int argc, int ** argv);

int main(int argc, int ** argv)
{
	check(argc, argv);
}

void check(int argc, int ** argv)
{
	int flag_error = 0;

	if(argc != 4)
	{
		flag_error = true;
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
	}

	if((argv[1] <= 2) || (argv[1] >= 10))
	{
		flag_error = true;
		printf("Number of fraction bits between 2 and 10\n");

	}
	if((argv[2] <= 3) || (argv[2] >=5))
	{
		flag_error = true;
		printf("Number of exponent bits (k) between 3 and 5\n");
	}

	if(flag_error == true)
		exit(0);
}
