#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void check(int argc, char ** argv);
int hToD(char ** argv);

int main(int argc, char ** argv)
{
	check(argc, argv);
	//hToD(argc, argv);
	exit; 
}

void check(int argc, char ** argv)
{
	if(argc == 1)
	{
		printf("No arguments, execute with arguments.\n");
		exit;
	}
}
