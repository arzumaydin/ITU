#include <stdio.h>
#include <stdlib.h>

#define KM_PER_MILE 1.6093

int main()
{
	const double switch_on = 2.50; // in dollars (read only variable)
	const double per_unit = 0.50;
	const double unit_distance = 0.2;
	const double minimal_fare = 13.00;
	double distance = 0.0; // travel distance in miles
	double distance_km = 0.0;
	double fare = 0.0; // in dollars

	printf("Enter the distance (in miles): ");
	scanf("%lf", &distance_km);

	distance = distance_km / KM_PER_MILE;

	fare = switch_on + per_unit * (int)(distance / unit_distance);

	if(fare < minimal_fare)
	{
		fare = minimal_fare;
	}

	printf("Taxi fare: $%.2f\n", fare);

	return EXIT_SUCCESS;
}