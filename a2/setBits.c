#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char **argv)
{
	int i;
	char *end;

	printf("%i\n", argc);
	for(long i = strtol(*argv, &end, 2); *argv != end; i = strtol(*argv, &end, 2))
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