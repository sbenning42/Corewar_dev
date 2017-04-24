/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_handler_opcode_st.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 11:46:26 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/24 11:47:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_handler_opcode_st_reg(t_vm *vm, t_process *p, t_instruction *ins,\
		int value)
{
	int	index;

	index = ins->args[1].value;
	if (check_reg_index(vm, index))
	{
		vm_pc_move(vm, p, ins, 0);
		return ;
	}
	p->registre[index] = value;
	vm_pc_move(vm, p, ins, 1);
}

void	vm_handler_opcode_st_ind(t_vm *vm, t_process *p, t_instruction *ins,\
		int value)
{
	int	pc;
	int	offset;

	offset = ins->args[1].value % vm->gconfig.idx_mod;
	pc = vm_pc(vm, p->pc + offset);
	write_int(vm, &pc, value);
	vm_pc_move(vm, p, ins, 1);
}


