#include "../include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret1;
	int	ret2;

	ret1 = printf("Hello %s, number: %d\n", "world", 42);
	ret2 = ft_printf("Hello %s, number: %d\n", "world", 42);
	printf("printf return: %d\n", ret1);
	printf("ft_printf return: %d\n", ret2);
	return (0);
}
