# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_corewar.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:28:27 by sbenning          #+#    #+#              #
#    Updated: 2017/04/27 13:15:22 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make -C ..
mkdir -p ressources
cp ../asm ressources/
cp ../corewar ressources/

cd ressources

./asm ../corewar-exemple/champions/ld_st.s
./corewar -c -v 31 -s 5 -d 10 ../corewar-exemple/champions/ld_st.cor

./asm ../corewar-exemple/champions/ld_st_toolong.s
./corewar -c -v 31 -s 5 -d 10 ../corewar-exemple/champions/ld_st_toolong.cor

./asm ../corewar-exemple/champions/ldi_sti.s
./corewar -c -v 31 -s 25 -d 50 ../corewar-exemple/champions/ldi_sti.cor

cd ..
rm -rf ressources
