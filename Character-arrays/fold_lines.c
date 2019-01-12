/*	
	A program to fold long input lines after the last non-blank character.
*/
#include<stdio.h>
#include<stdbool.h>

#define EXIT_SUCCESS		0
#define EXIT_FAILURE		-1

#define MAX_LINE			1000
#define MAX_COLUMN_LENGTH	20		/*	maximum column length in which we want to format the input text	*/

int main(void)
{

	int i, c, len = 0, column_len = 0;
	char line[MAX_LINE];
	//	a flag to check if the program is currently processing a word (if its inside of a word)
	bool is_in_word = false;

	for(i = 0; (c = getchar()) != EOF; ++i)
	{
		line[i] = c;
		//	increment length and column length
		++len;
		++column_len;

		//	if the character is a whitespace character (blank characters), then we are not in a word
		if(line[i] == '\n' || line[i] == ' ' || line[i] == '\t')
			is_in_word = false;
		//	otherwise, we are inside a word
		else
			is_in_word = true;

		//	if the column length has exceeded, if we are not inside a word,
		//	then go to the next line (print '\n') and reset the column length
		//	(column_len = 0)
		if(column_len >= MAX_COLUMN_LENGTH && is_in_word == false)
		{
			//	we need to increment the index of the array, otherwise
			//	we will overwrite an input character with a newline
			++i;
			line[i] = '\n';
			column_len = 0;
		}
		//	else if the column length has exceeded AND IF we are inside a word,
		//	simply put that character inside the array and do nothing
		else if(column_len >= MAX_COLUMN_LENGTH && is_in_word == true)
		{
			line[i] = c;
		}
	}

	printf("%s\n", line);

	return EXIT_SUCCESS;

}


