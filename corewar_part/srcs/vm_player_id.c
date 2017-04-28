/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_player_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:45:53 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/28 15:15:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char			*get_color(void)
{
	static char	*color[] = {\
		"\033[38;2;0;255;0m",\
		"\033[38;2;255;0;0m",\
		"\033[38;2;0;0;255m",\
		"\033[38;2;255;255;0m"\
	};
	static int	i = -1;

	return (color[(++i % TABSIZE(color))]);
}

int				is_available_id(t_vm *vm, long int id)
{
	t_list		*l;

	l = vm->player;
	while (l)
	{
		if (((t_player *)l->content)->id == id)
			return (0);
		l = l->next;
	}
	return (1);
}

long int		get_player_id(t_vm *vm, long int id)
{
	while (!is_available_id(vm, id))
		--id;
	return (id);
}
