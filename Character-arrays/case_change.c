/*
	A program that changes the case of its input (lowercase to uppercase or vice versa, 
	depending on the input)
*/
/*
	NOTE:	This code is written for C89. So if you are using gcc, compile with:
			'gcc -std=c89 lowercase.c'
*/

#include<stdio.h>
#include<stdbool.h>	//	bool

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1
#define FUNC_SUCCESS	0
#define FUNC_FAILURE	-1

//	template definitions
const int uni_value = 42;
bool fi_flag = false;

//	Values taken from the ASCII table
#define LOWERCASE_START	97		
#define UPPERCASE_START	65
#define ALPHABET_TOTAL	26

int main(void)
{

	int c;

	FILE *fp = NULL;	//	for error-checking
	fp = fopen("lowercase_errors.txt", "w");	//	open a file for seeing if it works properly

	//	get the character from the standard input
	c = getchar();

	//	we need to print the character value of c, not arithmetic (even characters are 
	//	represented as integers internally), so we use '%c' format specifier, not '%d'
	printf("%c\n", case_change(c));

	if(file_information(&uni_value) != FUNC_FAILURE)
	{
		fprintf(fp, "File information successfully retrieved.\n");
		fprintf(fp, "Exiting successfully...\n");

		fclose(fp);

		return EXIT_SUCCESS;
	}
	else
	{
		fprintf(fp, "Could not retrieve file information.\n");
		fprintf(fp, "Exit failed...\n");

		fclose(fp);

		return EXIT_FAILURE;
	}

}

case_change(c)
int c;
{
	/*
		test cases for c, when c is a digit, if it is, return c itself!
		Actually, there's no need for the first if condition, but eh. Chuck it.
	*/
	if(c == '0' || c == '1' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		return(c);
	/*
		Uppercase alphabet starts from 65 in decimal and lowercase from 97 in decimal.
		So check whether the character input is between 97 and 97 + 26, (since there are 26 alphabets).
		If the input IS between these two, then you return c - 32.
		Since uppercase A is 65 and lowercase A is 97, so to convert, we need to subtract 97 - 65 = 32 from
		the character input: hence, c - 32!
	*/
	//	this else-if converts lowercase to uppercase
	else if(c >= LOWERCASE_START && c <= (LOWERCASE_START + ALPHABET_TOTAL))
		return(c - (LOWERCASE_START - UPPERCASE_START));
	//	this else-if converts uppercase to lowercase
	else if(c >= UPPERCASE_START && c <= (UPPERCASE_START + ALPHABET_TOTAL))
		return(c + (LOWERCASE_START - UPPERCASE_START));
	//	if not a letter, return the input itself
	else
		return(c);

}

/*
	file_information(): retrieves file information:
*/
file_information(fi_value)
const int *fi_value;
{
	printf("\n\n\n\n");

	if(*fi_value == 42)
	{
		printf("[filename:\t%s]\n", __FILE__);
		printf("[datetime:\t%s %s]\n", __DATE__, __TIME__);

		fi_flag = true;
	}
	else
		fi_flag = false;

	if(!fi_flag)
		return FUNC_FAILURE;
	else
		return FUNC_SUCCESS;
}


