/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_rpn_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:56:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:56:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

static void		rpn_handler_val(t_list **rpn, t_list **stack, t_list *exp)
{
	push_rpn(rpn, *(t_re_entry *)exp->content);
	(void)stack;
}

static void		rpn_handler_bpclose(t_list **rpn, t_list **stack, t_list *exp)
{
	t_re_entry	re;

	if (!*stack)
		return ;
	while (42)
	{
		re = pop_stack(stack);
		if (re.c == REX_BOPEN_CODE || re.c == REX_POPEN_CODE)
			break ;
		push_rpn(rpn, re);
	}
	(void)exp;
}

static void		rpn_handler_other_op(t_list **rpn, t_list **stack, t_list *exp)
{
	t_re_entry	re;

	while (42)
	{
		if (!*stack)
			break ;
		re = eval_stack(*stack);
		if (re.c == REX_BOPEN_CODE || re.c == REX_POPEN_CODE)
			break ;
		if (is_prior(*(t_re_entry *)exp->content, re))
			break ;
		re = pop_stack(stack);
		push_rpn(rpn, re);
	}
	push_stack_exp(stack, *(t_re_entry *)exp->content);
}

static void		rpn_handler_op(t_list **rpn, t_list **stack, t_list *exp)
{
	t_re_entry	*re;

	re = (t_re_entry *)exp->content;
	if (re->c == REX_PCLOSE_CODE || re->c == REX_BCLOSE_CODE)
		rpn_handler_bpclose(rpn, stack, exp);
	else
		rpn_handler_other_op(rpn, stack, exp);
}

void			rpn_handler(t_list **rpn, t_list **stack, t_list *exp)
{
	t_re_entry	*re;

	re = (t_re_entry *)exp->content;
	if (re->type == REX_VAL_TYPE || re->c == REX_POINT_CODE)
		rpn_handler_val(rpn, stack, exp);
	else if (re->type == REX_OP_TYPE)
		rpn_handler_op(rpn, stack, exp);
}
