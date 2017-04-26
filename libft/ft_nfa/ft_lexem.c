/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:57:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:57:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lexem			*lexem_new(int id, char *key, char *scan, int size)
{
	t_lexem		*lexem;

	if (!(lexem = (t_lexem *)ft_memalloc(sizeof(t_lexem))))
		return (NULL);
	lexem->id = id;
	lexem->key = key;
	lexem->size = size;
	lexem->value = ft_strsub(scan, 0, size);
	if (!lexem->value)
	{
		free(lexem);
		return (NULL);
	}
	return (lexem);
}

void			lexem_dump(t_lexem *lexem)
{
	char		key[2048];
	char		fmt[2048];

	ft_sprintf(fmt, "%s", lexem->key);
	ft_sprintf(key, fmt);
	ft_printf("Lexem: %25s : [%s]\n", key, lexem->value);
}

void			lexem_del(t_lexem **lexem)
{
	if (!*lexem)
		return ;
	if ((*lexem)->value)
		ft_memdel((void **)&(*lexem)->value);
	ft_memdel((void **)lexem);
}
