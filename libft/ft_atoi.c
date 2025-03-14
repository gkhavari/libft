int	ft_atoi(char *str)
{
	size_t	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str == NULL || str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number > (2147483647 - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (sign * number);
}
