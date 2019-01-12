/*
	A program to remove multi-line comments from a C program.
*/
#include<stdio.h>
#include<stdbool.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1
#define MAXLINE			1000

bool s_flag = false;	//	s_flag -> slash flag
int s_count = 0;		//	s_count -> slash count

int main(void)
{
	int i, c, len = 0;
	char line[MAXLINE];

	for(i = 0; (c = getchar()) != EOF; ++i)
	{
		line[i] = c;
		//	if a '/' is encountered, set s_flag to true and increment s_count
		if(line[i] == '/')
		{
			s_flag = true;
			s_count++;
			//	as well as decrement 'i' so that we can write over it
			--i;
		}
		//	if s_flag is true and s_count is not even
		//	that is, you delete all the characters inside a comment
		else if(s_flag == true && s_count % 2 != 0)
			--i;
		//	else all is well and increment the length
		else
		{
			s_flag = false;
			++len;
		}
	}

	printf("\n\nAfter removing comments:\n");
	printf("%s\n", line);

	return EXIT_SUCCESS;
}

