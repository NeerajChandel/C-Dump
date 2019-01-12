/*
	Program:		Reversing and printing a line input by the user, using scanf()
*/
#include<stdio.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1

#define MAX_LIMIT		1000

void reverse_line(char[], char[], int);

int main(void)
{

	int line_len = 0, i;

	char line[MAX_LIMIT], c;	//	initialise c with any dummy value
	char rev[MAX_LIMIT];

	for(i = 0; c != '\n'; ++i)
	{
		scanf("%c", &c);
		line[i] = c;
		++line_len;
	}

	printf("\nOriginal string stored in line[]:\n");
	for(i = 0; i < line_len - 1; ++i)
		printf("%c", line[i]);
	printf("\nlength: %d\n\n", i);

	printf("Reversed string stored in rev[]:");

	reverse_line(line, rev, line_len);

	for(i = 0; i < sizeof(rev); ++i)
		printf("%c", rev[i]);
	printf("\n");

	return EXIT_SUCCESS;

}

void reverse_line(char s[], char r[], int len)
{
	int i, j;

	for(j = 0, i = len - 1; i >= 0; ++j, --i)
		r[j] = s[i];
}

