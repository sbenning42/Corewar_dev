/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_encode_argument.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:20:49 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 07:45:42 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					encode_direct_value(t_instruction *ins, \
											t_payload *payload, unsigned int i)
{
	unsigned char	*tmp;
	short			sval;
	int				ival;
	size_t			size;

	size = ins->op->label_size;
	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(size + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	if (size == 2)
		sval = SHORT_BIG2LITTLE((short)ft_atoi(ins->str_arguments[i] + 1));
	else if (size == 4)
		ival = INT_BIG2LITTLE((int)ft_atoi(ins->str_arguments[i] + 1));
	ft_memcpy(ins->arg_payload + ins->arg_size, \
							(size == 2 ? (void *)&sval : (void *)&ival), size);
	ins->arg_size += size;
	return (0);
	(void)payload;
}

int					encode_indirect(t_instruction *ins, \
											t_payload *payload, unsigned int i)
{
	unsigned char	*tmp;
	short			val;

	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(sizeof(short) + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	val = (short)ft_atoi(ins->str_arguments[i]);
	val = SHORT_BIG2LITTLE(val);
	ft_memcpy(ins->arg_payload + ins->arg_size, &val, sizeof(short));
	ins->arg_size += sizeof(short);
	return (0);
	(void)payload;
}

int					encode_registre(t_instruction *ins, \
											t_payload *payload, unsigned int i)
{
	unsigned char	*tmp;

	tmp = ins->arg_payload;
	if (!(ins->arg_payload = \
						ft_memalloc(sizeof(unsigned char) + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	ins->arg_payload[ins->arg_size] = \
							(unsigned char)ft_atoi(ins->str_arguments[i] + 1);
	ins->arg_size += sizeof(unsigned char);
	return (0);
	(void)payload;
}
