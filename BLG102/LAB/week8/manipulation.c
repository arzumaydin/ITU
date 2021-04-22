#include <stdio.h>
#include <stdlib.h>

#define size 10
#define qsize 4

int main()
{
	int queries[4][3] = {{0,4,3}, {3,7,7}, {5,8,1}, {5,8,1}};
	int arr[10] = {0};
	int max = 0;

	printf("Original Array: ");
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	for(int i = 0; i < qsize; i++)
	{
		printf("Manipulation of array %d : ", i + 1);
		for(int j = queries[i][0]; j < queries[i][1]; j++)
		{
			arr[j] += queries[i][2];
			if(arr[j] > max)
			{
				max = arr[j];
			}
		}
		for(int j = 0; j < size; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	printf("Max element: %d\n", max);
	return EXIT_SUCCESS;
}