/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_load_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:30:39 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/28 14:37:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static long int		get_id(void)
{
	static long int	i;

	return (++i);
}

void				vm_new_process(t_vm *vm, int pc, long int id, char *color)
{
	t_list			*l;
	t_process		process;

	ft_bzero(&process, sizeof(t_process));
	process.id = get_id();
	process.player_id = id;
	process.color = color;
	process.pc = pc;
	process.registre[1] = id;
	vm_set_timer(vm, &process);
	if (!(l = ft_lstnew(&process, sizeof(t_process))))
		vm_fatal(VM_EMALLOC);
	ft_lstadd(&vm->process, l);
}

void				vm_new_fprocess(t_vm *vm, int pc, t_process *p)
{
	t_list			*l;
	t_process		process;

	ft_bzero(&process, sizeof(t_process));
	process.id = get_id();
	process.player_id = p->player_id;
	process.color = p->color;
	process.pc = pc;
	process.carry = p->carry;
	process.live = p->live;
	process.registre[0] = 0;
	ft_memcpy(process.registre, p->registre, sizeof(int) * (REG_NUMBER + 1));
	vm_set_timer(vm, &process);
	if (!(l = ft_lstnew(&process, sizeof(t_process))))
		vm_fatal(VM_EMALLOC);
	ft_lstadd(&vm->process, l);
}

void				vm_load_process(t_vm *vm)
{
	int				start;
	size_t			offset;
	t_list			*l;
	t_player		*player;
	int				i;

	start = 0;
	offset = vm->gconfig.mem_size / vm->config.nb_player;
	l = vm->player;
	while (l)
	{
		player = (t_player *)l->content;
		player->pc = start;
		ft_memcpy(vm->memory + start, player->binary, player->binary_size);
		i = -1;
		while (++i < (int)player->binary_size)
			vm->color[start + i] = player->color;
		vm_new_process(vm, start, player->id, player->color);
		start += offset;
		l = l->next;
	}
}
