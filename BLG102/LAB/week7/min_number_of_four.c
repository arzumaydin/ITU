#include <stdio.h>
#include <stdlib.h>

int find_min(int a, int b, int c, int d)
{	
	int min = 0;
	if(a < b && a < c && a < d)
	{
		min = a;
	}
	else if(b < a && b < c && b < d)
	{
		min = b;
	}
	else if(c < a && c < b && c < d)
	{
		min = c;
	}
	else if(d < a && d < b && d < c)
	{
		min = d;
	}
	return min;
}

int main()
{
	int a, b, c, d;

	printf("Enter the numbers\n");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("%d", find_min(a,b,c,d));
	
	return EXIT_SUCCESS;
}