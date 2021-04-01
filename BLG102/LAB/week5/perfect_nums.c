#include <stdio.h>
#include <stdlib.h>

int main()
{
	int input = 0; 
	int count = 0;

	printf("Enter positive integer: ");
	scanf("%d", &input);

	while(input <= 0)
	{
		printf("Try again. Please enter positive integer: ");
		scanf("%d", &input);
	}

	for(int i = 1; i <= input / 2; i++)
	{
		if(input % i == 0)
		{
			count += i;
		}
	}

	if(count == input)
	{
		printf("%d is a perfect number.\n", input);
	}
	else
	{
		printf("%d is not a perfect number.\n", input);
	}

	return EXIT_SUCCESS;
}