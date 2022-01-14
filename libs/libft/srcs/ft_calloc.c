#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*rtn;

	rtn = malloc(number * size);
	if (!rtn)
		return (NULL);
	ft_bzero (rtn, number * size);
	return (rtn);
}
