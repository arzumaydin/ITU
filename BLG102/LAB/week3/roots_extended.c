#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double a = 0.0, b = 0.0, c = 0.0;
	double x1 = 0.0, x2 = 0.0;
	printf("Enter coefficients a,b,c in order: \n");
	scanf("%lf %lf %lf", &a, &b, &c);

	double discriminant = (b * b - (4.0) * a * c);

	if(discriminant > 0)
	{
		x1 = ((-b) + sqrt(discriminant)) / (2*a);
		x2 = ((-b) - sqrt(discriminant)) / (2*a);

		printf("Roots: %.2f %.2f\n", x1, x2);
	}
	else if(discriminant == 0)
	{
		x1 = ((-b) + sqrt(discriminant)) / (2*a);
		printf("Root: %.2f\n", x1);
	}
	else
	{
		printf("Roots are not real numbers!\n");
	}

	return EXIT_SUCCESS;
}