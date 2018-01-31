#include <stdio.h>
#include <stdlib.h>

int main()
{
	float i = -10;

	if (i == (int)(float) i)
		printf("true %d\n", i);
	else 
		printf("false %d\n", i);


	if (i == (int)(double) i)
		printf("true %d\n", i);
	else 
		printf("false %d\n", i);

	exit;
}