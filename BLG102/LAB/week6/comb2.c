#include <stdio.h>
#include <stdlib.h>

int combination(int n, int r)
{
	int res = 1;
	int denominator = 1;
	int a = r;

	for(int i = 0; i < a; i++)
	{
		res *= n;
		n--;
		denominator *= r;
		r--;
	}

	res /= denominator;

	return res;
}

int main()
{
	int n = 0;
	int r = 0;
	printf("Enter n and r: ");
	scanf("%d %d", &n, &r);
	printf("Combination C(n,r) = %d\n", combination(n,r));

	return EXIT_SUCCESS;
}