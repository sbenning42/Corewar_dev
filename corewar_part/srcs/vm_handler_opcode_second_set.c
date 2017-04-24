/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_handler_opcode_second_set.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:55:51 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/24 09:13:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_handler_opcode_and(t_vm *vm, t_process *p, t_instruction *ins)
{
	int				op1;
	int				op2;
	int				index;
	int				err;

	index = ins->args[2].value;
	op1 = access_arg_value(ins->args, vm, p, &err);
	if (err)
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	op2 = access_arg_value(ins->args + 1, vm, p, &err);
	if (err)
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	p->registre[index] = op1 & op2;
	if (!p->registre[index])
		p->carry = 1;
	else
		p->carry = 0;
	vm_pc_move(vm, p, ins, 1);
}

void	vm_handler_opcode_or(t_vm *vm, t_process *p, t_instruction *ins)
{
	int				op1;
	int				op2;
	int				index;
	int				err;

	index = ins->args[2].value;
	if (check_reg_index(vm, index))
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	op1 = access_arg_value(ins->args, vm, p, &err);
	if (err)
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	op2 = access_arg_value(ins->args + 1, vm, p, &err);
	if (err)
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	p->registre[index] = op1 | op2;
	if (!p->registre[index])
		p->carry = 1;
	else
		p->carry = 0;
	vm_pc_move(vm, p, ins, 1);
}

void	vm_handler_opcode_xor(t_vm *vm, t_process *p, t_instruction *ins)
{
	int				op1;
	int				op2;
	int				index;
	int				err;

	index = ins->args[2].value;
	if (check_reg_index(vm, index))
	{
		vm_pc_move(vm, p, ins, 1);
		return ;
	}
	op1 = access_arg_value(ins->args, vm, p, &err);
	if (err)
	{
		vm_pc_move(vm, p, ins, 1);
		return ;
	}
	op2 = access_arg_value(ins->args + 1, vm, p, &err);
	if (err)
	{
		vm_pc_move(vm, p, ins, 1);
		return ;
	}
	p->registre[index] = ((op1 & ~op2) | (~op1 & op2));
	if (!p->registre[index])
		p->carry = 1;
	else
		p->carry = 0;
	vm_pc_move(vm, p, ins, 1);
}
