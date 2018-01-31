#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = -100;

	if (i == (int)(float) i)
		printf("true");
	else 
		printf("false");


	if (i == (int)(double) i)
		printf("true");
	else 
		printf("false");

	exit;
}