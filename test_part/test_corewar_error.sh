# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_cor_error.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qstemper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 16:01:57 by qstemper          #+#    #+#              #
#    Updated: 2017/04/26 16:09:52 by qstemper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cd ../corewar_part
make > /dev/null
cd ../test_part
clear

echo "\n\t\033[0;32mTesting a non existing champ\033[0m\033[0;31m"
./../corewar_part/corewar -n 42 easy_peasy_chineasy.cor

echo "\033[0m\n\t\033[0;32mTesting a champ with no rights on it\033[0m\033[0;31m"
chmod 000 corewar-exemple/champions/zork.cor
./../corewar_part/corewar -n -42 corewar-exemple/champions/zork.cor
chmod 777 corewar-exemple/champions/zork.cor

echo "\033[0m\n\t\033[0;32mTesting a champ in a dir with no rights on it\033[0m\033[0;31m"
mkdir youjustlosethegame
cp corewar-exemple/champions/zork.cor youjustlosethegame/
chmod 000 youjustlosethegame
./../corewar_part/corewar -n 21 youjustlosethegame/zork.cor
chmod 777 youjustlosethegame
rm -Rf youjustlosethegame
echo "\033[0m"

cd ../corewar_part
make fclean > /dev/null
cd ../test_part
