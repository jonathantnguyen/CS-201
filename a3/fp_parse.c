#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


void check(int argc, char const *argv[]);
void strtol_func(int ** array, char const *argv[]);
void bit_manip(int ** array);

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
	printf("top of int main\n");
	int *array[];
	if(argc != 4)
	{
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
		exit(0);
	}
	
	strtol_func(array, argv); 
	printf("after strtol_func\n");
	check(argc, argv);
	printf("after check\n");
	bit_manip(array);
	printf("after bit_manip\n");

	exit(0);
}

void bit_manip(int **array)
{
	int sign = 0;
	int frac = *array[1];
	int exp = *array[2];
	uint32_t temp_hex = *array[3];

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
void strtol_func(int ** array, char const *argv[])
{
	char * end;

	for(int i = 1; i <=2; i++)
	{
		*argv = end;
		*array[i] = strtol(argv[i], &end, 10);
	}
		*array[3] = strtol(argv[3], &end, 16);
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
