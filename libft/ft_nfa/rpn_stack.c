/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:04:03 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:04:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

t_nfa			*pop_stack_rpn(t_list **stack)
{
	t_list		*h;
	t_list		*t;
	t_nfa		*nfa;

	h = *stack;
	if (!h)
		return (NULL);
	t = h->next;
	*stack = t;
	h->next = NULL;
	nfa = *(t_nfa **)h->content;
	ft_lstdel(&h, nfa_l_del);
	return (nfa);
}

t_nfa			*eval_stack_rpn(t_list *stack)
{
	if (!stack)
		return (NULL);
	return (*(t_nfa **)stack->content);
}

int				push_stack_rpn(t_list **stack, t_nfa *nfa)
{
	t_list		*l;

	l = ft_lstnew(&nfa, sizeof(t_nfa *));
	if (!l)
		return (-1);
	ft_lstadd(stack, l);
	return (0);
}
