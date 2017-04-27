/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_write_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:07:20 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/27 13:09:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_col(t_vm *vm, t_process *p, int pc)
{
	vm->color[vm_pc(vm, pc)] = p->color;
	vm->color[vm_pc(vm, pc + 1)] = p->color;
	vm->color[vm_pc(vm, pc + 2)] = p->color;
	vm->color[vm_pc(vm, pc + 3)] = p->color;
}
