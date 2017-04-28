/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:04:49 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/28 14:04:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			access_reg_arg(t_insarg_i *arg, t_process *p, int *err)
{
	if (arg->value < 1 || arg->value > REG_NUMBER)
	{
		*err = 1;
		return (0);
	}
	return (p->registre[arg->value]);
}

int			access_dir_arg(t_insarg_i *arg)
{
	return (arg->value);
}

int			access_ind_arg(t_insarg_i *arg, t_vm *vm, t_process *p)
{
	int		pc;

	pc = vm_pc(vm, p->pc + (arg->value % vm->gconfig.idx_mod));
	return (read_int(vm, &pc));
}

int			access_arg_value(t_insarg_i *arg, t_vm *vm, t_process *p, int *err)
{
	*err = 0;
	if (arg->type == reg_arg)
		return (access_reg_arg(arg, p, err));
	else if (arg->type == dir_arg)
		return (access_dir_arg(arg));
	return (access_ind_arg(arg, vm, p));
}
