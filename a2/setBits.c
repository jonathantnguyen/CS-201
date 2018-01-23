#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void dToB(long num);
void sToI(int argc, char ** argv);
int check(int argc, char ** argv);

int main(int argc, char **argv)
{
	check(argc, argv);

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
void sToI(int argc, char ** argv)
{	
	int bin;
	char * end;
	for (int j = 1; j < argc; j++)
	{	
		*argv = end;
		bin = (long)strtol(argv[j], &end, 10);
		while ((0 <= bin) && (bin <= 15))
		{
			dToB(bin);
		}
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
    	(num & 1 ) ? printf("1"): else printf("0");
    	num >>= 1;
    }
}