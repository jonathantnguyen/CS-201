#include <stdlib.h>
#include <stdio.h>

void check(int argc, char ** argv);
void strtol_func(int argc, char ** argv);

int main(int argc, char ** argv)
{
	check(argc, argv);
	strtol_func(argc, argv);
	exit(0);
}

 strtol_func(int argc, char ** argv)
{
	char * end;

	for(int i = 1; i <=2; i++)
	{
		*argv = end;
		*argv[i] = strtol(argv[i], &end, 10);
		printf("Value %d:  %d \n", i, argv[i]);
	}

	*argv[3] = strtol(argv[3], &end, 16);
	printf("Value 3: %d \n", argv[3]);


}

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
