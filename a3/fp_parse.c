#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


void check(uint32_t frac, uint32_t exp);
void strtol_func(uint32_t frac, uint32_t exp, char const *argv[]);
void bit_manip(uint32_t frac, uint32_t exp, char const * argv[]);

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
	uint32_t frac;
	uint32_t exp;
	printf("top of int main\n");
	if(argc != 4)
	{
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
		exit(0);
	}
	
	strtol_func(frac, exp, argv); 


	exit(0);
}

void bit_manip(uint32_t frac, uint32_t exp, char const*argv[])
{
	int sign = 0;
	int mask = 1;
	uint32_t temp_hex = *argv[3];
	printf("%u %i\n",temp_hex, temp_hex);
	printf("%i\n", mask );
	mask = mask << frac + exp;
	printf("%i\n", mask );
;
	sign = (temp_hex & mask) ? 1 : 0;
	printf("%u\n",temp_hex);

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
void strtol_func(uint32_t frac, uint32_t exp, char const *argv[])
{
	char * end;

	for(int i = 1; i <=2; i++)
	{
		*argv = end;
		frac = strtol(argv[i], &end, 10);
	}
		exp = strtol(argv[3], &end, 16);

	check(frac, exp);
	bit_manip(frac, exp, argv);


}

/**
 * @brief      Command-line argument error handling
 *
 * @param[in]  argc  argument count
 * @param      argv  argument values
 */
void check(uint32_t frac, uint32_t exp)
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
