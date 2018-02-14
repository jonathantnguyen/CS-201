#include <stdlib.h>
#include <stdio.h>

void check(int argc, char ** argv);

int main(int argc, char ** argv)
{
	check(argc, argv);
	exit(0);
}

void check(int argc, char ** argv)
{
	int flag_error = 0;

	int hex, arr1, arr2;

	sscanf(argv,"%i %i %i", &arr1, &arr2, hex);
	printf("Frac: %i, Exp: %i, Hex: %i \n", arr1, arr2, hex);

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
