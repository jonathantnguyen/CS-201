#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = -100;

	if (i == (int)(float) i)
		printf("true %f\n", i);
	else 
		printf("false %f\n", i);


	if (i == (int)(double) i)
		printf("true %f\n", i);
	else 
		printf("false %f\n", i);

	exit;
}