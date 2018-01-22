#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char **argv)
{
	int i;
	char *end;

	if(argc == 1)
	{
		printf("No arguments, execute with arguments.\n");
		return 0;
	}

	for(long i = strtol(argc, &end, 2); 
		argc != end; 
		i = strtol(argc, &end, 2))
	{
		*argv = end;
		if(errno == ERANGE)
		{
		printf("Range Error.\n");
		errno = 0;
		}
	printf("%ld\n", i);
	}

exit;
}