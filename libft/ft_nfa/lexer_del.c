/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:58:14 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:58:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void			lexer_del_i(void *c, size_t s)
{
	t_analyzer	*a;

	a = (t_analyzer *)c;
	nfa_deep_del(&a->nfa);
	free(c);
	(void)s;
}

void			lexer_del(t_lexer **lexer)
{
	if (!*lexer)
		return ;
	ft_lstdel(&(*lexer)->analyzer, lexer_del_i);
	ft_memdel((void **)&(*lexer)->regex);
	ft_memdel((void **)&(*lexer)->key);
}
