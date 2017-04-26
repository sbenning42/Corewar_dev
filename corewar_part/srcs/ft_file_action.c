/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:01:46 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:01:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

t_file			*open_file(char *name, int mode)
{
	t_file		*f;

	f = (t_file *)ft_memalloc(sizeof(t_file));
	if (!f)
		return (NULL);
	f->name = ft_strdup(name);
	if (!f->name)
	{
		free(f);
		return (NULL);
	}
	f->mode = mode;
	f->fd = open(name, mode, 0755);
	if (f->fd < 0)
	{
		free(f->name);
		free(f);
		return (NULL);
	}
	return (f);
}

void			close_file(t_file **f)
{
	if ((*f)->fd >= 0)
		close((*f)->fd);
	free((*f)->name);
	if ((*f)->line)
		free((*f)->line);
	if ((*f)->binary)
		free((*f)->binary);
	free(*f);
	*f = NULL;
}

int				read_file(t_file *f)
{
	int			status;

	if (f->line)
		ft_memdel((void **)&f->line);
	status = get_next_line(f->fd, &f->line);
	if (status > 0)
		f->li += 1;
	return (status);
}
