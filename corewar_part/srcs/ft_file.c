/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:04:27 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:04:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

static int			read_binary_file_bis(t_file *f, size_t *size, int *ret, \
												size_t *asize)
{
	size_t			offset;
	unsigned char	binary[2048];
	unsigned char	*tmp;

	offset = 2048 * 2;
	while ((*ret = read(f->fd, binary, 2048)) > 0)
	{
		if (*size + *ret > *asize)
		{
			tmp = f->binary;
			if (!(f->binary = ft_memalloc(sizeof(unsigned char) * \
											(*asize + offset))))
				return (-1);
			*asize += offset;
			if (*size)
				ft_memcpy(f->binary, tmp, (*size) * sizeof(unsigned char));
			if (tmp)
				free(tmp);
		}
		ft_memcpy(f->binary + (*size), binary, *ret);
		*size += *ret;
	}
	return (0);
}

int					read_binary_file(t_file *f)
{
	size_t			size;
	size_t			asize;
	int				ret;

	size = 0;
	asize = 0;
	ret = 0;
	if (f->binary)
		ft_memdel((void **)&f->binary);
	if (read_binary_file_bis(f, &size, &ret, &asize) == -1)
		return (-1);
	f->binary_size = size;
	return (0);
}

int					ft_realloc(void **m, int dsize, int size)
{
	void			*tmp;

	tmp = *m;
	if (!(*m = ft_memalloc(size)))
	{
		*m = tmp;
		return (-1);
	}
	if (tmp && dsize)
		ft_memcpy(*m, tmp, dsize);
	if (tmp)
		ft_memdel(&tmp);
	return (0);
}
