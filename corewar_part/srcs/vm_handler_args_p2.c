/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_handler_args_p2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:41:29 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/24 10:42:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_handler_arg_affiche(t_vm *vm, char *arg)
{
	vm->config.aff = 1;
	(void)arg;
}

void		vm_handler_arg_dump(t_vm *vm, char *arg)
{
	t_lexem	*l;

	if (!((l = get_arg()) && l->id == VM_NUMBER_ARG))
		vm_fatal(VM_EUSAGE);
	vm->config.dump = ft_atoi(l->value);
	lexem_del(&l);
	(void)arg;
}

void		vm_handler_arg_step(t_vm *vm, char *arg)
{
	t_lexem	*l;

	if (!((l = get_arg()) && l->id == VM_NUMBER_ARG))
		vm_fatal(VM_EUSAGE);
	vm->config.step = ft_atoi(l->value);
	lexem_del(&l);
	(void)arg;
}
