int	ft_atoi(const	char *nptr)
{
	long long int	number;
	int				signal;

	signal = 1;
	number = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = (number * 10) + (long long int)(*nptr - 48 );
		nptr++;
	}
	return ((int) number * signal);
}
