// menu example
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define MAXLINE 128
#define MAXBUFSIZE MAXLINE+1
// our file cannot have more than MAXITEMS entries
#define MAXITEMS 50
typedef struct _Menu {
  int count;
  char *items[MAXITEMS];
} Menu;

// pass by value
static void
printMenu(Menu menu)
{
  int i;

  printf("\n");
  for (i=0; i<menu.count; i++) 
    printf("%d. %s", i, menu.items[i]);
  printf("\n");
}

// pass by reference
static void
printMenu1(Menu *menu)
{
  int i;

  printf("\n");
  for (i=0; i<(*menu).count; i++) 
    printf("%d. %s", i, (*menu).items[i]);
  printf("\n");
}

int
main(void)
{
  int i;
  char *p;
  FILE *fp;
  Menu menu;
  char buffer[MAXBUFSIZE];

  fp = fopen("choices", "r");
  if (!fp) {
    fprintf(stderr, "Error: cannot open choices\n");
    exit(EXIT_FAILURE);
  }

  menu.count = 0;

  while (menu.count < MAXITEMS && ((p = fgets(buffer, MAXLINE, fp)) != 0)) {
    menu.items[menu.count] = malloc(MAXLINE+1);
    if (menu.items[menu.count] == 0) { // malloc failed
      printf("Error: malloc failed in %s in routine %s at line %d\n",
		      __FILE__, __FUNCTION__, __LINE__);
      fclose(fp);
      exit(EXIT_FAILURE);
    }
    strncpy(menu.items[menu.count], buffer, strlen(buffer));
    menu.count++;
  }

  fclose(fp);

  printMenu(menu);
  printMenu1(&menu);

  // always free malloc'd memory when done with it
  for (i=0; i<menu.count; i++)
    free(menu.items[i]);

  exit(EXIT_SUCCESS);
}