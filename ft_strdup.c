/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:53:11 by ubuntu            #+#    #+#             */
/*   Updated: 2025/03/16 16:25:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*cpy;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	cpy = (char *)malloc((len + 1) * sizeof(char));
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
