#include "ft_automaton.h"

t_re_entry		eval_stack(t_list *stack)
{
	t_re_entry	re;

	re.c = 0;
	re.type = 0;
	if (!stack)
		return (re);
	return (*(t_re_entry *)stack->content);
}

void			push_stack(t_list **stack, t_re_entry re)
{
	t_list		*l;

	if (!(l = ft_lstnew(&re, sizeof(t_re_entry))))
		return ;
	ft_lstadd(stack, l);
}

t_re_entry		pop_stack(t_list **stack)
{
	t_re_entry	re;
	t_list		*t;

	re.c = 0;
	re.type = 0;
	if (!*stack)
		return (re);
	t = (*stack)->next;
	(*stack)->next = NULL;
	re = *(t_re_entry *)(*stack)->content;
	ft_lstdel(stack, nfa_l_del);
	*stack = t;
	return (re);
}
