#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>


void check(int argc);
void fp_funct();

int FLAG_ERROR = 0;
int FP_FLAG;
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
	HEXDECIMAL = strtol(argv[3], &end, 16);
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
	uint32_t e_value = 0;
	uint32_t temp_hexdecimal = HEXDECIMAL;
	uint32_t pow_value = 0;
	int j = 0;
	int fp_value = 0;

	temp_hexdecimal = temp_hexdecimal << FRAC_BIT + EXP_BIT;
	temp_hexdecimal = temp_hexdecimal >> FRAC_BIT + EXP_BIT;
	printf("FRAC_BIT: %i, EXP_BIT: %i, HEXDECIMAL: %i\n",FRAC_BIT,EXP_BIT, temp_hexdecimal);

	for (int i = 0; i < EXP_BIT; i++)
	{
		if (!(temp_hexdecimal & 1))
		{
			pow_value = pow_value + pow(2, i);
			j++;
			printf("J: %i\n", j);
		}
		temp_hexdecimal = temp_hexdecimal >> 1;
	}

	printf("FRAC_BIT: %i, EXP_BIT: %i, HEXDECIMAL: %i\n",FRAC_BIT,EXP_BIT, temp_hexdecimal);
	if (j == EXP_BIT) //DENORMALIZED
	{
		e_value = 1 - BIAS;
		//fp_value = (pow(2, (-1)*e_value)); 
		printf("e_value: %i\n",e_value);
		printf("fp_value: %i\n", fp_value);

	}
	else // NORMALIZED
	{
		e_value = pow_value;
		printf("e_value: %i\n",e_value);
	}

	//printf("Pow_value: %i\n",pow_value);
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
