#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = -100;

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