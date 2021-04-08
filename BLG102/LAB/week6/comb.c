#include <stdio.h>
#include <stdlib.h>

int factorial(int a)
{
	int res = 1;
	if(a == 0 || a == 1)
	{
		return 1;
	}
	while(a != 1)
	{
		res *= a;
		a--;
	}
	return res;
}

int combination(int n, int r)
{
	int res = factorial(n) / (factorial(r) * factorial(n-r));
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