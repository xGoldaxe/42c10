/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:11:36 by pleveque          #+#    #+#             */
/*   Updated: 2021/07/16 11:24:35 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	verify_decimal_option(char *flag)
{
	int	bytes_read;

	bytes_read = ft_atoi_base(flag, DECIMAL);
	if (bytes_read == -1)
	{
		error_msg(flag, "illegal offset -- ");
		return (-1);
	}
	return (bytes_read);
}

int	verify_arg_c(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2 || (ft_strncmp(argv[i], "-c", 2) != 0))
		return (-1);
	if (argc < 3)
	{
		error_msg("c", "option requires an argument -- ");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		bytes_read;

	i = 1;
	if (verify_arg_c(argc, argv) != 0)
		return (1);
	bytes_read = verify_decimal_option(argv[++i]);
	if (bytes_read == -1)
		return (1);
	i++;
	if (argc < 4)
		read_file(0, bytes_read, 0);
	while (i < argc)
	{
		if (i > 3)
			read_file(argv[i], bytes_read, 2);
		else if (argc == 4)
			read_file(argv[i], bytes_read, 0);
		else
			read_file(argv[i], bytes_read, 1);
		i++;
	}
}
