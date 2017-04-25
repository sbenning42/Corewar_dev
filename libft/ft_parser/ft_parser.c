/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:08:05 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/25 15:08:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			skip_whitespace(char **scan)
{
	while (**scan == ' ' || **scan == '\t')
	{
		*scan += 1;
		inc_co_position(1);
	}
}

t_token			*ft_parse(t_parser *self, char **scan, void *data)
{
	t_token		*lst;
	char		*start_scan;

	if (!self)
		return (NULL);
	if (!self->match)
		return (NULL);
	start_scan = *scan;
	if (self->whitespace)
		skip_whitespace(scan);
	if ((lst = self->match(self, scan, data)))
	{
		if (self->callback && self->callback(self, &lst))
			exit(1);
		return (lst);
	}
	single_position()->column -= (*scan - start_scan);
	*scan = start_scan;
	return (NULL);
}
