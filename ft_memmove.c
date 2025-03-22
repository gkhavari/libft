#include "libft.h"

void	*reverse_copy(char *dest, const char *src, size_t len)
{
	while (len > 0)
	{
		dest[len - 1] = src[len - 1];
		len--;
	}
	return ((void *)dest);
}

void	*normal_copy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return ((void *)dest);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest == NULL || src == NULL)
		return (NULL);
	if (dest > src)
		return (reverse_copy((char *)dest, (char *)src, len));
	else
		return (normal_copy((char *)dest, (char *)src));
}
