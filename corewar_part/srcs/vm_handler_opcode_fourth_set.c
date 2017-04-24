/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_handler_opcode_fourth_set.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:58:54 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/24 09:18:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_handler_opcode_lld(t_vm *vm, t_process *p, t_instruction *ins)
{
	vm_put_instruction(vm, p, ins);
	(void)vm;
	(void)p;
	(void)ins;
}

void	vm_handler_opcode_lldi(t_vm *vm, t_process *p, t_instruction *ins)
{
	vm_put_instruction(vm, p, ins);
	(void)vm;
	(void)p;
	(void)ins;
}

void	vm_handler_opcode_lfork(t_vm *vm, t_process *p, t_instruction *ins)
{
	int				offset;
	int				pc;

	offset = ins->args[0].value;
	pc = vm_pc(vm, p->pc + offset);
	vm_new_fprocess(vm, pc, p);
	vm_pc_move(vm, p, ins, 1);
}
