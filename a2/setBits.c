#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void dToB(long num);
void sToI(int argc, char ** argv);
int check(int argc, char ** argv);

int main(int argc, char **argv)
{
	check(argc, argv);

exit;
}



void sToI(int argc, char ** argv)
{	
	int bin;
	char * end;
	for (int j = 1; j < argc; j++)
	{	
		*argv = end;
		bin = (long)strtol(argv[j], &end, 10);
		if(!(0 <= bin) && (bin <= 15))
		{
			printf("Must be between 0-15\n");
		}
		dToB(bin);
	}
}

int check(int argc, char ** argv)
{
	if(argc == 1)
	{
		printf("No arguments, execute with arguments.\n");
		return 0;
	}

	sToI(argc, argv);
}

void dToB(long num)
{	
	for (int i = 0; i <= 16; i++)
	{
    	(num & 1 ) ? printf("1") : printf("0");
    	num >>= 1;
    	if (num == 0)
    	break;
    }
    printf("\n");
}