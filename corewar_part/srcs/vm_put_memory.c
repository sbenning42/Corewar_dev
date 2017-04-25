/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_put_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 08:45:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/25 13:27:44 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				vm_put_pc_move(t_vm *vm, int pc_start, int offset, \
											t_instruction *ins)
{
	int				i;

	if (!ISBIT(vm->config.verb, VM_PC_VERB))
		return ;
	ft_printf("ADV %d (0x%04x -> 0x%04x) ", \
						offset, pc_start, vm_pc(vm, pc_start + offset));
	i = -1;
	while (++i < ins->size)
	{
		ft_printf("%02x ", bin_access(vm, pc_start + i));
	}
	ft_printf("\n");
}

void				vm_put_byte(t_vm *vm, size_t i)
{
	unsigned char	o;

	o = vm->memory[i];
	if (vm->col && vm->color[i])
		ft_printf("%s", vm->color[i]);
	if (!o)
		ft_printf("%02x ", o);
	else
		ft_printf("%02x ", o);
	if (vm->col && vm->color[i])
		ft_printf("{eoc}");
}

void				vm_put_64(t_vm *vm, size_t start)
{
	size_t			i;

	i = 0;
	while (i < 64)
	{
		vm_put_byte(vm, start + i);
		++i;
	}
	ft_printf("\n");
}

void				vm_put_memory(t_vm *vm)
{
	size_t			stop;
	size_t			i;

	i = 0;
	stop = vm->gconfig.mem_size / 64;
	while (i < stop)
	{
		ft_printf("0x%04x : ", i * 64);
		vm_put_64(vm, i * 64);
		++i;
	}
}
