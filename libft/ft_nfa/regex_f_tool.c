/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_f_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:03:08 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:03:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

void	esc_f(char **regex, t_list **stack, int *n)
{
	explicit_conjonction(stack, n);
	*regex += 1;
	if (!**regex)
		return ;
	push_stack(stack, REX_VAL_TYPE, **regex);
	*n += 1;
}

void	joker_f(char **regex, t_list **stack, int *n)
{
	push_op(stack, n, -'.');
	(void)regex;
}

void	op_f(char **regex, t_list **stack, int *n)
{
	if (**regex == '(' || **regex == '[')
		explicit_conjonction(stack, n);
	else if (**regex == '|' || **regex == '-')
		*n = 0;
	push_stack(stack, REX_OP_TYPE, -(**regex));
}

void	val_f(char **regex, t_list **stack, int *n)
{
	push_val(stack, n, **regex);
}

void	nop_f(char **regex, t_list **stack, int *n)
{
	(void)regex;
	(void)stack;
	(void)n;
}
