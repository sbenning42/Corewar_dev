/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_compile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:03:12 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/28 14:52:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			make_payload(t_payload *payload, t_header_t header)
{
	size_t			cursor;
	t_instruction	*drive;

	header.prog_size = INT_BIG2LITTLE(payload->size);
	payload->size += sizeof(t_header_t);
	if (!(payload->payload = ft_memalloc(payload->size)))
		return (-1);
	ft_memcpy(payload->payload, &header, sizeof(t_header_t));
	cursor = sizeof(t_header_t);
	drive = payload->instruction;
	while (drive)
	{
		ft_memcpy(payload->payload + cursor, &drive->op->opcode, 1);
		cursor += 1;
		if (drive->op->ocp)
		{
			ft_memcpy(payload->payload + cursor, &drive->ocp, 1);
			cursor += 1;
		}
		ft_memcpy(payload->payload + cursor, drive->arg_payload, \
						drive->arg_size);
		cursor += drive->arg_size;
		drive = drive->next;
	}
	return (0);
}

static int			asm_compile_bis(t_header_t *header, t_token **lst)
{
	if (asm_header(header, lst))
	{
		del_token(lst);
		return (1);
	}
	return (0);
}

t_payload			asm_compile(int fd, char *file)
{
	t_token			*lst;
	t_header_t		header;
	t_payload		payload;

	lst = NULL;
	ft_bzero((void *)&payload, sizeof(t_payload));
	if (asm_parse(fd, file, &lst))
		return (payload);
	if (asm_compile_bis(&header, &lst) == 1)
		return (payload);
	dump_header(header);
	dump_token(lst);
	if (asm_payload(&payload, &lst))
	{
		del_token(&lst);
		return (payload);
	}
	if (resolve_label(&payload))
		return (payload);
	make_payload(&payload, header);
	dump_payload(&payload);
	del_token(&lst);
	del_label(&payload.labels);
	del_instruction(&payload.instruction);
	return (payload);
}
