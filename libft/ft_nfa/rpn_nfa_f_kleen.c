/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_nfa_f_kleen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:03:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:03:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

int				kleen_point_f(t_list **stack, t_re_entry *rex)
{
	return (push_unary(stack, nfa_kleen_point));
	(void)rex;
}

int				kleen_plus_f(t_list **stack, t_re_entry *rex)
{
	return (push_unary(stack, nfa_kleen_plus));
	(void)rex;
}

int				kleen_star_f(t_list **stack, t_re_entry *rex)
{
	return (push_unary(stack, nfa_kleen_star));
	(void)rex;
}
