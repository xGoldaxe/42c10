/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:20:18 by pleveque          #+#    #+#             */
/*   Updated: 2021/07/16 11:27:55 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	read_file(char *name, int bytes_read, int with_header)
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
	if (bytes_read > file_size)
		bytes_read = file_size;
	if (with_header)
		print_filename(name, with_header);
	write(1, &file[file_size - bytes_read], bytes_read);
	free(file);
	return (0);
}
