#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double height = 0.0;
	double weight = 0.0;
	printf("Enter height (in cm) and weight(in gr): ");
	scanf("%lf %lf", &height, &weight);

	double bsa = 0.0003207 * pow(height, 0.3) * pow(weight, 0.7285 - (0.0188 * log10(weight)));

	printf("Body Surface Area: %.2f metersquares\n", bsa);
	return EXIT_SUCCESS;
}