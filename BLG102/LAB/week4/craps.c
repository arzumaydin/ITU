#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ITERATION 100000

int main()
{
	srand(time(NULL));

	int iteration = 0;

	double success_rate = 0.0;

	while(iteration < MAX_ITERATION)
	{
		int dice1 = rand() % 6 + 1;

		int dice2 = rand() % 6 + 1;

		int sum = dice1 + dice2;

		if(sum == 7 || sum == 11)
		{
			success_rate += 1;
		}
		else if(sum == 2 || sum == 3 || sum == 12)
		{
			success_rate += 0;
		}
		else
		{
			int new_sum = 0;
			while(new_sum != sum)
			{
				dice1 = rand() % 6 + 1;
				dice2 = rand() % 6 + 1;
				new_sum = dice1 + dice2;
				if(new_sum == 7)
				{
					success_rate += 0;
					break;
				}
			}
			if(new_sum != 7)
			{
				success_rate += 1;
			}
		}

		iteration++;
	}	

	success_rate = success_rate / MAX_ITERATION;

	printf("Success rate after %d times craps is played: %f\n", MAX_ITERATION, success_rate);

	return EXIT_SUCCESS;
}