/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_explicit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:03:20 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:03:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

t_func			g_func[] = {\
	esc_f,\
	joker_f,\
	op_f,\
	val_f,\
	nop_f\
};

void			explicit_conjonction(t_list **stack, int *n)
{
	if (*n < 1)
		return ;
	push_stack(stack, REX_OP_TYPE, -'&');
	*n -= 1;
}

int				dispatch_regex(char c)
{
	if (c == '\\')
		return (0);
	else if (c == '.')
		return (1);
	else if (ft_strchr(REX_CHARS, c))
		return (2);
	else if (c != '&')
		return (3);
	return (4);
}

t_list			*regex2explicit(char *regex)
{
	t_list		*stack;
	int			n;

	stack = NULL;
	n = 0;
	while (*regex)
	{
		g_func[dispatch_regex(*regex)](&regex, &stack, &n);
		++regex;
	}
	return (stack);
}

void			regex_explicit_dump(t_list *stack)
{
	t_re_entry	*re;

	ft_printf("Explicit: ");
	while (stack)
	{
		re = (t_re_entry *)stack->content;
		if (re->type == REX_VAL_TYPE)
			ft_printf("%c", re->c);
		else if (re->type == REX_OP_TYPE)
			ft_printf("{gr}%c{eoc}", -re->c);
		stack = stack->next;
	}
	ft_printf("\n");
}
