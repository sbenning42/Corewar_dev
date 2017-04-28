/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_new_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:23:00 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/28 14:58:50 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		vm_load_player_file(t_player *p)
{
	size_t		hsize;
	size_t		size;

	hsize = sizeof(t_header_t);
	size = hsize;
	ft_memcpy(&p->header, p->file->binary, size);
	p->header.magic = INT_LITTLE2BIG(p->header.magic);
	p->header.prog_size = INT_LITTLE2BIG(p->header.prog_size);
	size = p->file->binary_size - hsize;
	ft_memcpy(p->binary, p->file->binary + hsize, size);
	p->binary_size = size;
}

static int		vm_check_champ_size(t_vm *vm, t_player *player)
{
	size_t		hsize;

	hsize = sizeof(t_header_t);
	if ((player->file->binary_size < hsize)\
			|| (player->file->binary_size > hsize + vm->gconfig.champ_max_size))
	{
		vm_error_notcorewar(player->file->name);
		return (1);
	}
	return (0);
}

static void		fnorme(t_player *player, long int id, char *color)
{
	player->id = id;
	player->color = color;
}

void			vm_new_player(t_vm *vm, char *name, long int id)
{
	t_player	player;
	t_list		*l;

	ft_bzero(&player, sizeof(t_player));
	if (vm->config.nb_player >= vm->gconfig.max_player)
		vm_fatal(VM_ETOOMUCH);
	if (!(player.file = open_file(name, O_RDONLY)))
	{
		vm_error_notaccess(name);
		return ;
	}
	if (read_binary_file(player.file))
		vm_fatal(VM_EMALLOC);
	if (vm_check_champ_size(vm, &player))
	{
		close_file(&player.file);
		return ;
	}
	vm_load_player_file(&player);
	close_file(&player.file);
	fnorme(&player, get_player_id(vm, id), get_color());
	if (!(l = ft_lstnew(&player, sizeof(t_player))))
		vm_fatal(VM_EMALLOC);
	ft_lstadd_back(&vm->player, l);
	vm->config.nb_player += 1;
}
