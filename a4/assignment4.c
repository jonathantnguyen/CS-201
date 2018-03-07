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
	int size_str = 2;
	for (int i = 1; i < argc; ++i)
	{
		if (strncmp(key,argv[i], size_str) >= 0)
		{
			printf("It's hex.\n");
		}
		else
			printf("It's dec.\n");
	}
}

