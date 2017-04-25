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
