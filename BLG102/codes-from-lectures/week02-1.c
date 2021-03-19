#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main()
{
	printf("integer: %ld bytes\n", sizeof(int));
	printf("short integer: %ld bytes\n", sizeof(short int));
	printf("long integer: %ld bytes\n", sizeof(long int));

	printf("uint8_t %ld bytes\n", sizeof(uint8_t));
	printf("uint32_t %ld bytes\n", sizeof(uint32_t));

	printf("Minimum int is: %d\n", INT_MIN);
	printf("Maximum int is: %d\n", INT_MAX);

	printf("Minimum short int is: %d\n", SHRT_MIN);
	printf("Maximum int is: %d\n", SHRT_MAX);

	printf("Maximum unsigned short int is: %d\n", USHRT_MAX);
	return 0;
}