#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>


void check(int frac, int exp);
int strtol_func(char const *argv[]);
int sign_bit(int frac, int exp, char const * argv[]);
void fp_funct(int sign, char const * argv[]);

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
	int sign;

	if(argc != 4)
	{
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
		exit(0);
	}
	
	sign = strtol_func(argv);
	fp_funct(sign, argv);




	exit(0);
}

void fp_funct(int sign, char const * argv[])
{
	char * end;
	int bias;
	uint32_t temp_hex = strtol(argv[3], &end, 16);
	frac = strtol(argv[1], &end, 10);
	exp = strtol(argv[2], &end, 10);
	bias = (pow(2, (exp - 1)) - 1);
	printf("Bias: %i\n", bias);



	printf("sign: %i\n", sign);
}

/**
 * @brief      finds the sign bit for floating point
 *
 * @param[in]  frac  Size bit of fraction
 * @param[in]  exp   Size bit of Exponent
 * @param      argv  The argv
 */
int sign_bit(int frac, int exp, char const*argv[])
{
	int sign;
	char * end;
	int mask = 1;

	uint32_t temp_hex = strtol(argv[3], &end, 16);
	mask = mask << (frac + exp);
	sign = (temp_hex & mask) ? 1 : 0;

	return sign; 

/*
	if (sign == 1)
		printf("negative\n");
	else
		printf("positive\n");
*/
}

/**
 * @brief      parsing command-line argument using strtol base 10 for decimal arguement
 * 			   and base 16 for the hexdecimal argument
 *
 * @param[in]  argc  argument count
 * @param      argv  argument values
 */
int strtol_func(char const *argv[])
{
	int frac;
	int exp;

	char * end;

	frac = strtol(argv[1], &end, 10);
	exp = strtol(argv[2], &end, 10);


	check(frac, exp);
	return sign_bit(frac, exp, argv);
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
	if(( exp < 3) || ( exp > 5))
	{
		flag_error = 1;
		printf("Number of exponent bits (k) between 3 and 5\n");
	}

	if(flag_error != 0)
		exit(0);
}
