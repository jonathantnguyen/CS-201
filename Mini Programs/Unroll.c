#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main()
{

	int set[100];
	int total = 0;


	for (int i = 0; i < 100; i++)
	{
		set[i] = i;
	}


	for (int j = 0; j <= 31 ; j+=4)
	{

		for (int m = 0; m < 4; m++)
		{
			total += set[j + m];
		}

	}
	printf("total: %i\n", total);
	total = 0;

	for (int j = 0; j <= 35 ; j+=6)
	{

		for (int m = 0; m < 6; m++)
		{
			total += set[j + m];
		}

	}
	printf("total: %i\n", total);
	total = 0;

	for (int j = 0; j <= 71 ; j+=9)
	{

		for (int m = 0; m < 9; m++)
		{
			total += set[j + m];
		}

	}
	printf("total: %i\n", total);
	total = 0;	


	
}