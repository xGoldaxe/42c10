/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:22:35 by pleveque          #+#    #+#             */
/*   Updated: 2021/07/16 11:22:48 by pleveque         ###   ########.fr       */
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
