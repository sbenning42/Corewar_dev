#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/04/22 12:22:18 by                   #+#    #+#             *#
#*   Updated: 2017/04/22 12:32:07 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

ASM_NAME =		asm
COREWAR_NAME =	corewar

ASM_DIR =		asm_part/
COREWAR_DIR =	corewar_part/

ASM =			$(addprefix $(ASM_DIR), $(ASM_NAME))
COREWAR =		$(addprefix $(COREWAR_DIR), $(COREWAR_NAME))

all: $(ASM) $(COREWAR)

$(ASM):
	make -C $(ASM_DIR)
	cp $(ASM) .

$(COREWAR):
	make -C $(COREWAR_DIR)
	cp $(COREWAR) .

clean :
	make clean -C $(ASM_DIR)
	make clean -C $(COREWAR_DIR)

fclean :
	make fclean -C $(ASM_DIR)
	make fclean -C $(COREWAR_DIR)
	rm -f $(ASM_NAME)
	rm -f $(COREWAR_NAME)

re : fclean all
