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
	uint32_t temp_exp_value = HEXDECIMAL;
	uint32_t temp_frac_value = HEXDECIMAL;
	int e_value = 0;
	float fp_value = 0;
	float m_value = 0;
	float frac_value = 0;

	temp_exp_value <<= (32 - (FRAC_BIT + EXP_BIT));
	temp_exp_value >>= (32 - FRAC_BIT);
	printf("FRAC_BIT: %i, EXP_BIT: %i, HEXDECIMAL: %i\n",FRAC_BIT,EXP_BIT, HEXDECIMAL);
	if (temp_exp_value == 0) // DENORMALIZED
	{
		printf("DENORMALIZED\n");
		e_value = pow(2,1 - BIAS);
		for (int i = FRAC_BIT; i > 0; i--)	
		{	
			if (temp_frac_value & 1)
			{	
				frac_value += pow(2,-i);
			}
			temp_frac_value >>= 1;
		}
		m_value = frac_value;
		fp_value = m_value * pow(2,e_value);

	}
	else // NORMALIZED
	{	
		printf("NORMALIZED\n");
		e_value = temp_exp_value - BIAS;

		for (int i = FRAC_BIT; i > 0; i--)	
		{	
			if (temp_frac_value & 1)
			{	
				frac_value += pow(2,-i);
			}
			temp_frac_value >>= 1;
		}
		m_value = frac_value + 1;
		fp_value = m_value * pow(2,e_value);
	}
	if (SIGN == 1)
	{
		fp_value *= (-1);
	}
	printf("FRAC_BIT: %i, EXP_BIT: %i, HEXDECIMAL: %i\n",FRAC_BIT,EXP_BIT, HEXDECIMAL);
	printf("Bias: %i\n", BIAS);
	printf("Sign: %i\n", SIGN);
	printf("fp_value: %f\n", fp_value);
	printf("m_value: %f\n",m_value);
	printf("e_value: %i\n",e_value);
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
