#include "libft.h"

void	ft_del_content(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = 0;
	free (str);
}

char	*ft_split_rtn(char *str, char *keep)
{
	int		i;
	char	*rtn;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	rtn = ft_calloc ((i + 1), sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = str[i];
	while (str[++i])
		keep[j++] = str[i];
	ft_del_content (str);
	return (rtn);
}

char	*ft_cpy_and_increase(char *str)
{
	int		i;
	char	*rtn;

	i = -1;
	rtn = ft_calloc ((ft_strlen(str) + BUFFER_SIZE + 1), sizeof(char));
	while (str[++i])
		rtn[i] = str[i];
	ft_del_content (str);
	return (rtn);
}
