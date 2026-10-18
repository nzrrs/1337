#include <stdio.h>
#include <stdlib.h>

int					ft_atoi(const char *nptr);

#define G "\033[32m"
#define R "\033[31m"
#define X "\033[0m"

static const char	*g_tests[] = {
	/* basic */
	"0",
	"1",
	"-1",
	"42",
	"-42",
	"+42",
	"123456789",
	"-123456789",
	/* whitespace */
	" 42",
	"\t42",
	"\n42",
	"\v42",
	"\f42",
	"\r42",
	" \t\n\v\f\r42",
	"   -42",
	"   +42",
	/* trailing garbage */
	"42abc",
	"42 42",
	"-42abc",
	"12-3",
	"12+3",
	"4 2",
	/* invalid start */
	"abc",
	"",
	" ",
	"+",
	"-",
	"+-42",
	"-+42",
	"--42",
	"++42",
	"- 42",
	"+ 42",
	"a42",
	".5",
	"0x1A",
	/* leading zeros */
	"0042",
	"-0042",
	"+0042",
	"000000000000000000000042",
	"-00000",
	/* limits */
	"2147483647",
	"-2147483648",
	/* overflow */
	"2147483648",
	"2147483649",
	"2147483650",
	"4294967295",
	"4294967296",
	"4294967297",
	"9999999999",
	"99999999999999999999",
	"9223372036854775807",
	"9223372036854775808",
	"18446744073709551615",
	"18446744073709551616",
	"999999999999999999999999999999",
	/* underflow */
	"-2147483649",
	"-2147483650",
	"-4294967295",
	"-4294967296",
	"-9999999999",
	"-99999999999999999999",
	"-9223372036854775808",
	"-9223372036854775809",
	"-18446744073709551616",
	"-999999999999999999999999999999",
};

static int	show(const char *s)
{
	char	buf[26];
	int		i;

	for (i = 0; s[i] && i < 22; i++)
	{
		if (s[i] == '\n')
			buf[i] = 'n';
		else if (s[i] == '\t')
			buf[i] = 't';
		else if (s[i] == '\v')
			buf[i] = 'v';
		else if (s[i] == '\f')
			buf[i] = 'f';
		else if (s[i] == '\r')
			buf[i] = 'r';
		else
			buf[i] = s[i];
	}
	buf[i] = 0;
	return (printf("\"%s\"%s", buf, s[i] ? "..." : ""));
}

int	main(void)
{
	size_t	count;

	count = sizeof(g_tests) / sizeof(g_tests[0]);
	size_t i, fails = 0;
	int a, b, w;
	printf("%-3s | %-28s | %-12s | %-12s | %s\n", "#", "INPUT", "LIBC", "MINE",
		"RESULT");
	printf("----+------------------------------+--------------+--------------+-------\n");
	for (i = 0; i < count; i++)
	{
		b = atoi(g_tests[i]);
		a = ft_atoi(g_tests[i]);
		if (a != b)
			fails++;
		printf("%-3zu | ", i + 1);
		w = show(g_tests[i]);
		printf("%*s | %-12d | %-12d | %s\n", 28 - w, "", b, a,
			a == b ? G "OK" X : R "FAIL" X);
	}
	printf("\n%zu/%zu passed\n", count - fails, count);
	return (fails != 0);
}
