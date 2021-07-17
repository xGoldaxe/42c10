/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:23:17 by pleveque          #+#    #+#             */
/*   Updated: 2021/07/16 11:23:31 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_error(char *arg, char *error)
{
	ft_putstr("ft_tail: ");
	ft_putstr(arg);
	ft_putstr(": ");
	ft_putstr(error);
	ft_putstr("\n");
}

void	error_msg(char *arg, char *msg)
{
	ft_putstr("ft_tail: ");
	ft_putstr(msg);
	ft_putstr(arg);
	ft_putstr("\n");
}

void	print_filename(char *name, int with_newline)
{
	if (with_newline == 2)
		ft_putstr("\n");
	ft_putstr("==> ");
	ft_putstr(name);
	ft_putstr(" <==\n");
}
