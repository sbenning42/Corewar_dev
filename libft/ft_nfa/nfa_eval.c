/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:59:18 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:59:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

int				nfa_search_state(t_list *tokens, t_state *state)
{
	return ((tokens\
				&& ((state == *(t_state **)tokens->content)\
				|| nfa_search_state(tokens->next, state))));
}

void			nfa_union_tokens(t_list **l1, t_list *l2)
{
	if (!l2)
		return ;
	if (!nfa_search_state(*l1, *(t_state **)l2->content))
		ft_lstadd_back(l1, ft_lstnew(l2->content, sizeof(t_state *)));
	nfa_union_tokens(l1, l2->next);
}

void			nfa_play_tokens(t_list **tokens, char c)
{
	t_list		*trans;

	trans = NULL;
	nfa_rec_play_tokens(&trans, *tokens, c);
	ft_lstdel(tokens, nfa_l_del);
	*tokens = trans;
}

void			nfa_eval_tokens(t_list **tokens, char *scan)
{
	if (!*scan || !*tokens)
		return ;
	nfa_play_tokens(tokens, *scan);
	nfa_clone_tokens(tokens);
	nfa_eval_tokens(tokens, scan + 1);
}

int				nfa_eval_tokens_step(t_nfa *nfa, t_list **tokens, \
						char *scan, int *max)
{
	if (!*scan)
		return (*max);
	nfa_play_tokens(tokens, *scan);
	nfa_clone_tokens(tokens);
	if (!*tokens)
		return (*max);
	if (nfa_is_terminal(nfa, *tokens))
		*max = nfa->size + 1;
	nfa->size += 1;
	return (nfa_eval_tokens_step(nfa, tokens, scan + 1, max));
}
