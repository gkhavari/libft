/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:59:33 by gkhavari          #+#    #+#             */
/*   Updated: 2025/04/22 13:59:36 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
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
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (dest == NULL)
		return (NULL);
	if (words == 0)
	{
		dest = NULL;
		return (dest);
	}
	write_split(dest, str, c);
	dest[words] = NULL;
	return (dest);
}
/*
#include <stdio.h>

typedef struct TestCase{
	char str[1024];
	char split;
}TestCase;

int main(void)
{
	TestCase test_cases[] = {
		{ .str = "          " , .split = ' ' },
		{ .str = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse" , .split = ' ' },
		{ .str = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   " , .split = ' '},
		{ .str = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi." , .split = 'i' },
		{ .str = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi." , .split = 'z'},
		{ .str = "" , .split = 'z' }
	};

	size_t num_of_tests = sizeof(test_cases) / sizeof(test_cases[0]);
	size_t i = 0;
	while (i < num_of_tests)
	{
		printf("Start of test %zu\n", i+1);
		char **arr = ft_split(test_cases[i].str, test_cases[i].split);
		size_t j = 0;
		printf("String: %s\n", test_cases[i].str);
		printf("Delimiter: %c\n", test_cases[i].split);
		size_t words = count_words(test_cases[i].str, test_cases[i].split);
		if (words == 0)
			printf("Split: %s\n", arr[0]);
		while (j < words)
		{
			printf("Split: %s\n", arr[j]);
			j++;
		}
		printf("\n");
		i++;
	}
}*/
