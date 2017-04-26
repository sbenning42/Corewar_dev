/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_handler_opcode_tool.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:06:16 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:07:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_h_opc_tool(t_vm *vm, t_process *p, \
									t_instruction *ins, int err)
{
	if (err)
	{
		vm_pc_move(vm, p, ins, 0);
		return (1);
	}
	return (0);
}
