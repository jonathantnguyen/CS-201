#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int dToB();
int main(int argc, char **argv)
{

	char *end;
	int temp;

	if(argc == 1)
	{
		printf("No arguments, execute with arguments.\n");
		return 0;
	}

	for (int j = 1; j < argc; j++)
	{	
		*argv = end;
		temp = dToB((long) strtol(argv[j], &end, 10));
		
		printf("%li\n", temp);
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
int dToB(long dec)
{
	if(dec == 0)
		return 0;
	else
		return (dec % 2 + 10 *dToB(dec/2));
}