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

int * fisherYatesShuffle(char * words[]);
void fun(int array[])
{
	int temp = array[0];
	array[0] = array[4];
	array[4] = array[0];

}

//void printing(char * words[]);

int main()
{
	/*srand((unsigned)time(NULL));

	char * words[] ={"The", "quick", "brown","fox", "jumps", "over", "the", "lazy", "dog"};
	fisherYatesShuffle(words);
	//printing(bank);
*/

	int array[] = {1,2,3,4};
	for(int i = 0; i < 4; i++)
	{
		printf("%d:%d\n", i, array[i]);
	}
	fun(array);
	for(int i = 0; i < 4; i++)
	{
		printf("%d:%d\n", i, array[i]);
	}
exit;
}

int * fisherYatesShuffle(char * words[])
{
	int i;
	int j;
	j = ((rand() % 9) - i);
	for(i = 0; i <= 8; i++)
	{
		char * tmp = words[i];
		words[i] = words[j];
		words[j] = tmp;
	}
	return words;
}



/*
void printing(char * words[])
{
	int n;
	for(n = 0; n <= 8; n++)
	{
		printf("%s \n", words[n]);
	}
}
*/

