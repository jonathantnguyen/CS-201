#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int dToB(long num);

void StoI(int argc, char ** argv);

int main(int argc, char **argv)
{

	char *end;
	int bin;

	if(argc == 1)
	{
		printf("No arguments, execute with arguments.\n");
		return 0;
	}

	for (int j = 1; j < argc; j++)
	{	
		*argv = end;
		bin = dToB((long) strtol(argv[j], &end, 10));
		
		printf("%i\n", bin);
	}
	/*
	for(long i = strtol(*argv, &end, 2); 
		*argv != end; 
		i = strtol(*argv, &end, 2))
	{
		*argv = end;
		if(errno == ERANGE)
		{
		printf("Range Error.\n");
		errno = 0;
		}
	printf("%ld\n", i);
	}*/

exit;
}

int dToB(long num)
{
	for (0 to 16){
    	if (num & 1 ) ? print(1); else print(0);
    	num >>= 1;
}