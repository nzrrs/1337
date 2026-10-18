#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	size;

	size = ft_strlen(s);
	d = malloc(size + 1);
	if (d == NULL)
		return (NULL);
	memmove(d, s, size + 1);
	return (d);
}
