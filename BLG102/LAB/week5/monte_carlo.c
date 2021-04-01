#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	double pi = 0.0;

	double x = 0.0;
	double y = 0.0;

	int count = 0;
	int throw = 0;

	printf("Enter number of throws: ");
	scanf("%d", &throw);

	for(int i = 0; i < throw; i++)
	{
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;


		if(x*x + y*y <= 1)
		{
			count++;
		}
 	}

 	pi = (double) count / throw * 4;

 	printf("Pi: %.3lf\n", pi);

	return EXIT_SUCCESS;
}