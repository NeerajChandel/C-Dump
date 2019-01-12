/*
	A program to replace blanks by the minimum number of tabs and blanks to achieve
	the same spacing.
*/
#include<stdio.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1

#define MAXLINE			1000

int main(void)
{

	int c, len = 0, i;
	char line[MAXLINE];

	for(i = 0; (c = getchar()) != EOF; ++i)
	{
		line[i] = c;

		if(line[i] == ' ')
		{
			line[i] = '\t';
		}

		++len;
	}

	printf("%s\n", line);

}
