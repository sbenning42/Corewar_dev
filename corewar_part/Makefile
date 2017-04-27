#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/18 23:33:22 by sbenning          #+#    #+#             *#
#*   Updated: 2017/04/22 13:44:24 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			corewar

SRC =           ft_file.c\
				ft_file_action.c\
                get_next_line.c\
				main.c\
                op.c\
				vm_access_arg.c\
				vm_access_arg_p2.c\
				vm_access_bin.c\
				vm_access.c\
				vm_access_endian.c\
				vm_access_fill.c\
				vm_access_read.c\
				vm_access_swap_and_bin.c\
				vm_args.c\
				vm_check.c\
                vm_check_rules.c\
                vm_declare.c\
                vm_del.c\
				vm_error.c\
                vm_get.c\
				vm_handler_args_p1.c\
				vm_handler_args_p2.c\
				vm_handler_opcode_first_set.c\
				vm_handler_opcode_st.c\
				vm_handler_opcode_second_set.c\
				vm_handler_opcode_third_set.c\
				vm_handler_opcode_tool.c\
				vm_handler_opcode_fourth_set.c\
				vm_is.c\
				vm_load_args.c\
				vm_load_process.c\
				vm_main.c\
				vm_new_player.c\
				vm_player_id.c\
				vm_play_process.c\
                vm_put_instruction.c\
                vm_put_memory.c\
                vm_put_player.c\
                vm_set.c\
				vm_setup.c\
                vm_write_color.c

SRC_DIR =		srcs/
OBJ_DIR =		obj/

OBJ =			$(SRC:.c=.o)

COR_SRC =		$(addprefix $(SRC_DIR), %.c)

COR_OBJ =		$(addprefix $(OBJ_DIR), %.o)

ABS_OBJ =		$(addprefix $(OBJ_DIR), $(OBJ))

HEADER =		includes

DEPEND =	    vm.h

RESSOURCES =	../ressources/

ABS_DEPEND =	$(addprefix $(HEADER)/, $(DEPEND))

LIBFT =			ft

OBJ_LIBFT =		libft.a

LIBFT_DIR =		libft

ABS_OBJ_LIBFT =	$(addprefix $(LIBFT_DIR)/, $(OBJ_LIBFT))

LIBFT_HEADER =	$(addprefix $(LIBFT_DIR)/, $(HEADER))

CC =			gcc

FLAG =			-Wall -Wextra -Werror

all : $(ABS_OBJ_LIBFT) $(NAME)

$(NAME) :  $(ABS_OBJ)
	$(CC) $(FLAG) -g -o $@ $^ -L$(LIBFT_DIR) -l$(LIBFT)

$(COR_OBJ) : $(COR_SRC) $(ABS_DEPEND)
	@mkdir -p obj
	$(CC) $(FLAG) -g -o $@ -c $< -I$(HEADER) -I$(RESSOURCES) -I$(LIBFT_HEADER)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(ABS_OBJ_LIBFT) :
	make -C $(LIBFT_DIR)

lclean :
	make clean -C $(LIBFT_DIR)

lfclean :
	make fclean -C $(LIBFT_DIR)

lre : 
	make re -C $(LIBFT_DIR)

clean : lclean
	rm -rf $(OBJ_DIR)
	rm -f $(ABS_OBJ)

fclean : clean lfclean
	rm -f $(NAME)

re : fclean lre all
