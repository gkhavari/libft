/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:53:37 by ubuntu            #+#    #+#             */
/*   Updated: 2025/03/16 16:26:31 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len - 1] == (unsigned char)c)
			return ((char *)&s[len - ]);
		len--;
	}
	if (s[len] == (unsigned char)c)
		return ((char *)&s[len]);
	return (NULL);
}
