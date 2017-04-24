/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_handler_args_p1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:43:16 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/24 10:43:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_handler_arg_pnum(t_vm *vm, char *arg)
{
	t_lexem	*l;
	int		n;

	if (!((l = get_arg()) && l->id == VM_NUMBER_ARG))
		vm_fatal(VM_EUSAGE);
	n = ft_atoi(l->value);
	lexem_del(&l);
	if (!((l = get_arg()) && (l->id == VM_CHAMP_ARG || l->id == VM_NUMBER_ARG)))
		vm_fatal(VM_EUSAGE);
	vm_new_player(vm, l->value, n);
	lexem_del(&l);
	(void)arg;
}

void		vm_handler_arg_verbose(t_vm *vm, char *arg)
{
	t_lexem	*l;

	if (!((l = get_arg()) && l->id == VM_NUMBER_ARG))
		vm_fatal(VM_EUSAGE);
	vm->config.verb = ft_atoi(l->value);
	lexem_del(&l);
	(void)arg;
}

void		vm_handler_arg_champion(t_vm *vm, char *arg)
{
	vm_new_player(vm, arg, -1);
}
