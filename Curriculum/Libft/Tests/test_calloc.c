#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void				*ft_calloc(size_t nmemb, size_t size);

#define G "\033[32m"
#define R "\033[31m"
#define X "\033[0m"

typedef struct s_test
{
	const char		*name;
	size_t			n;
	size_t			s;
}					t_test;

static const t_test	g_tests[] = {
	{"0 x 0", 0, 0}, {"0 x 1", 0, 1}, {"1 x 0", 1, 0}, {"1 x 1", 1, 1},
		{"1 x sizeof(int)", 1, sizeof(int)}, {"5 x 1", 5, 1},
		{"5 x sizeof(int)", 5, sizeof(int)}, {"10 x sizeof(long)", 10,
		sizeof(long)}, {"100 x 1", 100, 1}, {"1000 x 8", 1000, 8}, {"1 x 1024",
		1, 1024}, {"1024 x 1024", 1024, 1024}, {"1 x 1000000", 1, 1000000},
		{"4096 x 4096", 4096, 4096}, {"SIZE_MAX x 2 (overflow)", SIZE_MAX, 2},
		{"2 x SIZE_MAX (overflow)", 2, SIZE_MAX},
		{"SIZE_MAX x SIZE_MAX (overflow)", SIZE_MAX, SIZE_MAX},
		{"SIZE_MAX/2+1 x 2 (overflow)", SIZE_MAX / 2 + 1, 2},
		{"INT_MAX x INT_MAX (overflow 32b)", INT_MAX, INT_MAX},
		{"SIZE_MAX x 1 (too big)", SIZE_MAX, 1}, {"1 x SIZE_MAX (too big)", 1,
		SIZE_MAX}, {"SIZE_MAX/2 x 1 (too big)", SIZE_MAX / 2, 1},
};

static int	all_zero(const unsigned char *p, size_t len)
{
	size_t	i;

	for (i = 0; i < len; i++)
		if (p[i] != 0)
			return (0);
	return (1);
}

int	main(void)
{
	size_t	count;

	count = sizeof(g_tests) / sizeof(g_tests[0]);
	size_t i, total;
	int ok_null, ok_zero, ok_write, ok, fails = 0;
	void *a, *b;
	printf("%-3s | %-34s | %-9s | %-6s | %-6s | %s\n", "#",
		"TEST (nmemb x size)", "NULL match", "ZEROED", "WRITE", "RESULT");
	printf("----+------------------------------------+------------+--------+--------+-------\n");
	for (i = 0; i < count; i++)
	{
		b = calloc(g_tests[i].n, g_tests[i].s);
		a = ft_calloc(g_tests[i].n, g_tests[i].s);
		ok_null = ((a == NULL) == (b == NULL));
		ok_zero = 1;
		ok_write = 1;
		if (a && b && !__builtin_mul_overflow(g_tests[i].n, g_tests[i].s,
				&total))
		{
			ok_zero = all_zero(a, total) && (memcmp(a, b, total) == 0);
			if (total > 0)
			{
				memset(a, 0xFF, total);
				ok_write = (((unsigned char *)a)[total - 1] == 0xFF);
			}
		}
		ok = ok_null && ok_zero && ok_write;
		if (!ok)
			fails++;
		printf("%-3zu | %-34s | %-10s | %-6s | %-6s | %s\n", i + 1,
			g_tests[i].name, ok_null ? G "OK" X : R "FAIL" X,
			ok_zero ? G "OK" X : R "FAIL" X, ok_write ? G "OK" X : R "FAIL" X,
			ok ? G "OK" X : R "FAIL" X);
		free(a);
		free(b);
	}
	printf("\n%zu/%zu passed\n", count - fails, count);
	return (fails != 0);
}
