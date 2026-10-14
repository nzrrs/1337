#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dst_len = 0;
	j = 0;
	i = 0;
	if (dsize == 0)
		return (src_len);
	while (dst_len < dsize && dst[dst_len])
		dst_len++;
	if (dst_len == dsize)
		return (dsize + src_len);
	i = dst_len;
	while (src[j] && i < dsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (src_len + dst_len);
}
