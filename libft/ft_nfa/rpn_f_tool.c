/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_f_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:03:28 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:03:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

int				range_f(t_list **stack, t_re_entry *rex)
{
	t_nfa		*left;
	t_nfa		*right;
	t_nfa		*nfa;

	if (!(eval_stack_rpn(*stack) && eval_stack_rpn((*stack)->next)))
		return (1);
	right = pop_stack_rpn(stack);
	left = pop_stack_rpn(stack);
	nfa = nfa_make_range(left, &right);
	push_stack_rpn(stack, nfa);
	return (0);
	(void)rex;
}

int				atom_f(t_list **stack, t_re_entry *rex)
{
	t_nfa		*nfa;

	if (!(nfa = nfa_atom(rex->c)))
		return (-1);
	return (push_stack_rpn(stack, nfa));
}

int				rpn_joker_f(t_list **stack, t_re_entry *rex)
{
	t_nfa		*nfa;

	if (!(nfa = nfa_joker()))
		return (-1);
	return (push_stack_rpn(stack, nfa));
	(void)rex;
}

int				conjonction_f(t_list **stack, t_re_entry *rex)
{
	return (push_binary(stack, nfa_conjonction));
	(void)rex;
}

int				disjonction_f(t_list **stack, t_re_entry *rex)
{
	return (push_binary(stack, nfa_disjonction));
	(void)rex;
}
