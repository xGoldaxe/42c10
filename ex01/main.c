/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:02:23 by pleveque          #+#    #+#             */
/*   Updated: 2021/07/15 12:39:27 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>
#include "ft.h"

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

int	write_file(char *name)
{
	int		fd;
	int		read_b;
	char	buffer[1023];

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ft_cat: ");
		ft_putstr(name);
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return (-1);
	}
	while ((read_b = read(fd, buffer, 1023)))
	{
		write(1, buffer, read_b);
	}	
	close(fd);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	return (*s1 - *s2);
}

void	cat_in(void)
{	
	char	test[1023 + 1];
	int		result;
	int		fd;

	while ((result = read(fd, test, 1023)))
	{
		test[result] = '\0';
		ft_putstr(test);
	}
	return ;
}

int	main(int argc, char **argv)
{
	int		i;
	char	test[1023];

	i = 1;
	if (argc == 1)
		cat_in();
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
			cat_in();
		else
			write_file(argv[i]);
		i++;
	}
	return (0);
}
