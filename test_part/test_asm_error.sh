# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_asm_error.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 16:01:40 by qstemper          #+#    #+#              #
#    Updated: 2017/04/26 16:10:13 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cd ../asm_part
make > /dev/null
cd ../test_part
clear

echo "\n\t\033[0;32mTesting a non existing champ\033[0m\033[0;31m"
./../asm_part/asm easy_peasy_chineasy.s

echo "\033[0m\n\t\033[0;32mTesting a champ with no rights on it\033[0m\033[0;31m"
chmod 000 corewar-exemple/champions/zork.s
./../asm_part/asm corewar-exemple/champions/zork.s
chmod 777 corewar-exemple/champions/zork.s

echo "\033[0m\n\t\033[0;32mTesting a champ in a dir with no rights on it\033[0m\033[0;31m"
mkdir themoneyisnothere
cp corewar-exemple/champions/zork.s themoneyisnothere/
chmod 000 themoneyisnothere
./../asm_part/asm themoneyisnothere/zork.s
chmod 777 themoneyisnothere
rm -Rf themoneyisnothere
echo "\033[0m"

cd ../asm_part
make fclean > /dev/null
cd ../test_part
