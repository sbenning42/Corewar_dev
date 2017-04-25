#include "ft_automaton.h"

int				push_unary(t_list **stack, t_nfa *(*f)(t_nfa *))
{
	t_nfa		*origin;
	t_nfa		*nfa;

	if (!eval_stack_rpn(*stack))
		return (1);
	origin = pop_stack_rpn(stack);
	if (!(nfa = f(origin)))
		return (-1);
	return (push_stack_rpn(stack, nfa));
}

int				push_binary(t_list **stack, t_nfa *(*f)(t_nfa *, t_nfa *))
{
	t_nfa		*left;
	t_nfa		*right;
	t_nfa		*nfa;

	if (!(eval_stack_rpn(*stack) && eval_stack_rpn((*stack)->next)))
		return (1);
	right = pop_stack_rpn(stack);
	left = pop_stack_rpn(stack);
	if (!(nfa = f(left, right)))
		return (-1);
	return (push_stack_rpn(stack, nfa));
}
