/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_eval_rec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:59:24 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:59:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

void			nfa_rec_clone_tokens(t_list **tokens, t_list *token)
{
	if (!token)
		return ;
	nfa_union_tokens(tokens, (*(t_state **)token->content)->eps_trans);
	nfa_rec_clone_tokens(tokens, token->next);
}

void			nfa_clone_tokens(t_list **tokens)
{
	nfa_rec_clone_tokens(tokens, *tokens);
}

void			nfa_rec_play_token(t_list **trans, t_list *closure, char c)
{
	t_trans		*cast;

	if (!closure)
		return ;
	cast = (t_trans *)closure->content;
	if (c >= cast->start && c <= cast->end)
		ft_lstadd_back(trans, ft_lstnew(&cast->state, sizeof(t_state *)));
	nfa_rec_play_token(trans, closure->next, c);
}

void			nfa_rec_play_tokens(t_list **trans, t_list *tokens, char c)
{
	t_list		*l;

	if (!tokens)
		return ;
	if ((l = nfa_play_token(tokens, c)))
		nfa_union_tokens(trans, l);
	ft_lstdel(&l, nfa_l_del);
	nfa_rec_play_tokens(trans, tokens->next, c);
}

t_list			*nfa_play_token(t_list *token, char c)
{
	t_list		*trans;

	trans = NULL;
	nfa_rec_play_token(&trans, (*(t_state **)token->content)->trans, c);
	return (trans);
}
