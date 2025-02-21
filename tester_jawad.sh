#!/bin/bash

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${YELLOW}"\n\t\tTEST CREATED BY: "${DEF_COLOR};
printf ${CYAN}"GEMARTIN\t\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};

rm -rf traces.txt
rm -rf 0

# -=-=-=-=-	Control errors -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

FILE=$PWD/push_swap
FICHERO=test_check.txt

if [ -f "$FILE" ]; then
	echo -n
else
	printf "${RED}NO EXIST PUSH_SWAP PROGRAM ${DEF_COLOR}\n";
	exit 0
fi

if [ $1 == -v ];then
if [ -z "$2" ];then
	n=500;
else
	n=$2;
fi
ARG=$(ruby -e "puts (0..($n)).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./pro_checker $ARG
exit 0
fi

if [ $1 == -v2 ];then
ARG=$2; ./push_swap $ARG | ./pro_checker $ARG
exit 0
fi

if [ -z "$1" ] || [ $1 != -b ]; then
printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${BLUE}"\n\t\t\tCONTROL ERRORS\t\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

ARG="a"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}1.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}1.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}1.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="111a11"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}2.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}2.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}2.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="hello world"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}3.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}3.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}3.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

./push_swap "" > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}4.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}4.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}4.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="0 0"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}5.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}5.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}5.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="-01 -001"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}6.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}6.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}6.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="111-1 2 -3"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}7.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}7.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}7.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="-3 -2 -2"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}8.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}8.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}8.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="\n"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}9.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}9.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}9.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="-2147483649"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}10.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}10.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}10.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="-2147483650"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}11.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}11.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}11.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="2147483648"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}12.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}12.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}12.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="8 008 12"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}13.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}13.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}13.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="10 -1 -2 -3 -4 -5 -6 90 99 10"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}14.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}14.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}14.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="1 +1 -1"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}15.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}15.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}15.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="3333-3333 1 4"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}16.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}16.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}16.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="111a111 -4 3"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}17.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}17.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}17.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="111111 -4 3 03"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}18.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}18.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}18.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="2147483649"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}19.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}19.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}19.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="2147483647+1"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}20.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}20.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}20.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="0 1 2 3 4 5 0"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}21.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}21.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}21.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="3 +3"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}22.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}22.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}22.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="3+3"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}23.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}23.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}23.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="42 42"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}24.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}24.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}24.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="42 -42 -42 "
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}25.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}25.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}25.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="4222-4222"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}26.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}26.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}26.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="99999999999999999999999999"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}27.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}27.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}27.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="-99999999999999999999999999"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}28.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}28.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}28.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="0 -0 1 -1"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}29.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}29.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}29.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="0 +0 1 -1"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}30.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}30.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}30.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="111+111 -4 3"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}31.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}31.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}31.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="-"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}32.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}32.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}32.[KO] ${DEF_COLOR}\n";
fi

ARG="+"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}33.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}33.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}33.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="--123 1 321"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}34.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}34.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}34.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="++123 1 321"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${GREEN}35.[OK] ${DEF_COLOR}\n";
  else
  	printf "${RED}35.[KO] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}35.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="0000000000000000000000009 000000000000000000000009"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}36.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}36.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}36.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="00000001 1 9 3"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}37.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}37.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}37.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="00000003 003 9 1"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}38.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}38.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}38.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="--21345"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}39.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}39.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}39.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt


ARG="1 01"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}40.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}40.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}40.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="-000 -0000"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}41.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}41.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}41.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt

ARG="-00042 -000042"
./push_swap $ARG > /dev/null 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
    printf "${GREEN}42.[OK] ${DEF_COLOR}\n";
  else
    printf "${RED}42.[KO] ${DEF_COLOR}\n";
    break
  fi
done < test_check.txt
else
  printf "${RED}42.[KO] ${DEF_COLOR}\n";
fi

rm -rf test_check.txt
rm -rf 0

# -=-=-=-=-	Basic -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${BLUE}"\n\t\t\tBasic input\t\t\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

