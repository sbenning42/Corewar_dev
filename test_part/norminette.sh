# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    norminette.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 11:49:36 by sbenning          #+#    #+#              #
#    Updated: 2017/04/26 12:19:24 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

sh norminette_lib.sh
norminette ../asm_part/srcs/*.c ../asm_part/includes/*.h
norminette ../corewar_part/srcs/*.c ../corewar_part/includes/*.h