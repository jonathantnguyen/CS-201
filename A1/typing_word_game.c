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
#include <string.h>

int * permutationBank(int numberBank[]);
int numberChecker(int tempNumber, int numberBank[]);
void printWords(char *topArray[],int numberBank[]);

int main()
{
	srand((unsigned)time(NULL));

	int numberBank[9];

	char theFirst[] = {'T', 'h', 'e'};
	char quick[] = {'q','u','i','c','k'};
	char brown[] = {'b','r','o','w','n'};
	char fox[] = {'f','o', 'x'};
	char jumps[] = {'j','u','m','p','s'};
	char over[] = {'o', 'v', 'e', 'r'};
	char theSecond[] = {'t', 'h', 'e'};
	char lazy[] = {'l','a','z', 'y'};
	char dog[] = {'d','o','g'};

	char *topArray[] = {theFirst, quick, brown, fox, jumps, over, theSecond, lazy, dog}; 
	printf("Before Permutation Bank\n");
	//printf("Printing: %s \n", topArray[0]);
	printWords(topArray, permutationBank(numberBank));

exit;
}


void printWords(char *topArray[], int numberBank[])
{	
	int i;
	int j;
	int temp;
	int size;
	for(i = 0; i <= 8; i++)
	{
		printf("Inside forloop i\n");
		temp = numberBank[i];
		size = strlen(topArray[temp]);
		for(j = 0; j <= size; j++)
		{
			printf("Inside forloop j\n");
			printf("%c", topArray[temp][j]);
		}
	}
	printf("\n");
}

int * permutationBank(int numberBank[])
{ 
	int k;
	int i = 0;
	while(i <= 8)
	{	
		//printf("Inside permutationBank\n");
		int tempNumber = ((rand() % 9)+1);

		if(numberChecker(tempNumber, numberBank))
		{
			numberBank[i] = tempNumber;
			i++;				
		}

	}
	//printf("Coming out of permutationBank\n");
	return numberBank;
}

int numberChecker(int tempNumber, int numberBank[])
{
	int j;
	int k;
	//printf("Inside numberChecker\n");
	for(j = 0; j <= 8 ; j++)
	{ 
		if (tempNumber == numberBank[j])
		{
			return 0;
		}
	}
	return 1;
}
