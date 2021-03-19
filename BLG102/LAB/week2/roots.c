#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double a, b, c;
	printf("Enter coefficients a,b,c in order: \n");
	scanf("%lf %lf %lf", &a, &b, &c);

	double discriminant = (b * b - (4.0) * a * c);

	if(discriminant >= 0)
	{
		double x1 = ((-b) + sqrt(discriminant)) / (2*a);
		double x2 = ((-b) - sqrt(discriminant)) / (2*a);

		printf("Roots: %.2f %.2f\n", x1, x2);
	}
	else
	{
		printf("Roots are not real numbers!\n");
	}

	return EXIT_SUCCESS;
}