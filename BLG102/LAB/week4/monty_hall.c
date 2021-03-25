#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ITERATION 100000

int main()
{
	int iteration = 0;

	int switched = 1;

	int not_switched = 1;

	srand(time(NULL));

	double srate = 0.0;
	double rate = 0.0;

	while(iteration < MAX_ITERATION)
	{
		int prize_door = rand() % 3 + 1;

		int chosen_door = rand() % 3 + 1;

		int third_door = rand() % 3 + 1;

		while(third_door == prize_door || third_door == chosen_door)
		{
			third_door = rand() % 3 + 1;
		}

		int switched = rand() % 2;

		if(chosen_door == prize_door && not_switched) // not switched
		{
			rate += 1;
		}
		else if(chosen_door == prize_door && switched)
		{
			srate += 0;
		}
		else if(chosen_door != prize_door && switched)
		{
			srate += 1;
		}
		else if(chosen_door != prize_door && not_switched)
		{
			rate += 0;
		}

		iteration++;
	}

	srate = srate / MAX_ITERATION;
	rate = rate / MAX_ITERATION;

	printf("After %d Iteration Success Rate if Switched: %.3f\n", MAX_ITERATION, srate);
	printf("After %d Iteration Success Rate if Not Switched: %.3f\n", MAX_ITERATION, rate);

	return EXIT_SUCCESS;
}