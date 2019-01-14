/*
	Program:	A program to rotate the elements of an array (right or left), by n digits.
*/
#include<stdio.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	-1
//	array size
#define ARRAY_LIMIT		5
//	rotate by how many digits?
#define ROTATE_LEFT		2
#define ROTATE_RIGHT 	3

void display_array(int[]);
void rotate_left(int[], int);
void rotate_right(int[], int);

int main(void)
{
	int array_one[ARRAY_LIMIT] = {1, 2, 3, 4, 5};
	int array_two[ARRAY_LIMIT] = {6, 7, 8, 9, 10};

	printf("Original array:\n");
	display_array(array_one);
	rotate_left(array_one, ROTATE_LEFT);
	printf("After rotating left by %d:\n", ROTATE_LEFT);
	display_array(array_one);
	
	printf("Original array:\n");
	display_array(array_two);
	rotate_right(array_two, ROTATE_RIGHT);
	printf("After rotating right by %d:\n", ROTATE_RIGHT);
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

void rotate_left(int a[], int rot_val)
{
	int i, j;
	/*
		if we rotate by 2 digits(for ex), then the first two digits (elements at first
		two indices) of the array will be shifted to the last two indices.
		The number of elements to be shifted to the last n indices is equal to the
		number by which we are rotating, so we declare an array of size rot_val.
	*/
	int temp[rot_val];

	/*
		Fill the temporary array with the elements at the first n indices, so that they
		aren't overwritten when we shift.
		
		If rotation is by 2, we only need i = 0, 1.
		temp[0] = a[0]
		temp[1] = a[1], so,
		i < rot_val
	*/
	for(i = 0, j = 0; i < rot_val; ++i, ++j)
		temp[i] = a[j];

	/*
		Now we begin to shift normally		
	*/
	for(i = 0, j = 0; i < ARRAY_LIMIT; ++i)
	{
		/*
			Only shift the elements if i + rot_val doesn't overflow.
			a[0] = a[0 + 2]; 2 < ARRAY_LIMIT: TRUE
			a[1] = a[1 + 2]; 3 < ARRAY_LIMIT: TRUE
			a[2] = a[2 + 2]; 4 < ARRAY_LIMIT: TRUE
			a[3] = a[3 + 2]; 5 < ARRAY_LIMIT: FALSE
			at the end, i will be 3
		*/
		if((i + rot_val) < ARRAY_LIMIT)
			a[i] = a[i + rot_val];
		else
		{
			/*
				if j = 0 (< rot_val ?, true)
				then a[3] = temp[0]
				and j increments..
			*/
			if(j < rot_val)
			{
				a[i] = temp[j];
				++j;
			}
		}
	}
}

void rotate_right(int a[], int rot_val)
{
	int i, j;
	//	create a temporary array with as many elements as rot_val
	int temp[rot_val];
	
	int arr_indices = ARRAY_LIMIT - 1;

	//	copy the elements of the last 'rot_val' number of the array,
	//	otherwise they will be overwritten
	for(i = ARRAY_LIMIT - rot_val, j = 0; i < ARRAY_LIMIT; ++i, ++j)
		temp[j] = a[i];
	
	//	rotate the array elements till '(ARRAY_LIMIT - 1) - rot_val', so that we
	//	do not copy over other elements
	for(i = (arr_indices - rot_val); i >= 0; --i)
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

