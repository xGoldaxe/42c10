int	ft_base_to_int(char value, char *base)
{
	int	i;

	i = 0;
	while (value != base[i])
	{
		i++;
	}
	return (i);
}

int	str_to_int(char *str, int size, char *base)
{
	int	result;
	int	i;
	int	base_s;
	int	pow_result;
	int	pow_i;

	result = 0;
	i = 0;
	while (i < size)
	{
		base_s = 0;
		while (base[base_s] != '\0')
			base_s++;
		pow_i = 0;
		pow_result = 1;
		while (pow_i < size - 1 - i)
		{
			pow_result = pow_result * base_s;
			pow_i++;
		}
		result += ft_base_to_int(str[i], base) * pow_result;
		i++;
	}
	return (result);
}

int	str_contain_char(char value_to_test, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == value_to_test)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		start_number;
	int		result;
	int		number_of_minus;

	number_of_minus = 0;
	i = 0;
	while (str[i] == '-')
	{
		number_of_minus++;
		i++;
	}
	if (number_of_minus > 1)
		return (-1);
	start_number = i;
	while (str[i] != '\0')
	{
		if (!str_contain_char(str[i], base))
			return (-1);
		i++;
	}
	result = str_to_int(&str[start_number], i - start_number, base);
	return (result);
}
