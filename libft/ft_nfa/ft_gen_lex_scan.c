/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_lex_scan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:57:21 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:57:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char	**s_scan(void)
{
	static char		*scan;

	return (&scan);
}

int		*s_offset(void)
{
	static int		offset;

	return (&offset);
}

void	ft_lex_start_scan(char *scan)
{
	*s_scan() = scan;
	*s_offset() = 0;
}
