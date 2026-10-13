#include "libft.h"
#include <stdio.h>

static int	check_result(const char *name, int input, int actual, int expected)
{
	if (actual != expected)
	{
		printf("FAIL: %s(%d) returned %d, expected %d\n", name, input, actual,
			expected);
		return (1);
	}
	return (0);
}

static int	test_isalpha(void)
{
	int	c;
	int	failures;

	failures = 0;
	c = 0;
	while (c <= 255)
	{
		if (check_result("ft_isalpha", c, ft_isalpha(c), ((c >= 'A' && c <= 'Z')
					|| (c >= 'a' && c <= 'z'))))
			failures++;
		c++;
	}
	if (check_result("ft_isalpha", -1, ft_isalpha(-1), 0))
		failures++;
	if (check_result("ft_isalpha", 256, ft_isalpha(256), 0))
		failures++;
	return (failures);
}

static int	test_isdigit(void)
{
	int	c;
	int	failures;

	failures = 0;
	c = 0;
	while (c <= 255)
	{
		if (check_result("ft_isdigit", c, ft_isdigit(c), (c >= '0'
					&& c <= '9')))
			failures++;
		c++;
	}
	if (check_result("ft_isdigit", -1, ft_isdigit(-1), 0))
		failures++;
	if (check_result("ft_isdigit", 256, ft_isdigit(256), 0))
		failures++;
	return (failures);
}

static int	test_isalnum(void)
{
	int	c;
	int	failures;
	int	expected;

	failures = 0;
	c = 0;
	while (c <= 255)
	{
		expected = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
				|| (c >= '0' && c <= '9'));
		if (check_result("ft_isalnum", c, ft_isalnum(c), expected))
			failures++;
		c++;
	}
	if (check_result("ft_isalnum", -1, ft_isalnum(-1), 0))
		failures++;
	if (check_result("ft_isalnum", 256, ft_isalnum(256), 0))
		failures++;
	return (failures);
}

static int	test_isascii(void)
{
	int	c;
	int	failures;

	failures = 0;
	c = -2;
	while (c <= 257)
	{
		if (check_result("ft_isascii", c, ft_isascii(c), (c >= 0 && c <= 127)))
			failures++;
		c++;
	}
	return (failures);
}

static int	test_isprint(void)
{
	int	c;
	int	failures;

	failures = 0;
	c = -2;
	while (c <= 257)
	{
		if (check_result("ft_isprint", c, ft_isprint(c), (c >= 32 && c <= 126)))
			failures++;
		c++;
	}
	return (failures);
}

int	main(void)
{
	int	failures;

	failures = 0;
	failures += test_isalpha();
	failures += test_isdigit();
	failures += test_isalnum();
	failures += test_isascii();
	failures += test_isprint();
	if (failures == 0)
		printf("All tests passed!\n");
	else
		printf("%d test(s) failed.\n", failures);
	return (failures != 0);
}
