#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ARRAY_SIZE 20

bool isfound(int* arr, int num)
{
	int i = 0;
	while(i < ARRAY_SIZE)
	{
		if(arr[i] == num)
		{
			return true;
		}
		i++;
	}
	return false;
}

void swap(int* first, int* second)
{
	int temp;
	for(int i = 0; i < ARRAY_SIZE / 2; i++)
	{
		temp = *first;
		*first = *second;
		*second = temp;

		first++;
		second--;
	}
}

void random_fill_array(int* arr)
{
	srand(time(NULL));
	int i = 0;

	while(i < ARRAY_SIZE)
	{
		int num = rand() % ARRAY_SIZE + 1;
		if(isfound(arr, num) == false)
		{
			arr[i] = num;
			i++;
		}
	}
}

int main()
{
	int taxis[ARRAY_SIZE];
	random_fill_array(taxis);

	printf("ORIGINAL ARRAY: ");
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%-5d", taxis[i]);
	}
	printf("\n");

	int* first = &taxis[0];
	int* second = &taxis[ARRAY_SIZE - 1];

	swap(first, second);

	printf("NEXT DAY ARRAY: ");
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%-5d", taxis[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}