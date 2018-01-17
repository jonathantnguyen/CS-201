#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	
	int wordBank[9];
	int numberBank;
	int i;
	int j;

	char theFirst[] = {'T', 'h', 'e'};
	char quick[] = {'q','u','i','c','k'};
	char brown[] = {'b','r','o','w','n'};
	char fox[] = {'f','o', 'x'};
	char jumps[] = {'j','u','m','p','s'};
	char over[] = {'o', 'v', 'e', 'r'};
	char theSecond[] = {'t', 'h', 'e'};
	char lazy[] = {'l','a','z', 'y'};
	char dog[] = {'d','o','g'};

	int *topArray[] = {&theFirst, &quick, &brown, &fox, &jumps, &over, &theSecond, &lazy, &dog}; 
	
	srand(time(NULL));

	
	for (i=0; i<= 8; i++)
		{
			numberBank = rand() % 9 + 1;

			if (numberBank != wordBank[])
				wordBank[j];
				j++;

			printf("Random number: %i\n",numberBank);
		}
	//printf("%s\n",topArray[i]); 



	return 0;
}