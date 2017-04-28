/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_handler_opcode_third_set.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:56:52 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/28 14:19:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_handler_opcode_ld(t_vm *vm, t_process *p, t_instruction *ins)
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
	value = access_arg_value(ins->args, vm, p, &err);
	if (err)
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	p->registre[index] = value;
	p->carry = (p->registre[index] ? 0 : 1);
	vm_pc_move(vm, p, ins, 1);
}

void	vm_handler_opcode_st(t_vm *vm, t_process *p, t_instruction *ins)
{
	int	value;
	int	err;

	value = access_arg_value(ins->args, vm, p, &err);
	if (vm_h_opc_tool(vm, p, ins, err) == 1)
		return ;
	if (ins->args[1].type == reg_arg)
		vm_handler_opcode_st_reg(vm, p, ins, value);
	else if (ins->args[1].type == ind_arg)
		vm_handler_opcode_st_ind(vm, p, ins, value);
}

void	vm_handler_opcode_ldi(t_vm *vm, t_process *p, t_instruction *ins)
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
	addr = access_arg_value(ins->args, vm, p, &err);
	if (vm_h_opc_tool(vm, p, ins, err) == 1)
		return ;
	offset = access_arg_value(ins->args + 1, vm, p, &err);
	if (vm_h_opc_tool(vm, p, ins, err) == 1)
		return ;
	pc = vm_pc(vm, p->pc + ((addr + offset) % vm->gconfig.idx_mod));
	p->registre[index] = read_int(vm, &pc);
	vm_pc_move(vm, p, ins, 1);
}

void	vm_handler_opcode_sti(t_vm *vm, t_process *p, t_instruction *ins)
{
	int	pc;
	int	index;
	int	addr;
	int	offset;
	int	err;

	index = ins->args[0].value;
	if (check_reg_index(vm, index))
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	p->value = p->registre[index];
	addr = access_arg_value(ins->args + 1, vm, p, &err);
	if (vm_h_opc_tool(vm, p, ins, err) == 1)
		return ;
	offset = access_arg_value(ins->args + 2, vm, p, &err);
	if (vm_h_opc_tool(vm, p, ins, err) == 1)
		return ;
	pc = vm_pc(vm, p->pc + ((addr + offset) % vm->gconfig.idx_mod));
	write_int(vm, &pc, p->value);
	write_col(vm, p, pc);
	vm_pc_move(vm, p, ins, 1);
}

void	vm_handler_opcode_fork(t_vm *vm, t_process *p, t_instruction *ins)
{
	int				offset;
	int				pc;

	offset = ins->args[0].value % vm->gconfig.idx_mod;
	pc = vm_pc(vm, p->pc + offset);
	vm_new_fprocess(vm, pc, p);
	vm_pc_move(vm, p, ins, 1);
}
