/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:14:03 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 14:39:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_disp_fct			dispatch_access(unsigned char ocp)
{
	ocp &= 0xc0;
	if (ocp == 0x40)
		return (fill_reg);
	else if (ocp == 0x80)
		return (fill_dir);
	else if (ocp == 0xc0)
		return (fill_ind);
	return (fill_null);
}

int					get_op_index(unsigned int opcode)
{
	int				i;

	i = -1;
	while (g_op[++i].id)
	{
		if (opcode == g_op[i].opcode)
			return (i);
	}
	return (-1);
}

unsigned char		make_ocp(t_op op)
{
	unsigned int	i;
	unsigned char	ocp;

	i = 0;
	ocp = 0;
	while (i < op.nb_arg)
	{
		if (op.args_type[i] != T_IND)
			ocp |= (op.args_type[i] << 0x6) >> (0x2 * i);
		else
			ocp |= 0x3;
		++i;
	}
	return (ocp);
}

void				vm_read_instruction(t_vm *vm, int pc, \
								t_instruction *ins, unsigned char opcode)
{
	int				op_index;

	ins->pc = pc;
	ins->op = opcode;
	pc = vm_pc(vm, pc + 1);
	ins->size = 1;
	op_index = get_op_index(opcode);
	if (op_index < 0)
		return ;
	if (g_op[op_index].ocp)
	{
		ins->ocp = bin_access(vm, pc);
		pc = vm_pc(vm, pc + 1);
		ins->size += 1;
	}
	else
		ins->ocp = make_ocp(g_op[op_index]);
	fill_args(ins, vm, pc, g_op[op_index].label_size);
}

int					check_reg_index(t_vm *vm, int i)
{
	if (i < 1 || i > vm->gconfig.reg_number)
		return (-1);
	return (0);
}
