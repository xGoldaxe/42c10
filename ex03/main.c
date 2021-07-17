/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:30:09 by pleveque          #+#    #+#             */
/*   Updated: 2021/07/16 13:16:37 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_file(int fd)
{
	int				read_b;
	char			buffer[1023];
	unsigned int	file_size;

	file_size = 0;
	while ((read_b = read(fd, buffer, 1023)))
	{
		file_size += read_b;
	}
	return (file_size);
}

int	stock_file(char *name, char *dest)
{
	int		file_size;
	int		fd;
	char	*file;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		print_error(name, strerror(errno));
		return (-1);
	}
	file_size = count_file(fd);
	close(fd);
	file = malloc(sizeof(char) * (file_size));
	if (file == NULL)
		return (0);
	fd = open(name, O_RDONLY);
	read(fd, file, file_size);
	ft_strdup(file, dest);
	return (file_size);
}

void	print_file_hex(int	file_size, char *file)
{
	int	line;
	int i;

	i = 0;
	while (i < 16)
	{
		ft_putnbr_base(file[i], "0123456789abcdef");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*actual_file;
	int		file_size;

	i = 1;
	file_size = stock_file(argv[i], actual_file);
	printf("%s\n", actual_file);
//	print_file_hex(file_size, actual_file);
//	free(actual_file);
}
