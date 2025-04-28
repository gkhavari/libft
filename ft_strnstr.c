/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:02:07 by gkhavari          #+#    #+#             */
/*   Updated: 2025/04/22 14:02:10 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (haystack == NULL || needle == NULL)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (needle[j] && i + j < len && haystack[i + j] == needle[j])
				j++;
			if (needle [j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TestCase {
	char haystack[1024];
	char needle[1024];
	size_t size;
} TestCase;

void	test_strnstr(TestCase *test_case)
{
		if (ft_strnstr(test_case->haystack, test_case->needle, test_case->size) == strnstr(test_case->haystack, test_case->needle, test_case->size))
			printf("Test passed!\n");
		else
			printf("Test failed!\n");
}

int main(void)
{
	TestCase test_cases[] = {
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "lorem", .size = 15},
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "ipsum", .size = 15},
		{ .haystack = "lorem ipsum dolor sit lorem", .needle = "ipsum dolor", .size = 35},
		{ .haystack = "lorem ipsum dolor sit lorem", .needle = "ipsum", .size = 35},
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "", .size = 10},
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "ipsumm", .size = 30},
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "dol", .size = 30},
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "consectetur", .size = 30},
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "sit", .size = 10},
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "dolor", .size = 15},
		{ .haystack = "lorem ipsum dolor sit amet", .needle = "dolor", .size = 0}
	};
	
	size_t numb_of_tests = sizeof(test_cases) / sizeof(test_cases[0]);
	size_t i = 0;
	while (i < numb_of_tests)
	{
		test_strnstr(&test_cases[i]);
	}
}
