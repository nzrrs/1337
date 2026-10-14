/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:01:57 by nsadiki           #+#    #+#             */
/*   Updated: 2026/10/14 21:27:38 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		if (result > (LONG_MAX - (*nptr - '0')) / 10 && sign == 1)
			return (-1);
		else if (result > (LONG_MAX - (*nptr - '0')) / 10 && sign == -1)
			return (0);
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

int	main(void)
{
	printf("Test 1:  %d | %d\n", atoi("42"), ft_atoi("42"));
	printf("Test 2:  %d | %d\n", atoi("-42"), ft_atoi("-42"));
	printf("Test 3:  %d | %d\n", atoi("+42"), ft_atoi("+42"));
	printf("Test 4:  %d | %d\n", atoi("0"), ft_atoi("0"));
	printf("Test 5:  %d | %d\n", atoi("-0"), ft_atoi("-0"));
	printf("Test 6:  %d | %d\n", atoi("+0"), ft_atoi("+0"));
	printf("Test 7:  %d | %d\n", atoi("00042"), ft_atoi("00042"));
	printf("Test 8:  %d | %d\n", atoi("00000"), ft_atoi("00000"));
	printf("\n--- Whitespace ---\n");
	printf("Test 9:  %d | %d\n", atoi(" 42"), ft_atoi(" 42"));
	printf("Test 10: %d | %d\n", atoi("   42"), ft_atoi("   42"));
	printf("Test 11: %d | %d\n", atoi("\t42"), ft_atoi("\t42"));
	printf("Test 12: %d | %d\n", atoi("\n42"), ft_atoi("\n42"));
	printf("Test 13: %d | %d\n", atoi("\v42"), ft_atoi("\v42"));
	printf("Test 14: %d | %d\n", atoi("\f42"), ft_atoi("\f42"));
	printf("Test 15: %d | %d\n", atoi("\r42"), ft_atoi("\r42"));
	printf("Test 16: %d | %d\n", atoi(" \t\n -42"), ft_atoi(" \t\n -42"));
	printf("Test 17: %d | %d\n", atoi("42 "), ft_atoi("42 "));
	printf("Test 18: %d | %d\n", atoi("42 56"), ft_atoi("42 56"));
	printf("\n--- Invalid input ---\n");
	printf("Test 19: %d | %d\n", atoi(""), ft_atoi(""));
	printf("Test 20: %d | %d\n", atoi(" "), ft_atoi(" "));
	printf("Test 21: %d | %d\n", atoi("abc"), ft_atoi("abc"));
	printf("Test 22: %d | %d\n", atoi("abc42"), ft_atoi("abc42"));
	printf("Test 23: %d | %d\n", atoi("+"), ft_atoi("+"));
	printf("Test 24: %d | %d\n", atoi("-"), ft_atoi("-"));
	printf("Test 25: %d | %d\n", atoi("++42"), ft_atoi("++42"));
	printf("Test 26: %d | %d\n", atoi("--42"), ft_atoi("--42"));
	printf("Test 27: %d | %d\n", atoi("+-42"), ft_atoi("+-42"));
	printf("Test 28: %d | %d\n", atoi("-+42"), ft_atoi("-+42"));
	printf("Test 29: %d | %d\n", atoi("42abc"), ft_atoi("42abc"));
	printf("Test 30: %d | %d\n", atoi("42.5"), ft_atoi("42.5"));
	printf("\n--- Signs and digits ---\n");
	printf("Test 31: %d | %d\n", atoi("  +42"), ft_atoi("  +42"));
	printf("Test 32: %d | %d\n", atoi("  -42"), ft_atoi("  -42"));
	printf("Test 33: %d | %d\n", atoi("  - 42"), ft_atoi("  - 42"));
	printf("Test 34: %d | %d\n", atoi("  + 42"), ft_atoi("  + 42"));
	printf("Test 35: %d | %d\n", atoi("123abc456"), ft_atoi("123abc456"));
	printf("Test 36: %d | %d\n", atoi("-123abc"), ft_atoi("-123abc"));
	printf("Test 37: %d | %d\n", atoi("+123abc"), ft_atoi("+123abc"));
	printf("Test 38: %d | %d\n", atoi("007"), ft_atoi("007"));
	printf("Test 39: %d | %d\n", atoi("999"), ft_atoi("999"));
	printf("Test 40: %d | %d\n", atoi("-999"), ft_atoi("-999"));
	printf("\n--- Integer boundaries ---\n");
	printf("Test 41: %d | %d\n", atoi("21474836489"), ft_atoi("21474836489"));
	printf("Test 42: %d | %d\n", atoi("-2147483649"), ft_atoi("-2147483649"));
	printf("Test 43: %d | %d\n", atoi("214748364"), ft_atoi("214748364"));
	printf("Test 44: %d | %d\n", atoi("-214748364"), ft_atoi("-214748364"));
	printf("\n--- Multiple zeros ---\n");
	printf("Test 45: %d | %d\n", atoi("0000001"), ft_atoi("0000001"));
	printf("Test 46: %d | %d\n", atoi("-00042"), ft_atoi("-00042"));
	printf("Test 47: %d | %d\n", atoi("+00042"), ft_atoi("+00042"));
	printf("Test 48: %d | %d\n", atoi("000"), ft_atoi("000"));
	return (0);
}
