#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*anc_b1;
	unsigned char	*anc_b2;

	anc_b1 = (unsigned char *)b1;
	anc_b2 = (unsigned char *)b2;
	if (len < 1)
		return (0);
	while (len--)
	{
		if (*anc_b1 != *anc_b2)
		{
			return (*anc_b1 - *anc_b2);
		}
		anc_b1++;
		anc_b2++;
	}
	return (0);
}
