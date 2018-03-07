#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


#define min(a, b) ((a) < (b) ? (a) : (b))
#define maxItems 7
typedef struct _Menu
{
	int menu_size;
	char *items[max_menu_size];
} Menu;

char *choices[] = {"Exit", "Addition", "Subtraction",
  "Multiplication", "Division", "Modulo", "Reverse Input"};
int menu_size = sizeof(choices)/sizeof(choice[0]);

void printMenu(Menu *menu)
{
  int i;

  printf("\n");
  for (i=0; i< menu->menu_size; i++) 
  {
    printf("%d. %s\n", i, menu->items[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
	Menu menu;
	printMenu(&menu);
	return 0;
}


/*
int main(int argc, char const *argv[])
{
	int argi[argc];

	if ((argc < 3) || (argc > 16))
		{
			printf("[Error] Enter between 2 to 15 arguments.\n");
			return 0;
		}

	char * end;
	char key[] = "0x";
	int size_str = 2;
	for (int i = 1; i < argc; ++i)
	{
		if (strncmp(key,argv[i], size_str) == 0)
		{
			printf("It's hex.\n");
			argi[i] = strtol(argv[i], &end, 16)
		}
		else
			printf("It's dec.\n");
	}
}

*/
