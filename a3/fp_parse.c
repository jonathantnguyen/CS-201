#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


void check(int argc, char const *argv[]);
int strtol_func(int frac, int exp, char const *argv[]);
void bit_manip(int frac, int exp, char const * argv[]);

int flag_error = 0;

/**
 * @brief      main funct to call functions
 *
 * @param[in]  argc  command-line argument count
 * @param      argv  command-line argument values
 *
 * @return     { description_of_the_return_value }
 */


int main(int argc, char const *argv[])
{
	int frac = 0;
	int exp = 0;
	printf("top of int main\n");
	if(argc != 4)
	{
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
		exit(0);
	}
	
	strtol_func(frac, exp, argv); 
	printf("after strtol_func\n");
	check(argc, argv);
	printf("after check\n");
	bit_manip(frac, exp);
	printf("after bit_manip\n");

	exit(0);
}

void bit_manip(int frac, int exp, char const*argv[])
{
	int sign = 0;
	uint32_t temp_hex = *argv[3];

	sign = (temp_hex & (1 << (frac + exp + 1))) ? 1 : 0;

	if (sign == 1)
		printf("negative\n");
	else
		printf("positive\n");

}

/**
 * @brief      parsing command-line argument using strtol base 10 for decimal arguement
 * 			   and base 16 for the hexdecimal argument
 *
 * @param[in]  argc  argument count
 * @param      argv  argument values
 */
int strtol_func(int frac, int exp, char const *argv[])
{
	char * end;

	for(int i = 1; i <=2; i++)
	{
		*argv = end;
		frac = strtol(argv[i], &end, 10);
	}
		exp = strtol(argv[3], &end, 16);

	return frac, exp;
}

/**
 * @brief      Command-line argument error handling
 *
 * @param[in]  argc  argument count
 * @param      argv  argument values
 */
void check(int argc, char const *argv[])
{

	if(( *argv[1] < 2) || ( *argv[1] > 10))
	{
		flag_error = 1;
		printf("Number of fraction bits between 2 and 10\n");

	}
	if(( *argv[2] < 3) || ( *argv[2] > 5))
	{
		flag_error = 1;
		printf("Number of exponent bits (k) between 3 and 5\n");
	}

	if(flag_error != 0)
		exit(0);
}
