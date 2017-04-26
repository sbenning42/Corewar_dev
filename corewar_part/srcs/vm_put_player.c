/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:07:33 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:07:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			vm_put_player(t_list *l)
{
	t_player	*player;

	player = (t_player *)l->content;
	ft_printf("* Player %d, weighing %zu bytes, \"%s\" (\"%s\") !\n",\
			ABS(player->id),\
			player->header.prog_size,\
			player->header.prog_name,\
			player->header.comment);
}

void			vm_put_players(t_vm *vm)
{
	if (vm->config.nb_player < 1)
		return ;
	ft_printf("Introducing contestants...\n");
	ft_lstiter(vm->player, vm_put_player);
}
