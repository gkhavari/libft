/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:02:42 by gkhavari          #+#    #+#             */
/*   Updated: 2025/04/22 14:02:44 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*edge_cases(const char *s1, const char *set)
{
	if (s1 == NULL)
		return (NULL);
	if (set == NULL || set[0] == '\0')
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL || set[0] == '\0')
		return (edge_cases(s1, set));
	start = 0;
	while (is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (is_in_set(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	trimmed = (char *)malloc((end - start + 2) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		trimmed[i++] = s1[start++];
	trimmed[end + 1] = '\0';
	return (trimmed);
}
