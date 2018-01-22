#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i;
	char *end;
	if (argc == 0)
	{
		return 0;
	}

	for(long i = strtol(*argv, &end, 2); *argv != end; i = strtol(*argv, &end, 2))
	{
		printf("%ld\n", i);
	}


exit;
}
 