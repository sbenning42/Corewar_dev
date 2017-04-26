/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_handler_opcode_fourth_set.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:58:54 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 13:54:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_handler_opcode_lld(t_vm *vm, t_process *p, t_instruction *ins)
{
	int	value;
	int	index;
	int	err;

	index = ins->args[1].value;
	if (check_reg_index(vm, index))
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	value = access_arg_value_woidx(ins->args, vm, p, &err);
	if (err)
	{
		vm_put_pc_move(vm, p->pc, ins->size, ins);
		p->pc = vm_pc(vm, p->pc + ins->size);
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	p->registre[index] = value;
	p->carry = (p->registre[index] ? 0 : 1);
	vm_pc_move(vm, p, ins, 1);
}

void	vm_handler_opcode_lldi(t_vm *vm, t_process *p, t_instruction *ins)
{
	int	pc;
	int	index;
	int	addr;
	int	offset;
	int	err;

	index = ins->args[2].value;
	if (check_reg_index(vm, index))
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	addr = access_arg_value_woidx(ins->args, vm, p, &err);
	if (vm_h_opc_tool(vm, p, ins, err) == 1)
		return ;
	offset = access_arg_value_woidx(ins->args + 1, vm, p, &err);
	if (vm_h_opc_tool(vm, p, ins, err) == 1)
		return ;
	pc = vm_pc(vm, p->pc + (addr + offset));
	p->registre[index] = read_int(vm, &pc);
	p->carry = (p->registre[index] ? 0 : 1);
	vm_pc_move(vm, p, ins, 1);
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
