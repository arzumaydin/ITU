#include <stdio.h>

int main()
{
	double weight = 0.0;
	printf("Enter weight (in kg): ");
	scanf("%lf", &weight);

	double height = 0.0;
	printf("Enter height (in m): ");
	scanf("%lf", &height);

	double bmi = weight / (height * height);
	printf("Body mass index: %.1f\n", bmi);
	
	return 0;
}

// lf for double, f for float