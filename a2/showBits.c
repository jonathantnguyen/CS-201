#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int check(int argc, char ** argv);
int hToD(char ** argv);

int main(int argc, char ** argv)
{
	check(argc, argv);
	exit; 
}

int check(int argc, char ** argv)
{
	if(argc == 1)
	{
		printf("No arguments, execute with arguments.\n");
		return 0;
	}

	hToD(argc, argv);
}

int hToB(int argc, char ** argv)
{	
	int hexArray[];
	char * end;
	for (int j = 1; j < argc; j++)
	{	
		*argv = end;
		if (isalpha(argv[j]))
		{
			alphToB(argv[j])
		}
	}
}

int alphaToB(char ** argv)
{
	
}