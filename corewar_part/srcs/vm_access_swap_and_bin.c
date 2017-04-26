/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access_swap_and_bin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:05:26 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:05:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_intswap(int i)
{
	t_swap		origin;
	t_swap		swap;

	origin.u_int = i;
	swap.u_tab[0] = origin.u_tab[3];
	swap.u_tab[1] = origin.u_tab[2];
	swap.u_tab[2] = origin.u_tab[1];
	swap.u_tab[3] = origin.u_tab[0];
	return (swap.u_int);
}

short			ft_shortswap(short sh)
{
	t_swap		origin;
	t_swap		swap;

	origin.u_short = sh;
	swap.u_tab[0] = origin.u_tab[1];
	swap.u_tab[1] = origin.u_tab[0];
	return (swap.u_short);
}

short			bin_short(t_vm *vm, int pc)
{
	t_swap		swap;

	swap.u_tab[0] = bin_access(vm, pc++);
	swap.u_tab[1] = bin_access(vm, pc);
	return (swap.u_short);
}

int				bin_int(t_vm *vm, int pc)
{
	t_swap		swap;

	swap.u_tab[0] = bin_access(vm, pc++);
	swap.u_tab[1] = bin_access(vm, pc++);
	swap.u_tab[2] = bin_access(vm, pc++);
	swap.u_tab[3] = bin_access(vm, pc);
	return (swap.u_int);
}
