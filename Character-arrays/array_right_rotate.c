#include<stdio.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1
//	array size
#define ARRAY_LIMIT		5
//	rotate by how many digits?
#define ROTATE_LEFT		1
#define ROTATE_RIGHT 	3

void display_array(int[]);
void rotate_right(int[], int);

int main(void)
{
	int array_one[ARRAY_LIMIT] = {1, 2, 3, 4, 5};
	int array_two[ARRAY_LIMIT] = {1, 2, 3, 4, 5};

	rotate_right(array_two, ROTATE_RIGHT);
	display_array(array_two);

	return EXIT_SUCCESS;

}

void display_array(int a[])
{
	int i;

	for(i = 0; i < ARRAY_LIMIT; ++i)
		printf("a[%d] = %d; ", i, a[i]);
	printf("\n");
}

void rotate_right(int a[], int rot_val)
{
	int i, j;
	//	create a temporary array with as many elements as rot_val
	int temp[rot_val];
	
	//	copy the elements of the last 'rot_val' number of the array,
	//	otherwise they will be overwritten
	for(i = ARRAY_LIMIT - rot_val, j = 0; i < ARRAY_LIMIT; ++i, ++j)
		temp[j] = a[i];
	
	//	rotate the array elements till '(ARRAY_LIMIT - 1) - rot_val', so that we
	//	do not copy over other elements
	for(i = ((ARRAY_LIMIT - 1) - rot_val); i >= 0; --i)
	{
		a[rot_val + i] = a[i];
	}

	//	copy the temporarily taken elements back, at the bginning of the array,
	//	till 'rot_val' number of indices
	for(i = 0, j = 0; i < rot_val; ++i, ++j)
		a[i] = temp[j];

/*
	for(i = 0; i < rot_val; ++i)
		printf("%d ", temp[i]);
	printf("\n");
*/
}
