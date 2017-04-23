/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:17:32 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/13 14:36:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				vm_is_process_dead(void *ref, void *c, size_t size)
{
	t_process	*p;

	p = (t_process *)c;
	return (p->dead);
	(void)ref;
	(void)size;
}
