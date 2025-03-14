char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	len_sub;
	size_t	i;

	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len_s - start > len)
		len_sub = len;
	else
		len_sub = len_s - start;
	sub = (char *)malloc((len_sub + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len_sub)
	{
		sub[i] = s[(size_t)start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
