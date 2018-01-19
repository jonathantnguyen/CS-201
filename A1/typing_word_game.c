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

int permutationBank();
int numberChecker(int tempNumber, int numberBank[]);
int printWords(int  * topArray[],int * numberBank[]);

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

	int * topArray[] = {&theFirst, &quick, &brown, &fox, &jumps, &over, &theSecond, &lazy, &dog}; 
	
	//printf("Printing: %s \n", topArray[0]);
	printWords(topArray, permutationBank());

exit;
}


int printWords(int * topArray[], int *numberBank[])
{	
	int i;
	int temp;
	for(i = 0; i <= 8; i++)
	{
		temp = numberBank[i];
		printf("Printing: %c\n", *topArray[temp]);
	}

}

int permutationBank()
{ 
	int k;
	int i = 0;
	int * numberBank[9];

	while(i <= 8)
	{
		int tempNumber = (rand() % 9+1);
		//printf("R: %i\n", tempNumber);
		//tempNumber = tempNumber - 1;
		//printf("R: %i\n", tempNumber);
		if(numberChecker(tempNumber, numberBank))
		{
			numberBank[i] = tempNumber;
			//printf("Number: %i \n", tempNumber);
			i++;				
		}

	}
	/*for(k = 0; k <= 8; k++)
	{
		printf("Position %i:, %i\n", k, numberBank[k]);
	}	*/
	return numberBank;
}

int numberChecker(int tempNumber, int numberBank[])
{
	int j;
	int k;
	for(j = 0; j <= 8 ; j++)
	{ 
		//for(k = 0; k <= j; k++)
		//{
		//	printf("Position %i:, %i\n", k, numberBank[k]);
		//}	
		//printf("R: %i\n", tempNumber);
		if (tempNumber == numberBank[j])
		{
			return 0;
		}
	}
	return 1;
}
