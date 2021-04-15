#include <stdio.h>
#include <stdlib.h>

int fibonacci(int index)
{
	if(index == 1)
	{
		return 0;
	}
	else if(index == 2)
	{
		return 1;
	}
	else
	{
		return (fibonacci(index - 1) + fibonacci(index - 2));
	}
}

int main()
{
	int index = 0;
	printf("Enter the index of the Fibonacci series\n");
	scanf("%d", &index);
	printf("%d", fibonacci(index));
	
	return EXIT_SUCCESS;
}