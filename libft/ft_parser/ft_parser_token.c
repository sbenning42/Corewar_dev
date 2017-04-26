/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:00:52 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:00:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		del_token(t_token **lst)
{
	t_token	*drive;

	drive = *lst;
	while (drive)
	{
		*lst = drive->next;
		free(drive->value);
		free(drive);
		drive = *lst;
	}
}

void		pop_token(t_token **lst)
{
	t_token	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	free((*lst)->value);
	free(*lst);
	*lst = tmp;
}

t_token		*new_token(int id, char *value, size_t size, t_position position)
{
	t_token	*token;

	if (!(token = (t_token *)ft_memalloc(sizeof(t_token))))
		return (NULL);
	if (!(token->value = ft_strsub(value, 0, (size ? size : 1))))
	{
		free(token);
		return (NULL);
	}
	token->id = id;
	token->size = size;
	token->position = position;
	return (token);
}

void		add_token(t_token **lst, t_token *token)
{
	t_token	*drive;

	if (!*lst)
	{
		*lst = token;
		return ;
	}
	drive = *lst;
	while (drive->next)
		drive = drive->next;
	drive->next = token;
}
