/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_encode_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:35:35 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:35:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					encode_direct_slabel(t_instruction *ins, \
							t_payload *payload, unsigned int i, t_label *label)
{
	short			val;
	unsigned char	*tmp;

	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(sizeof(short) + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	val = (short)((short)label->offset - (short)ins->offset);
	val = SHORT_BIG2LITTLE(val);
	ft_memcpy(ins->arg_payload + ins->arg_size, &val, sizeof(short));
	ins->arg_size += sizeof(short);
	return (0);
	(void)payload;
	(void)i;
}

int					encode_direct_ilabel(t_instruction *ins, \
							t_payload *payload, unsigned int i, t_label *label)
{
	int				val;
	unsigned char	*tmp;

	tmp = ins->arg_payload;
	if (!(ins->arg_payload = ft_memalloc(sizeof(int) + ins->arg_size)))
		return (-1);
	if (ins->arg_size)
	{
		ft_memcpy(ins->arg_payload, tmp, ins->arg_size);
		free(tmp);
	}
	val = (int)((int)label->offset - (int)ins->offset);
	val = INT_BIG2LITTLE(val);
	ft_memcpy(ins->arg_payload + ins->arg_size, &val, sizeof(int));
	ins->arg_size += sizeof(int);
	return (0);
	(void)i;
	(void)payload;
}

void				label_error(char *label)
{
	ft_fprintf(2, "Can't find this label: %s\n", label);
}

int					encode_direct_label(t_instruction *ins, \
											t_payload *payload, unsigned int i)
{
	t_label	*label;

	if (!(label = get_label(payload->labels, ins->str_arguments[i] + 2)))
	{
		label_error(ins->str_arguments[i]);
		return (-1);
	}
	if (ins->op->label_size == 2)
		return (encode_direct_slabel(ins, payload, i, label));
	return (encode_direct_ilabel(ins, payload, i, label));
	(void)payload;
}

int					encode_indirect_label(t_instruction *ins, \
											t_payload *payload, unsigned int i)
{
	t_label			*label;

	if (!(label = get_label(payload->labels, ins->str_arguments[i] + 1)))
	{
		label_error(ins->str_arguments[i]);
		return (-1);
	}
	return (encode_direct_slabel(ins, payload, i, label));
	(void)payload;
}
