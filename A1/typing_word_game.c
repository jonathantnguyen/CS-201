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

void printing(int i, char * words[]);

void game(char * words[]);

int main()
{
	srand((unsigned)time(NULL));

	char * words[] ={"The", "quick", "brown","fox", "jumps", "over", "the", "lazy", "dog"};
	fisherYatesShuffle(words);
		//words[] has now changed orders
	game(words);


exit;
}

void game(char * words[])
{
	for (int i = 0; i <= 8; i++)
	{
		printing(i, words);
	}

}


void fisherYatesShuffle(char * words[])
{
	int j;
	for(int i = 0; i <= 8; i++)
	{
		j = (rand() % 9);
		char * tmp = words[i];
		words[i] = words[j];
		words[j] = tmp;
	}
}


void printing(int i, char * words[])
{
	char buffer[50];
	printf("Type: %s \n", words[i]);
	scanf("%s", buffer);
	if(buffer != words)
	{
		printf("Incorrect, retype:\n");
		printing(i, words);
	}

}
