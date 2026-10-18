
#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 0;
	while (c <= 127)
	{
		if (ft_toupper(c) != toupper(c))
			printf("FAIL: %d\n", c);
		c++;
	}
	printf("Test finished\n");
	return (0);
}
