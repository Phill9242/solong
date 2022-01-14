#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*anchor;

	anchor = (unsigned char *)dest;
	while (len--)
		*anchor++ = (unsigned char) c;
	return (dest);
}
