#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include <stdlib.h>
# define DECIMAL "0123456789"

void	ft_putstr(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_atoi_base(char *str, char *base);
int		read_file(char *name, int bytes_read, int with_header);
int		count_file(int fd);
void	print_error(char *arg, char *error);
void	error_msg(char *arg, char *msg);
void	print_filename(char *name, int with_newline);

#endif
