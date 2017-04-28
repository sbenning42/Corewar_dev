# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_corewar.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:28:27 by sbenning          #+#    #+#              #
#    Updated: 2017/04/28 14:35:26 by sbenning         ###   ########.fr        #
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

cp ../corewar-exemple/corewar zaz

echo "Launch a corewar game with turtle.cor, bigzork.cor and fluttershy.cor on our vm and zaz one"

./corewar -d 5000 ../corewar-exemple/champions/turtle.cor ../corewar-exemple/champions/bigzork.cor ../corewar-exemple/champions/fluttershy.cor > core_out_5
./zaz -d 5000 ../corewar-exemple/champions/turtle.cor ../corewar-exemple/champions/bigzork.cor ../corewar-exemple/champions/fluttershy.cor > zaz_out_5
./corewar -d 10000 ../corewar-exemple/champions/turtle.cor ../corewar-exemple/champions/bigzork.cor ../corewar-exemple/champions/fluttershy.cor > core_out_10
./zaz -d 10000 ../corewar-exemple/champions/turtle.cor ../corewar-exemple/champions/bigzork.cor ../corewar-exemple/champions/fluttershy.cor > zaz_out_10
./corewar -d 20000 ../corewar-exemple/champions/turtle.cor ../corewar-exemple/champions/bigzork.cor ../corewar-exemple/champions/fluttershy.cor > core_out_20
./zaz -d 20000 ../corewar-exemple/champions/turtle.cor ../corewar-exemple/champions/bigzork.cor ../corewar-exemple/champions/fluttershy.cor > zaz_out_20
./corewar -d 25000 ../corewar-exemple/champions/turtle.cor ../corewar-exemple/champions/bigzork.cor ../corewar-exemple/champions/fluttershy.cor > core_out_25
./zaz -d 25000 ../corewar-exemple/champions/turtle.cor ../corewar-exemple/champions/bigzork.cor ../corewar-exemple/champions/fluttershy.cor > zaz_out_25

echo "End game, begin diff on cycle 5000, 10000, 20000 and 25000"

echo "diff on cycle 5000"
diff core_out_5 zaz_out_5
echo "diff on cycle 10000"
diff core_out_10 zaz_out_10
echo "diff on cycle 20000"
diff core_out_20 zaz_out_20
echo "diff on cycle 25000"
diff core_out_25 zaz_out_25


cd ..
rm -rf ressources
