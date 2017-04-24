/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:38:03 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/24 10:38:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_del_player(void *content, size_t size)
{
	free(content);
	(void)size;
}

void	vm_del_process(void *content, size_t size)
{
	free(content);
	(void)size;
}
