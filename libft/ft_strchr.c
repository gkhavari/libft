char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (NULL);
}
