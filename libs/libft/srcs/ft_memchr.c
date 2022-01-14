#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)b;
	while (len--)
	{
		if (s[i] == (char)c)
			return ((void *)(b + i));
		i++;
	}
	return (0);
}
