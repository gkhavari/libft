/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:56:52 by gkhavari          #+#    #+#             */
/*   Updated: 2025/04/22 13:56:54 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	if (s == NULL || n == 0)
		return (NULL);
	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}


#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct TestCase {
	char str[1024];
	int to_find;
	int size;
} TestCase;

void	test_strchr(TestCase *test_case)
{
		if (ft_strchr(test_case->str, test_case->to_find) == strchr(test_case->str, test_case->to_find))
			printf("Test passed!\n");
		else
			printf("Test failed!\n");
}

int main(void)
{
	TestCase test_cases[] = {
		{ .str = "Hello, World!", .to_find = 'H' , .size = 4},
		{ .str = "Hello, World!", .to_find = 'l' , size = 5},
		{ .str = "Hello, World!", .to_find = '!' , size = 3},
		{ .str = "Hello, World!", .to_find = 'z' , size = 13}},
		{ .str = "", .to_find = 'a' },
		{ .str = "42", .to_find = '\0' },
		{ .str = "a", .to_find = 'a' },
		{ .str = "a", .to_find = 'A' },
		{ .str = "aaaaaaaaaa", .to_find = 'A' },
		{ .str = "Hello\nworld", .to_find = '\n' }
	};
	
	int numb_of_cases = sizeof(test_cases) / sizeof(test_cases[0]);
	int i = 0;
	while (i < numb_of_cases)
	{
		test_strchr(&test_cases[i]);
		i++;
	}
}
