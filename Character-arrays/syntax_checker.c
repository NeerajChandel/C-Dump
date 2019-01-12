/*
	A rudimentary program to check the syntax of a C program.
*/
#include<stdio.h>
#include<stdbool.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1

#define MAXLINE			1000

//	we need these variables to count the number of parentheses, brackets and quotes(single and double)
int num_parentheses = 0;
int num_brackets = 0;
int num_single_quotes = 0;
int num_double_quotes = 0;

//	to copy the input text to a new array
void copy(char[], char[]);

int main(void)
{

	int c, len = 0, i;

	char line[MAXLINE];
	char save[MAXLINE];

	for(i = 0; (c = getchar()) != EOF; ++i)
	{
		line[i] = c;
		++len;
	}

	/*
		We need to apply the checks on the data, so we need to save(or copy) the input text
		into another array; so we call copy()!
	*/
	copy(line, save);

	for(i = 0; i < len; ++i)
	{
		//	all of the checks are performed, and counters incremented
		if(save[i] == '{')
			num_parentheses++;
		else if(save[i] == '}')
			num_parentheses++;
		else if(save[i] == '(')
			num_brackets++;
		else if(save[i] == ')')
			num_brackets++;
		else if(save[i] == '\'')
			num_single_quotes++;
		else if(save[i] == '\"')
			num_double_quotes++;
	}

	/*
		It's pretty simple to see that for the number of parentheses, brackets and
		quotes(single as well as double) to be balanced, their counts (their numbers)
		need to be even! So, it is all that we need to check:
	*/
	printf("----------------------------------------\n");
	if(num_parentheses % 2 != 0)
		printf("SYNTAX ERROR: Unbalanced parentheses.\n");
	if(num_brackets % 2 != 0)
		printf("SYNTAX ERROR: Unbalanced brackets.\n");
	if(num_single_quotes % 2 != 0)
		printf("SYNTAX ERROR: Unbalanced single quotes.\n");
	if(num_double_quotes % 2 != 0)
		printf("SYNTAX ERROR: Unbalanced double quotes.\n");
	printf("----------------------------------------\n");

	/*
	printf("-----------------------------\n");
	printf("%s\n", save);
	printf("-----------------------------\n");
	*/
	return EXIT_SUCCESS;

}

//	a simple copy() function
void copy(char src[], char dest[])
{
	int i = 0;

	while((dest[i] = src[i]) > 0)
		++i;
}

