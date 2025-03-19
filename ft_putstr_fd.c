#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	if (s == NULL)
		return ;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}
