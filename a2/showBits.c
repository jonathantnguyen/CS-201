#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void check(int argc, char ** argv);
void hToD(int argc, char ** argv);


int main(int argc, char ** argv)
{
	check(argc, argv);
	hToD(argc, argv);
	exit; 
}

void check(int argc, char ** argv)
{
	if((argc == 1)  || (argc >=4))
	{
		printf("No arguments, execute with arguments.\n");
		exit;
	}
}

void hToD(long bin)
{
	*argv = end;
	while(int j = 0; j <= argc)
	{
		errno = 0;
		bin = (long unsigned)strtoul(argv[j], &end, 16);
		hToD(bin);
	}

}
