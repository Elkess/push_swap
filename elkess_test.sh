#!/bin/bash

PURPLE='\033[0;35m' # Purple color
NC='\033[0m'        # No color

echo -e "${PURPLE}"
echo "       __    __                         
  ____ |  | |  | __ ____   ______ ______
_/ __ \|  | |  |/ // __ \ /  ___//  ___/
\  ___/|  |_|    <\  ___/ \___ \ \___ \ 
 \___  >____/__|_ \\___  >____  >____  >
     \/          \/    \/     \/     \/ "
echo -e "${NC}"

max_instr=0
max_arg=""

trap 'echo -e "\nMax instructions found: $max_instr\nARG=\"$max_arg\""; exit 0' SIGINT

permute() {
    local prefix=$1
    shift
    local numbers=($@)
    local count=${#numbers[@]}

    if [ $count -eq 0 ]; then
        INSTR_COUNT=$(./push_swap $prefix | wc -l)

        if [ "$INSTR_COUNT" -gt 700 ]; then
            echo "Found a case with $INSTR_COUNT instructions!"
            echo "ARG=\"$prefix\""
            exit 0
        fi

        if [ "$INSTR_COUNT" -gt "$max_instr" ]; then
            max_instr=$INSTR_COUNT
            max_arg="$prefix"
        fi

        echo "Checked case with $INSTR_COUNT instructions"
        return
    fi

    for i in "${!numbers[@]}"; do
        permute "$prefix${numbers[i]} " "${numbers[@]:0:$i}" "${numbers[@]:$((i + 1))}"
    done
}

range=($(seq 1 100)) # Change the range as needed
permute "" "${range[@]}"
