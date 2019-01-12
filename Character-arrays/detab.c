/*
	A program which replaces tabs with proper number of blanks.
*/
#include<stdio.h>
#include<stdbool.h>	//	for bool

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1

#define MAXLINE			1000

bool blank_flag = false;	//	to check for number of blanks

int main(void)
{

	int c, len = 0, i;

	char line[MAXLINE];

	for(i = 0; (c = getchar()) != EOF;/*	no ++i over here, since our increments are conditional	*/)
	{
		line[i] = c;

		if(line[i] == '\t')
		{
			//	if a tab has been found, we will replace it with 4 blanks
			line[i] = line[i + 1] = line[i + 2] = line[i + 3] = ' ';
			blank_flag = true;	//	set blank flag if a tab has been found
		}

		if(blank_flag)
		{
			/*
				if a tab has been found, and since we hav ereplaced it with 4 blanks, we
				need to increment the length by 4.......
			*/
			len += 4;
			blank_flag = false;
			/*
				...... and we also need to increment the array index by 4, since we will
				store the next character after the blanks.
			*/
			i += 4;
		}
		else
		{
			//	if no tabs found, increment simply the way it used to increment
			++len;
			++i;
		}
	}

	for(i = 0; i < len; ++i)
		printf("%c", line[i]);
	printf("\n");

	return EXIT_SUCCESS;

}

