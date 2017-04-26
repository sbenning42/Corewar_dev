/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explicit_rpn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:56:15 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:56:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

void			push_rpn(t_list **rpn, t_re_entry re)
{
	t_list		*l;

	if (!(l = ft_lstnew(&re, sizeof(t_re_entry))))
		return ;
	ft_lstadd_back(rpn, l);
}

void			rec_explicit2rpn(t_list **rpn, t_list **stack, t_list *exp)
{
	if (!exp)
		return ;
	rpn_handler(rpn, stack, exp);
	rec_explicit2rpn(rpn, stack, exp->next);
}

t_list			*explicit2rpn(t_list *exp)
{
	t_list		*rpn;
	t_list		*stack;

	rpn = NULL;
	stack = NULL;
	rec_explicit2rpn(&rpn, &stack, exp);
	while (stack)
		push_rpn(&rpn, pop_stack(&stack));
	return (rpn);
}

void			rpn_dump(t_list *rpn)
{
	t_re_entry	*re;

	ft_printf("Rpn: ");
	while (rpn)
	{
		re = (t_re_entry *)rpn->content;
		if (re->type == REX_VAL_TYPE)
			ft_printf("%c", re->c);
		else if (re->type == REX_OP_TYPE)
			ft_printf("{gr}%c{eoc}", -re->c);
		rpn = rpn->next;
	}
	ft_printf("\n");
}
