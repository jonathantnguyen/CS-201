#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>

int _menu();

int main(int argc, char const *argv[])
{
	int choice = _menu();




	exit(0);

}

int _menu()
{
	int choice = 0;

	printf("Please enter one of the following options by it's corresponding number, and press ENTER\n");
	printf("\n 0. Exit\n 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Module\n 6. Reverse Input\n\n");

	scanf(" %d", &choice);
	if (!isalpha(choice))
	{
		choice = -1;
	}

	if ((choice < 0) || (choice > 6))
	{
		printf("Invalid input. Try again.\n");
		_menu();
	}

	return choice;
} 