char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (s[i] != (char)c && i)
		i--;
	if (s[i] != (char)c)
		return (0);
	else
		return ((char *)(s + i));
}