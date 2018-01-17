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

int permutationBank(int i, int tempNumber);

int randNumberGen();

int numberChecker(int tempNumber, int numberBank[]);

int main()
{

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

	printf("Before randNumberGen\n")
	randNumberGen();
	printf("After randNumberGen\n")

exit;
}

int randNumberGen()
{
	int i;
	srand(time(NULL));

	for (i = 0; i <= 8; i++)
	{
		int tempNumber = (rand() % 9);
		permutationBank(i, tempNumber);
		printf("Loop randNumberGen\n")
	}

	return 0;
}
 
int permutationBank(int i, int tempNumber)
{ 
	int numberBank[9];
	printf("function permutationBank\n");
	if(numberChecker(tempNumber, numberBank))
	{
		numberBank[i] = tempNumber;
		printf("Number: %i\n",tempNumber);
	}
	return 0;
}

int numberChecker(int tempNumber, int numberBank[])
{
	int j;
	for(j = 0; j <= 8; j++ )
	{ 
		printf("Loop numberChecker\n");
		if (tempNumber != numberBank[j])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
