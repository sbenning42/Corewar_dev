/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:03:01 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:03:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

void			push_stack(t_list **stack, int type, char c)
{
	t_list		*l;
	t_re_entry	re;

	re.type = type;
	re.c = c;
	if (!(l = ft_lstnew(&re, sizeof(t_re_entry))))
		return ;
	ft_lstadd_back(stack, l);
}

void			push_val(t_list **stack, int *n, char c)
{
	explicit_conjonction(stack, n);
	push_stack(stack, REX_VAL_TYPE, c);
	*n += 1;
}

void			push_op(t_list **stack, int *n, char c)
{
	explicit_conjonction(stack, n);
	push_stack(stack, REX_OP_TYPE, c);
	*n += 1;
}
