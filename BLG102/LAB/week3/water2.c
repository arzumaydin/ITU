#include <stdio.h>
#include <stdlib.h>

int main()
{
	char temp;
	double degree = 0.0;
	double altitude = 0.0;
	printf("Enter temperature (end with F for Fahrenheit or C for Celsius): ");
	scanf("%lf %c", &degree, &temp);
	printf("Enter altitude in meters: ");
	scanf("%lf", &altitude);


	if(temp == 'C')
	{

		if(degree < 0)
		{
			printf("Water is Solid (Ice) at %.2f degrees Celsius\n", degree);
		}
		else if(degree > 0 && degree < (100 - (altitude / 300)))
		{
			printf("Water is Liquid at %.2f degrees Celsius\n", degree);
		}
		else
		{
			printf("Water is Gas (Vapor) at %.2f degrees Celsius\n", degree);
		}
	}
	else if(temp == 'F')
	{
		if(degree < 32)
		{
			printf("Water is Solid (Ice) at %.2f degrees Fahrenheit\n", degree);
		}
		else if(degree > 0 && degree < (212 - (5.0 / 9.0) * (altitude / 300)))
		{
			printf("Water is Liquid at %.2f degrees Fahrenheit\n", degree);
		}
		else
		{
			printf("Water is Gas (Vapor) at %.2f degrees Fahrenheit\n", degree);
		}
	}
	else
	{
		printf("Please enter temperature unit as either C or F.\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}