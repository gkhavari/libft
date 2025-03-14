char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*cpy;

	len = ft_strlen(s);
	cpy = (char *)malloc((len + 1)  * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
