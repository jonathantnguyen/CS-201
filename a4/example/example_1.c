// menu example
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define maxItems 15
typedef struct _Menu {
  int count;
  char *items[maxItems];
} Menu;

char *choices[] = {"Exit", "Addition", "Subtraction",
  "Multiplication", "Division", "Modulo", "Reverse Input"};
int count = sizeof(choices)/sizeof(choices[0]);


// pass by value
static void
printMenu(Menu menu)
{
  int i;

  printf("\n");
  for (i=0; i<menu.count; i++) 
    printf("%d. %s\n", i, menu.items[i]);
  printf("\n");
}

// pass by reference
static void
printMenu1(Menu *menu)
{
  int i;

  printf("\n");
  for (i=0; i<menu->count; i++) 
    printf("%d. %s\n", i, menu->items[i]);
  printf("\n");
}

int
main(void)
{
  int i;
  Menu menu;

  menu.count = min(count, maxItems);
  for (i=0; i < menu.count; i++)
    menu.items[i] = choices[i];
  printMenu(menu);
  printMenu1(&menu);
  exit(EXIT_SUCCESS);
}