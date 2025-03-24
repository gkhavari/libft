/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:53:04 by ubuntu            #+#    #+#             */
/*   Updated: 2025/03/16 16:41:06 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			words++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (words);
}

static void	write_words(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	free_all(char **dest, int words)
{
	while (words > 0)
	{
		free(dest[words - 1]);
		words--;
	}
	free(dest);
}

static void	write_split(char **dest, const char *str, char c)
{
	int	i;
	int	word_len;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			word_len = 0;
			while (str[i + word_len] != c && str[i + word_len])
				word_len++;
			dest[words] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (dest[words] == NULL)
			{
				free_all(dest, words);
				return ;
			}
			write_words(dest[words++], &str[i], c);
			i = i + word_len;
		}
	}
}

char	**ft_split(char const *str, char c)
{
	char	**dest;
	int		words;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	words = count_words(str, c);
	if (words == 0)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (dest == NULL)
		return (NULL);
	write_split(dest, str, c);
	dest[words] = NULL;
	return (dest);
}
