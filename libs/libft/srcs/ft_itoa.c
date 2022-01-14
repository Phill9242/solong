#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	while (n < 0)
	{
		size++;
		n /= 10;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int	ft_div(int n, int size, char *rtn)
{
	long int	div;

	div = 1;
	while (size-- > 1)
		div *= 10;
	if (n < 0)
	{
		rtn[0] = '-';
		div /= 10;
	}
	return (div);
}

static char	*ft_convert(int n, char *rtn, int size, long int div)
{
	long int	number;
	int			i;

	i = 0;
	number = (long int) n;
	if (n < 0)
	{
		i++;
		size--;
		number *= -1;
	}
	while (size--)
	{
		rtn[i++] = (char)(number / div) + '0';
		number -= div * (number / div);
		div /= 10;
	}
	rtn[i] = 0;
	return (&rtn[0]);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*rtn;
	long int	div;

	if (n == 0)
	{
		rtn = (char *) malloc (2 * sizeof(char));
		rtn[0] = '0';
		rtn[1] = 0;
		return (rtn);
	}
	size = ft_size(n);
	rtn = (char *) malloc ((size + 1) * sizeof(char));
	if (!rtn)
		return (0);
	div = ft_div (n, size, rtn);
	rtn = ft_convert(n, rtn, size, div);
	return (rtn);
}
