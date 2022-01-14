#include "libft.h"

static int	ft_ini_index_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = -1;
	while (set[++j] && s1[i])
	{
		if (set[j] == s1[i])
		{
			i++;
			j = -1;
		}
	}
	len = ft_strlen(s1);
	if (set && i >= len)
		return (-1);
	return (i);
}

static int	ft_final_index(char const *s1, char const *set, int len)
{
	int	j;

	j = -1;
	while (set[++j] && s1[len])
	{
		if (set[j] == s1[len])
		{
			len--;
			j = -1;
		}
	}
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	int		ini_index_s1;
	int		final_index_s1;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ini_index_s1 = ft_ini_index_strtrim(s1, set);
	if (ini_index_s1 == -1)
	{
		rtn = (char *) malloc(sizeof(char));
		if (!rtn)
			return (NULL);
		rtn[0] = 0;
		return (rtn);
	}
	final_index_s1 = ft_final_index(s1, set, len - 1);
	rtn = (char *) malloc((final_index_s1 - ini_index_s1 + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	while (ini_index_s1 < final_index_s1)
		rtn[i++] = s1[ini_index_s1++];
	rtn[i] = 0;
	return (rtn);
}
