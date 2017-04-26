/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access_arg_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 13:48:24 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 13:50:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			access_ind_arg_woidx(t_insarg_i *arg, t_vm *vm, t_process *p)
{
	int		pc;

	pc = vm_pc(vm, p->pc + arg->value);
	return (read_int(vm, &pc));
}

int			access_arg_value_woidx(t_insarg_i *arg, t_vm *vm, t_process *p,\
		int *err)
{
	*err = 0;
	if (arg->type == reg_arg)
		return (access_reg_arg(arg, p, err));
	else if (arg->type == dir_arg)
		return (access_dir_arg(arg));
	return (access_ind_arg_woidx(arg, vm, p));
}
