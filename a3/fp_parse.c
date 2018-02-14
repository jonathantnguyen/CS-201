#include <stdlib.h>
#include <stdio.h>


void check(int argc, char ** argv);
void strtol_func(int argc, char ** argv);
void bit_manip(char ** argv)

int flag_error = 0;

/**
 * @brief      main funct to call functions
 *
 * @param[in]  argc  command-line argument count
 * @param      argv  command-line argument values
 *
 * @return     { description_of_the_return_value }
 */
int main(int argc, char ** argv)
{
	if(argc != 4)
	{
		printf("<# of frac_bits> <# of exp_bits> <hex_to_convert>\n");
		exit(0);
	}
	
	strtol_func(argc, argv); 
	check(argc, argv);
	bit_manip(argv);

	exit(0);
}

void bit_manip(char ** argv)
{
	int sign = 0;
	int size = *argv[1] + *argv[2];
	printf("%d\n",size );



}

/**
 * @brief      parsing command-line argument using strtol base 10 for decimal arguement
 * 			   and base 16 for the hexdecimal argument
 *
 * @param[in]  argc  argument count
 * @param      argv  argument values
 */
void strtol_func(int argc, char ** argv)
{
	char * end;

	for(int i = 1; i <=2; i++)
	{
		*argv = end;
		*argv[i] = strtol(argv[i], &end, 10);
	}
		*argv[3] = strtol(argv[3], &end, 16);
}

/**
 * @brief      Command-line argument error handling
 *
 * @param[in]  argc  argument count
 * @param      argv  argument values
 */
void check(int argc, char ** argv)
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
