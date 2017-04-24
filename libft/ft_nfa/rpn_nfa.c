#include "ft_automaton.h"

/********************** A ENLEVER ET A METTRE DANS .H *************************/

typedef int				(*t_factor)(t_list **, t_re_entry *);
typedef struct s_disp	t_disp;
struct					s_disp
{
	char				c;
	t_factor			f;
};
/******************************************************************************/

t_disp					g_dispatch[] = {\
	{REX_RANGE_CODE, range_f},\
	{REX_POINT_CODE, rpn_joker_f},\
	{REX_KPOINT_CODE, kleen_point_f},\
	{REX_KPLUS_CODE, kleen_plus_f},\
	{REX_KSTAR_CODE, kleen_star_f},\
	{REX_CONJ_CODE, conjonction_f},\
	{REX_DISJ_CODE, disjonction_f},\
	{0, NULL}\
};

static t_nfa			*nfa_make_range(t_nfa *a1, t_nfa **a2)
{
	t_trans				*t1;
	t_trans				*t2;

	t1 = (t_trans *)a1->initial->trans->content;
	t2 = (t_trans *)(*a2)->initial->trans->content;
	t1->end = t2->start;
	nfa_deep_del(a2);
	return (a1);
}

static t_factor			dispatch(t_re_entry *rex)
{
	int					i;

	i = -1;
	while (g_dispatch[++i].f)
	{
		if (g_dispatch[i].c == rex->c)
			return (g_dispatch[i].f);
	}
	return (atom_f);
}

static t_nfa			*rec_rpn2nfa(t_list **stack, t_list *rpn)
{
	t_re_entry			*rex;

	if (!rpn)
		return (pop_stack_rpn(stack));
	rex = (t_re_entry *)rpn->content;
	if (dispatch(rex)(stack, rex))
		return (NULL);
	return (rec_rpn2nfa(stack, rpn->next));
}

t_nfa					*rpn2nfa(t_list *rpn)
{
	t_list				*stack;

	stack = NULL;
	return (rec_rpn2nfa(&stack, rpn));
}
