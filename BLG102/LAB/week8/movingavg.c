#include <stdlib.h>
#include <stdio.h>

int main()
{
	int size = 0;
	int window = 0;
	double total = 0;

	printf("Enter the size of sequence: ");
	scanf("%d", &size);

	int sequence[size];
	printf("Enter numbers in the sequence: \n");

	for(int i = 0; i < size; i++)
	{
		scanf("%d", &sequence[i]);
		total += sequence[i];
	}
	printf("Enter moving average window: ");
	scanf("%d", &window);
	double cavg = total / size; 

	printf("Cumulative Average: %.3lf\n", cavg);

	double sum = 0;
	double mavg = 0;

	for(int i = 0; i < size; i ++)
	{
		sum += sequence[i];
	
		if(i + 1 >= window)
		{
			sum -= sequence[i - window];
		}
		
		mavg = (double)(sum / window);
		printf("Moving Average for window %d : %.3lf\n", i+1, mavg);
	}
	
	return EXIT_SUCCESS;
}