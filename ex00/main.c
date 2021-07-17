/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:31:20 by pleveque          #+#    #+#             */
/*   Updated: 2021/07/14 14:42:53 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		read_b;
	char	buffer[1023];

	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	read_b = read(fd, buffer, 1023);
	close(fd);
	write(1, buffer, read_b);
}
