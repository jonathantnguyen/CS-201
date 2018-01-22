#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char **argv)
{
	//int i;
	char *end;
	int  *array;

	if(argc == 1)
	{
		printf("No arguments, execute with arguments.\n");
		return 0;
	}

	for (int j = 1; j < argc; j++)
	{	
		array[j] = strtol( * argv, &end, 2);
		printf("%i\n", array);
		//printf("%li\n", (long) strtol(argv[j], &end, 10));
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