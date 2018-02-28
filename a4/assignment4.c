#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void print_menu();

int main(int argc, char const *argv[])
{
	print_menu();



	exit(0);

}

void print_menu()
{
	printf("Please enter one of the following options by it's corresponding number, and press ENTER\n");
	printf("     0. Exit\n     1. Addition\n     2.Subtraction\n     3.Multiplication\n
	     4.Division\n     5.Module\n     6.Reverse Input\n");
} 