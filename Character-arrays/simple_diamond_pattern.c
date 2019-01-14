/*
	Name:		simple_diamond_pattern.c
	Purpose:	To draw the following pattern

							*
						*		*
					*		*		*
				*		*		*		*
					*		*		*
						*		*
							*
	Author:		N
*/

#include<stdio.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1

void draw_pattern(char, char, int);		//	(star, no_of_lines)

int main()
{

	char star = '*';
	char space = ' ';

	//	printf("%c%c%c\n", star, space, star);

	draw_pattern(star, space, 10);

	return EXIT_SUCCESS;

}

void draw_pattern(char pat, char esc_seq, int lines)
{

	int i, j, k;

	for(i = 1; i <= lines; i++)	
	{	
		for(k = lines; k > i; k--)	
			printf("%c", esc_seq);

		for(j = 1; j <= i; j++)
		{
			printf("%c ", pat);
		}
		printf("\n");
	}

	for(i = 2; i <= lines; i++)	
	{	
		for(k = 2; k <= i; k++)	
			printf("%c", esc_seq);

		for(j = i; j <= lines; j++)
		{
			printf("%c ", pat);
		}
		printf("\n");
	}

}



