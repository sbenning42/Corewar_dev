/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_new_trans.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:59:49 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:59:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

t_list			*nfa_new_trans_entry(char start, char end, t_state *state)
{
	t_trans		trans;

	trans.start = start;
	trans.end = end;
	trans.state = state;
	return (ft_lstnew(&trans, sizeof(t_trans)));
}

t_list			*nfa_new_eps_trans_entry(t_state *state)
{
	return (ft_lstnew(&state, sizeof(t_state *)));
}
