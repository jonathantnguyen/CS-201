#include <stdio.h>

int main()
{
	
	//int wordBank[9];
	int numberBank;
	int i;

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
	
	numberBank = rand() % 9 + 1;
	if (i=0, i <= 9, i++)
		{
			printf("Random number: %i",numberBank);
		}
	printf("%s\n",topArray[i]); 



	return 0;
}