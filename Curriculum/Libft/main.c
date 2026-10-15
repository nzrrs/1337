#include <limits.h>
#include <stdio.h>

int	main(void)
{
	printf("int: %zu bytes\n", sizeof(int));
	printf("long: %zu bytes\n", sizeof(long));
	printf("INT_MAX: %d\n", INT_MAX);
	printf("LONG_MAX: %ld\n", LONG_MAX);
	return (0);
}
