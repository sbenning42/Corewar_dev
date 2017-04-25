/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:11:49 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/25 11:48:07 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_file	t_file;

struct					s_file
{
	char				*name;
	int					mode;
	int					fd;
	char				*line;
	int					li;
	unsigned char		*binary;
	size_t				binary_size;
};

t_file					*open_file(char *name, int mode);
void					close_file(t_file **f);
int						read_file(t_file *f);
int						read_binary_file(t_file *f);

#endif
