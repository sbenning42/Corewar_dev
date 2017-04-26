/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:06:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 13:36:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_dump_token(t_token *token)
{
	char	*pad;

	if (token->id == N_LABEL)
		pad = "";
	else if (token->id == T_ID)
		pad = "\t";
	else
		pad = "\t\t";
	ft_printf(token_fmt(),\
			token->position.line,\
			token->position.column,\
			token->key, pad, token->value);
}

void		asm_dump_token_lst(t_token *lst)
{
	while (lst)
	{
		asm_dump_token(lst);
		lst = lst->next;
	}
	if (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT))
		ft_printf("{gr}%s{eoc}\n\n", SEPLINE);
	else
		ft_printf("%s\n\n", SEPLINE);
}
