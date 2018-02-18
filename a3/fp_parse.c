#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>


void check(int argc);
void sign_bit(int frac, int exp, char const * argv[]);
void fp_funct();

int FLAG_ERROR = 0;
int FRAC_BIT;
int EXP_BIT;
int SIGN;
int BIAS;
uint32_t HEXDECIMAL;



/**
 * @brief      define FRAC, BIT, SIGN Provides error handling, and function
 *             calls to perform floating point calculation
 *
 * @param[in]  argc  Command-line argument array size offset by +1;
 * @param      argv  Command-line argument values
 *
 * @return     {No return value}
 */			
int main(int argc, char const *argv[])
{
	char * end;
	uint32_t mask;

	FRAC_BIT = strtol(argv[1], &end, 10);
	EXP_BIT = strtol(argv[2], &end, 10);
	printf("COMMAND-LINE VALUES\n");
	printf("FRAC_BIT: %i, EXP_BIT: %i, HEXDECIMAL: %i\n",*argv[1],*argv[2],*argv[3]);
	mask = ((1 << (FRAC_BIT + EXP_BIT)) - 1);
	printf("Mask: %i\n", mask);
	HEXDECIMAL = *argv[3] & ((1 << (FRAC_BIT + EXP_BIT)) - 1);
	printf("FRAC_BIT: %i, EXP_BIT: %i, HEXDECIMAL: %i\n",FRAC_BIT,EXP_BIT, HEXDECIMAL);

	SIGN = (HEXDECIMAL & (1 << (FRAC_BIT + EXP_BIT))) ? 1 : 0;

	check(argc);
	fp_funct();

	exit(0);
}

/**
 * @brief      Solves for floating point based on the hexdecimal given.
 *
 * @param[in]  sign  The sign
 * @param      argv  The argv
 */
void fp_funct()
{
	BIAS = pow(2, (EXP_BIT - 1)) - 1; // Solving for the bias
	
	printf("Bias: %i\n", BIAS);
	printf("Sign: %i\n", SIGN);
}


/**
 * @brief      Command-line error handling
 *
 * @param      argc  Command-line argument array size
 */
void check(int argc)
{
		if(argc != 4)
	{
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
		exit(0);
	}

	if(( FRAC_BIT < 2) || ( FRAC_BIT > 10))
	{
		FLAG_ERROR = 1;
		printf("Number of fraction bits between 2 and 10\n");

	}
	if(( EXP_BIT < 3) || ( EXP_BIT > 5))
	{
		FLAG_ERROR = 1;
		printf("Number of exponent bits (k) between 3 and 5\n");
	}

	if(FLAG_ERROR != 0)
		exit(0);
}
