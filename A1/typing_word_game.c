/* File name: typing_word_game.c
** Author: Jonathan Nguyen
** Class: CS 201
** Discription: You are to implement a game that tests a user's typing speed.  
** The game randomly chooses words from an array of strings containing "The", "quick", 
** "brown", "fox", "jumps", "over", "the", "lazy", "dog".   Each word must appear exactly once.  
** The program should output the time it takes for the user to correctly enter the entire array
** of words.  If the user incorrectly types a word, the program must prompt the user to retype 
** the incorrect word.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permutationBank();

int numberChecker(int tempNumber, int numberBank[]);

int main()
{
	srand(time(NULL));

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
	//printf("Printing: %s \n", topArray[0]);
	printf("Before permutationBank\n");
	permutationBank();
	printf("After permutationBank\n");

exit;
}

void permutationBank()
{ 
	int i = 8;
	int numberBank[9];

	while(i > 0)
	{
		int tempNumber = 0; //(rand() % 9);
		printf("R: %i\n", tempNumber);
		if(numberChecker(tempNumber, numberBank))
		{
			i--;
			printf("Number: %i \n", tempNumber);
			numberBank[i] = tempNumber;
				
		}

	}

}

int numberChecker(int tempNumber, int numberBank[])
{
	int j;
	for(j = 8; j >= 0 ; j-- )
	{ 
		if (tempNumber == numberBank[j])
		{
			return 0;
		}
	}
	return 1;
}
