# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_corewar.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:28:27 by sbenning          #+#    #+#              #
#    Updated: 2017/04/26 14:22:45 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make -C ..
mkdir -p ressources
cp ../asm ressources/
cp ../corewar ressources/

cd ressources

./asm ../corewar-exemple/champions/st_ld.s
./corewar -c -v 31 -s 5 -d 10 ../corewar-exemple/champions/st_ld.cor

./asm ../corewar-exemple/champions/sti_ldi.s
./corewar -c -v 31 -s 25 -d 50 ../corewar-exemple/champions/sti_ldi.cor

cd ..
rm -rf ressources
