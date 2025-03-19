/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:52:45 by ubuntu            #+#    #+#             */
/*   Updated: 2025/03/16 16:24:24 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*edge_cases(int n)
{
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, "0");
		return (str);
	}
	if (n == -2147483648)
	{
		str = (char *)malloc(12 * sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	return (NULL);
}

static size_t	calc_num_len(int n)
{
	size_t	num_len;

	num_len = 0;
	if (n <= 0)
		num_len++;
	while (n != 0)
	{
		n = n / 10;
		num_len++;
	}
	return (num_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	num_len;

	if (n == 0 || n == -2147483648)
		return (edge_cases(n));
	num_len = calc_num_len(n);
	str = (char *)malloc((num_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[num_len] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[num_len - 1] = n % 10 + '0';
		n = n / 10;
		num_len--;
	}
	return (str);
}
