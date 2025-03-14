void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	r = malloc(nmemb * size);
	if (r == NULL)
		return (NULL);
	ft_bzero(r, nmemb * size);
	return (r);
}
