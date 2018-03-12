#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


/**
 * @brief      So we do not exceed boundaries for our menu list (7) and the
 *             command-line arguments (15)
 *
 * @param      a     menu_Size (7), arg_Size (15)
 * @param      b     MAXMENUSIZE (7), MAXARGS (15)
 *
 * @return     (7) for menu_Size, (1 - 15) for arg_Size
 */
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAXMENUSIZE 15
#define MAXARGS 15

/**
 * Menu struct, to hold, delete, or add options. Currently max items is 15
 */
typedef struct _Menu
{
	int 		menu_Size;
	char 	   *items[MAXMENUSIZE];
} Menu;

/**
 * Command-line argument struct, holds up to 15 arguments integer or string; String length has no current limit;
 */
typedef struct argList
{
	int 		arg_Size;
	char 	   *args[MAXARGS];
	float 		argi[MAXARGS];
} ArgList;
ArgList argList;

/**
 *  Function call struct, we're holding the size of each string 
 */
typedef struct 
{
    char   	   *string;
} funcParam_t;

/**
 * Dispatch Table Struct, 
 */
typedef void funcPtr_t(funcParam_t *);
typedef struct 
{
    char       *description;
    funcPtr_t  *name;
}dispatch_Table_Entry;

/**
 * @brief      Functions needed to execute each option
 */
void printMenu();
void menu_Setup();
void convert(int argc, char const *argv[]);
void func_exit();
void addition();
void subtraction();
void multiplication();
void division();
void modulo();
void reverse_input();

dispatch_Table_Entry fdt[] =
{
	{"Exit",  func_exit},
	{"Addition", addition},
	{"Subtraction",	subtraction},
	{"Multiplication", multiplication},
	{"Division", division},
	{"Modulo", modulo},
	{"Reverse Input", reverse_input},
};
int fdt_Size = sizeof(fdt) / sizeof(fdt[0]);


char *choices[] = {"Exit", "Addition", "Subtraction",
  "Multiplication", "Division", "Modulo", "Reverse Input",};
int menu_Size = sizeof(choices)/sizeof(choices[0]);

/**
 * @brief      Main just to call the functions
 *
 * @param[in]  argc  Size of Command-Line arguements
 * @param      argv  Command-Line Values
 *
 * @return     No return, exit(0)
 */				
int main(int argc, char const *argv[])
{

	convert(argc, argv);
	printMenu();
	menu_Setup();

	exit(0);
}


/**
 * @brief      Printing out the Menu from the struct _Menu (Menu)
 *
 * @param      menu  ptr to the menu.
 */
void printMenu()
{
	Menu menu;
	menu.menu_Size = min(menu_Size, MAXMENUSIZE);

  	for (int i=0; i < menu.menu_Size; i++)
  	{
    	menu.items[i] = choices[i];
  	}
	int i;

  	printf("\n");
  	for (i=0; i< menu.menu_Size; i++) 
  	{
    	printf("%d. %s\n", i, menu.items[i]);
  	}
  	printf("\n");
}

/**
 * @brief      Store and call
 */
void menu_Setup()
{
	int i;
	int index;
	fdt_Size = min(fdt_Size, menu_Size);

    funcParam_t *paramList[fdt_Size];

    for (i=0; i<fdt_Size; i++) 
    {
        paramList[i] = (funcParam_t *)malloc(sizeof(funcParam_t));
        paramList[i]->string = fdt[i].description;
    }
    printf("Enter Number: ");
    scanf("%i", &index);

	if (index >= 0 && index <= (fdt_Size-1))
	{
		printf("Invoking %s\n\n", fdt[index].description);
    	(*fdt[index].name)(paramList[index]);
    }
    else
    {
    	printf("[ERROR]: Invalid option. \n");
    	menu_Setup();
    }
    for (i = 0; i < fdt_Size; i++)
    {
    	free(paramList[i]);
    }
}

/**
 * @brief      Convert hex to decimal in command-line arguments
 *
 * @param[in]  argc   the size (count) of command line arguments
 * @param      argv   the values of command-line arguments
 * @param[in]  manip  The manip
 */
void convert(int argc, char const *argv[])
{
	argList.arg_Size = min(argc-1,MAXARGS);

	if ((argList.arg_Size == 0) || (argc-1 >= 16))
	{
		printf("[ERROR]: Enter between 1 to 15 command-line arguments. \n\n");
		exit(0);
	}

	char * end;
	char key[] = "0x";
	int size_str = 2;


	for (int i = 0; i < argList.arg_Size; i++)
	{

		int stringLength = strlen(argv[i+1]);
		argList.args[i] = (char *)malloc(sizeof(char) * stringLength);

		strcpy(argList.args[i], argv[i+1]);

		if (strncmp(key,argv[i+1], size_str) == 0)
		{
			//printf("It's hex.\n");
			argList.argi[i] = strtol( argv[i+1], &end, 16 );
		}
		else
		{
			//printf("It's dec.\n");
			argList.argi[i] = strtol( argv[i+1], &end, 10 );
		}
	}
}

void func_exit()
{
	printf("Exited");
}

void addition()
{	
	float total = 0;
	for (int i = 0; i < argList.arg_Size; i++)
	{
		total += argList.argi[i];
		printf("Total: %f\n", total);
		printf("argList.argi[%i]: %f\n", i,argList.argi[i]);
	}
	printf("Total: %f\n", total);
}
void subtraction()
{	
	float total = argList.argi[0];
	for (int i = 1; i < argList.arg_Size; i++)
	{
		total -= argList.argi[i];
		//printf("Total: %f\n", total);
		//printf("argList.argi[%i]: %f\n", i,argList.argi[i]);
	}
	printf("Total: %f\n", total);	

}
void multiplication()
{
	float total = argList.argi[0];
	for (int i = 1; i < argList.arg_Size; i++)
	{
		total *= argList.argi[i];
		//printf("Total: %f\n", total);
		//printf("argList.argi[%i]: %f\n", i,argList.argi[i]);
	}
	printf("Total: %f\n", total);	

}
void division()
{
	if(argList.arg_Size < 2)
	{
		printf("[ERROR]: 2nd argument is needed to compute. \n");
		exit(0);
	}
	//printf("1: %f 2: %f \n",argList.argi[0],argList.argi[1]);
	float total = (argList.argi[0])/(argList.argi[1]);
	printf("Total: %f\n", total);

}
void modulo()
{
	if(argList.arg_Size < 2)
	{
		printf("[ERROR]: 2nd argument is needed to compute. \n");
		exit(0);
	}
	int arg_zero = (argList.argi[0]);
	int arg_one = (argList.argi[1]);
	//printf("1: %f 2: %f \n",argList.argi[0],argList.argi[1]);
	int total = arg_zero % arg_one;
	printf("Total: %d\n", total);	

}
void reverse_input()
{
	//printf("argList.arg_Size: %i\n", argList.arg_Size );
	for (int i = argList.arg_Size-1; i >=0 ; --i)
	{
		//printf("i:%i\n", i);
		int stringLength = strlen(argList.args[i]);
		for (int j = stringLength-1; j >= 0; --j)
		{//			printf("j: %i\n", j);
			printf("%c", argList.args[i][j]);
		}
		printf(" ");
	}  	
	printf("\n");
}
