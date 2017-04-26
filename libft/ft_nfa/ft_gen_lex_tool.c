/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_lex_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:57:32 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:57:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lexer				**s_lex(void)
{
	static t_lexer	*lex;

	return (&lex);
}

void				ft_set_lex(t_lexer *lexer)
{
	*s_lex() = lexer;
}

void				ft_quit_lex(void)
{
	*s_scan() = NULL;
	*s_offset() = 0;
	*s_lex() = NULL;
}

void				ft_kill_lex(void)
{
	*s_scan() = NULL;
	*s_offset() = 0;
	lexer_del(s_lex());
}

t_lexem				*ft_lex_eval(void)
{
	t_lexem			*lexem;

	lexem = NULL;
	return (lexem);
}
