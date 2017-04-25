/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:01:07 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/25 09:32:08 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include "ft_header.h"
# include "ft_str.h"
# include "ft_exit.h"

extern char		**g_environ;
extern char		**g_ft_environ;
extern char		*g_ft_program_name;

void			ft_init(char *name);
void			ft_initname(char *name);
void			ft_initenv(void);

#endif
