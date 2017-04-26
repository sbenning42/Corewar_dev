/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:04:59 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:05:00 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				vm_pc(t_vm *vm, int pc)
{
	return (((pc % vm->gconfig.mem_size) + \
				(pc < 0 ? vm->gconfig.mem_size : 0)));
}

unsigned char	bin_access(t_vm *vm, int pc)
{
	return (vm->memory[vm_pc(vm, pc)]);
}

unsigned char	*bin_access_w(t_vm *vm, int pc)
{
	return (vm->memory + vm_pc(vm, pc));
}

char			bin_char(t_vm *vm, int pc)
{
	return ((char)bin_access(vm, pc));
}
