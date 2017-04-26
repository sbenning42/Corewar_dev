/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:05:20 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:05:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				read_int(t_vm *vm, int *pc)
{
	int			i;

	i = ft_bigint(bin_int(vm, *pc));
	*pc = vm_pc(vm, *pc + 4);
	return (i);
}

void			write_int(t_vm *vm, int *pc, int value)
{
	t_swap		swap;
	int			cp_pc;

	cp_pc = *pc;
	swap.u_int = ft_bigint(value);
	*bin_access_w(vm, cp_pc++) = swap.u_tab[0];
	*bin_access_w(vm, cp_pc++) = swap.u_tab[1];
	*bin_access_w(vm, cp_pc++) = swap.u_tab[2];
	*bin_access_w(vm, cp_pc) = swap.u_tab[3];
}

int				read_short(t_vm *vm, int *pc)
{
	short		s;

	s = ft_bigshort(bin_short(vm, *pc));
	*pc = vm_pc(vm, *pc + 2);
	return ((int)s);
}

int				read_char(t_vm *vm, int *pc)
{
	char		c;

	c = bin_char(vm, *pc);
	*pc = vm_pc(vm, *pc + 1);
	return ((int)c);
}
