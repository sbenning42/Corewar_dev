/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_rpn_prior.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:56:29 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:56:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

t_re_entry		g_prior[] = {\
	{0, -'|'},\
	{1, -'&'},\
	{2, -'-'},\
	{3, -'*'},\
	{3, -'+'},\
	{3, -'?'},\
	{4, -'('},\
	{4, -'['},\
	{-1, 0}\
};

static int		get_prior(t_re_entry r)
{
	int			i;

	i = -1;
	while (g_prior[++i].c)
	{
		if (r.c == g_prior[i].c)
			return (g_prior[i].type);
	}
	return (-1);
}

int				is_prior(t_re_entry r1, t_re_entry r2)
{
	return (get_prior(r1) > get_prior(r2));
}
