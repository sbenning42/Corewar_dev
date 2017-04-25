/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:54:10 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/25 09:33:45 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>
# include <errno.h>

# define MAX_UINT 4294967295
# define BS 256

# define TABSIZE(X) (sizeof(X) / sizeof(*X))

typedef unsigned int		t_uint;
typedef unsigned char		t_uchar;
typedef unsigned long int	t_ulong;
typedef unsigned short int	t_ushort;

typedef struct s_list		t_list;

typedef struct s_trans		t_trans;
typedef struct s_state		t_state;
typedef struct s_nfa		t_nfa;
typedef struct s_re_entry	t_re_entry;

typedef struct s_lexer		t_lexer;
typedef struct s_lexem		t_lexem;
typedef struct s_analyzer	t_analyzer;

typedef void				(*t_func)(char **, t_list **, int *);
typedef int					(*t_factor)(t_list **, t_re_entry *);
typedef struct s_disp		t_disp;

#endif