ARG="2 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}";
else
	printf "${RED}1.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}2.[OK] ${DEF_COLOR}";
else
	printf "${RED}2.[KO]${DEF_COLOR}";
fi

ARG="1 3 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}3.[OK] ${DEF_COLOR}";
else
	printf "${RED}3.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}4.[OK] ${DEF_COLOR}";
else
	printf "${RED}4.[KO]${DEF_COLOR}";
fi

ARG="2 3 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}5.[OK] ${DEF_COLOR}";
else
	printf "${RED}5.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}6.[OK] ${DEF_COLOR}";
else
	printf "${RED}6.[KO]${DEF_COLOR}";
fi

ARG="2 1 3";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}7.[OK] ${DEF_COLOR}";
else
	printf "${RED}7.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}8.[OK] ${DEF_COLOR}";
else
	printf "${RED}8.[KO]${DEF_COLOR}";
fi

ARG="3 1 2";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}9.[OK] ${DEF_COLOR}";
else
	printf "${RED}9.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}10.[OK] ${DEF_COLOR}";
else
	printf "${RED}10.[KO]${DEF_COLOR}";
fi

ARG="3 2 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}11.[OK] ${DEF_COLOR}";
else
	printf "${RED}11.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}12.[OK] ${DEF_COLOR}";
else
	printf "${RED}12.[KO]${DEF_COLOR}";
fi

printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};
printf ${MAGENTA}"\n\t\t  All size test + leaks check\t\n"${DEF_COLOR};
printf ${MAGENTA}"\n-------------------------------------------------------------\n\n"${DEF_COLOR};

echo BONUS-All size test >> traces.txt

val=500
res_1=0
res_2=0
cont=1
var=0
while [ $cont -lt $val ] && [ $var -lt 500 ]
do
ARG=$(ruby -e "puts (00..$var).to_a.shuffle.join(' ')");
var=$(($var + 1))
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}$cont .[OK] ${DEF_COLOR}";
	((res_1++))
else
	printf "${RED}$cont .[KO] ${DEF_COLOR}";
	echo TEST $cont ARG:"$ARG" >> traces.txt
 	((res_2++))
fi
R=$(./push_swap $ARG | leaks -atExit -- ./checker $ARG > /dev/null && echo $?)
if [[ $R == 0 ]]; then
  printf "${GREEN}[MOK] ${DEF_COLOR}";
else
  printf "${RED} [KO LEAKS] ${DEF_COLOR}";
fi
echo
((cont++))
done

while [ $var -lt 1000 ]
do
ARG=$(ruby -e "puts (00..$var).to_a.shuffle.join(' ')");
var=$(($var + 25))
S=$(./push_swap $ARG | ./checker_Mac $ARG)
R=$(./push_swap $ARG | ./checker $ARG)
if [ $S == $R ]; then
	printf "${GREEN}$cont .[OK] ${DEF_COLOR}";
	((res_1++))
else
	printf "${RED}$cont .[KO] ${DEF_COLOR}";
	echo TEST $cont ARG:"$ARG" >> traces.txt
 	((res_2++))
fi
R=$(./push_swap $ARG | leaks -atExit -- ./checker $ARG > /dev/null && echo $?)
if [[ $R == 0 ]]; then
  printf "${GREEN}[MOK] ${DEF_COLOR}";
else
  printf "${RED} [KO LEAKS] ${DEF_COLOR}";
fi
echo
((cont++))
done

((cont--))
echo

val=$(($val+$var))

((val--))
if [ $res_1 == $cont ]; then
	printf "${GREEN}\nCongrats , all tests have been completed successfully 🥳✅\n"
	echo OK >> traces.txt
fi
if [ $res_2 != 0 ]; then
printf	"${GREEN}\nOK${WHITE} TESTS $res_1/$cont\n"
printf	"${RED}\nKO${WHITE} TESTS $res_2/$cont\n"
printf "${CYAN}\nCheck traces $PWD/traces.txt\n"
fi

fi

rm -rf 0
rm -rf test_check.txt
