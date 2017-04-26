/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_dump_trans.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:59:09 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:59:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

extern char		*g_fmt[];

void			nfa_dump_trans_entry(t_list *l, int color)
{
	t_trans		*t;

	t = (t_trans *)l->content;
	ft_printf(g_fmt[color + NFA_DUMP_TE_I], (t->start > 32 ? t->start : '\0'), \
			(t->end < 127 ? t->end : '\0'), (long)t->state & (long)NFA_DM);
}

void			nfa_dump_trans(t_list *l, int color)
{
	if (l)
	{
		nfa_dump_trans_entry(l, color);
		nfa_dump_trans(l->next, color);
	}
}
