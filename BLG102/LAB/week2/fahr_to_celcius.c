#include <stdio.h>

int main()
{
	double temp = 0.0;
	printf("Enter temperature in fahrenheit: ");
	scanf("%lf", &temp);

	double celcius = (5.0/9.0)*(temp - 32.0);
	printf("Temperature in celcius: %.1f\n", celcius);
	return 0;
}