#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


void check(int frac, int exp);
void strtol_func(int frac, int exp, char const *argv[]);
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
	int frac;
	int exp;

	printf("top of int main\n");
	if(argc != 4)
	{
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
		exit(0);
	}
	
	strtol_func(frac, exp, argv); 


	exit(0);
}

void bit_manip(int frac, int exp, char const*argv[])
{
	int sign;
	int mask = 1;

	mask = mask << (frac + exp + 1) ;

	sign = (temp_hex & mask) ? 1 : 0;

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
void strtol_func(int frac, int exp, char const *argv[])
{
	char * end;

	frac = strtol(argv[1], &end, 10);
	exp = strtol(argv[2], &end, 16);


	check(frac, exp);
	bit_manip(frac, exp, argv);


}

/**
 * @brief      Command-line argument error handling
 *
 * @param[in]  argc  argument count
 * @param      argv  argument values
 */
void check(int frac, int exp)
{

	if(( frac < 2) || ( frac > 10))
	{
		flag_error = 1;
		printf("Number of fraction bits between 2 and 10\n");

	}
	if(( frac < 3) || ( frac > 5))
	{
		flag_error = 1;
		printf("Number of exponent bits (k) between 3 and 5\n");
	}

	if(flag_error != 0)
		exit(0);
}
