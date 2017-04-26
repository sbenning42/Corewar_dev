/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_access_endian.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:05:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:05:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_endian(void)
{
	int			endian;

	endian = 1;
	return (*(char *)&endian);
}

int				ft_bigint(int i)
{
	return ((ft_endian() ? ft_intswap(i) : i));
}

int				ft_littleint(int i)
{
	return ((ft_endian() ? i : ft_intswap(i)));
}

short			ft_bigshort(short sh)
{
	return ((ft_endian() ? ft_shortswap(sh) : sh));
}

short			ft_littleshort(short sh)
{
	return ((ft_endian() ? sh : ft_shortswap(sh)));
}
