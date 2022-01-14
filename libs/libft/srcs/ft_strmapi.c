#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;

	i = 0;
	rtn = (char *) malloc ((ft_strlen(s) + 1) * sizeof (char));
	if (!rtn)
		return (NULL);
	while (s[i])
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
