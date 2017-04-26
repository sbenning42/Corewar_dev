/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_lex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:57:15 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:57:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lexer				*ft_gen_lex(char **regex, char **key, int size)
{
	t_lexer			*lexer;

	lexer = lexer_new(regex, key, size);
	if (!lexer)
		return (NULL);
	if (lexer_computize(lexer))
		return (NULL);
	return (lexer);
}

static int			ft_lex_bis(t_list *l, t_analyzer **max_analyze)
{
	t_analyzer		*analyze;
	int				size;
	int				max;

	max = 0;
	while (l)
	{
		analyze = (t_analyzer *)l->content;
		size = nfa_match(analyze->nfa, *s_scan());
		if (size > max)
		{
			max = size;
			*max_analyze = analyze;
		}
		l = l->next;
	}
	return (max);
}

t_lexem				*ft_lex(void)
{
	t_list			*l;
	t_lexem			*lexem;
	int				max;
	t_analyzer		*max_analyze;

	if (!*s_scan() || !*s_lex())
		return (NULL);
	while (**s_scan() == ' ' || **s_scan() == '\t')
	{
		*s_scan() += 1;
		*s_offset() += 1;
	}
	l = (*s_lex())->analyzer;
	max = ft_lex_bis(l, &max_analyze);
	if (!max && **s_scan())
		return (lexem_new(-1, "{red}LEXERROR{eoc}", *s_scan(), \
					(int)ft_strlen(*s_scan())));
	else if (!**s_scan())
		return (NULL);
	if (!(lexem = lexem_new(max_analyze->id, max_analyze->key, *s_scan(), max)))
		return (NULL);
	*s_scan() += max;
	*s_offset() += max;
	return (lexem);
}
