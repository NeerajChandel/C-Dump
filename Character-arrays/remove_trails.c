/*
	Program:		A program to remove trailing blanks and tabs from each line of input,
					to delete entire blank lines
*/
#include<stdio.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1

#define MAX_LIMIT		1000

int main(void)
{

	int c, len = 0, i;
	char line[MAX_LIMIT];

	for(i = 0; (c = getchar()) != EOF; ++i)
	{
		line[i] = c;
		/*	
			If the character is a space or a newline or a tab, then decrement
			the index for the array, so that in the next iteration, if 'c' is
			an actual character (besides a whitespace character), it writes over
			it.
		*/
		if(line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			--i;
		++len;
	}

	for(i = 0; i < len; ++i)
		printf("%c", line[i]);
	printf("\n");

	return EXIT_SUCCESS;

}


