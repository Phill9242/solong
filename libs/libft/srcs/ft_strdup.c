#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		len;

	len = ft_strlen(str);
	cpy = malloc (len + 1);
	if (!str || !cpy)
		return (NULL);
	ft_memcpy(cpy, str, len);
	cpy[len] = 0;
	return (cpy);
}
