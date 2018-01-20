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

void fisherYatesShuffle(char * words[]);

void printing(char * words[]);

int main()
{
	srand((unsigned)time(NULL));

	char * words[] ={"The", "quick", "brown","fox", "jumps", "over", "the", "lazy", "dog"};
	fisherYatesShuffle(words);
		//words[] has now changed orders
	printing(words);

exit;
}


void fisherYatesShuffle(char * words[])
{
	int i;
	int j;
	int n;
	printf("inside fisher\n");
	j = ((rand() % 9) - i);
	for(n = 0; n <= 8; n++)
	{
		printf("%s \n", words[n]);
	}
	for(i = 0; i <= 8; i++)
	{
		char * tmp = words[i];
		words[i] = words[j];
		words[j] = tmp;
	}
	for(n = 0; n <= 8; n++)
	{
		printf("%s \n", words[n]);
	}
	printf("end of fisher\n");
}


void printing(char * words[])
{
	printf("inside print\n");
	int n;
	for(n = 0; n <= 8; n++)
	{
		printf("%s \n", words[n]);
	}
}

