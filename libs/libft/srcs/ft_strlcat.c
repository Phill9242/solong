#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count_dst;
	size_t	count_src;
	size_t	i;

	i = 0;
	count_src = ft_strlen(src);
	count_dst = 0;
	while (dst[count_dst] && dstsize > 0)
	{
		count_dst++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		dst[count_dst + i++] = *src;
		src++;
		dstsize--;
	}
	if (dstsize)
		dst[count_dst + i] = 0;
	return (count_src + count_dst);
}
