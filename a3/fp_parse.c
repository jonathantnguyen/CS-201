#include <stdlib.h>
#include <stdio.h>

void check(int argc, int ** argv)
int main(int argc, int ** argv)
{
	check(argc, argv);
}
void check(int argc, int ** argv)
{
	if(argc != 4)
	{
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
		exit(0);
	}

	if((argv[1] <= 2) || (argv[1] >= 10))
	{
		printf("Number of fraction bits between 2 and 10\n");
		exit(0);
	}
	if((argv[2] <= 3) || (argv[2] >=5))
	{
		printf("Number of exponent bits (k) between 3 and 5\n");
		exit(0);
	}
}
