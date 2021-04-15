#include <stdio.h>
#include <stdlib.h>

#define pi 3.14159265358979323846

double perimeter(double a, double b)
{
	return 2 * (a + b);
}

double area(double a, double b)
{
	return a * b;
}

double c_area(double r)
{
	return pi * r * r;
}

double c_circ(double r)
{
	return 2 * pi * r;
}

int main()
{
	char shape;

	printf("Enter the shape type, e.g., rectangle, square, or circle\n");
	scanf("%c", &shape);

	if(shape == 'c')
	{
		double radius = 0.0;
		printf("Enter the radius of the circle\n");
		scanf("%lf", &radius);
		printf("Circumference: %.6lf\n", c_circ(radius));
		printf("Area: %.6lf\n", c_area(radius));
	}
	else if(shape == 's')
	{
		double side_length = 0.0;
		printf("Enter the side length of the square\n");
		scanf("%lf", &side_length);
		printf("Perimeter: %.6lf\n", perimeter(side_length, side_length));
		printf("Area: %.6lf\n", area(side_length, side_length));
	}
	else if(shape == 'r')
	{
		double a = 0.0;
		double b = 0.0;
		printf("Enter the side lengths of the rectangle\n");
		scanf("%lf %lf", &a, &b);
		printf("Perimeter: %.6lf\n", perimeter(a,b));
		printf("Area: %.6lf\n", area(a,b));
	}

	return EXIT_SUCCESS;
}