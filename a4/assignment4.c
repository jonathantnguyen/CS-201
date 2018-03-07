#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int argi[argc];

	if ((argc < 3) || (argc > 16))
		{
			printf("[Error] Enter between 2 to 15 arguments.\n");
			return 0;
		}

	char * end;
	char key[] = "0x";
	for (int i = 1; i < argc; ++i)
	{	int j = strcmp(key,argv[i]);
		printf("strcmp: %d\n", j);
		if (strcmp(key,argv[i]) >= 2)
		{
			printf("It's hex.\n");
		}
		else
			printf("It's dec.\n");
	}
}

