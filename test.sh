#!/bin/bash
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
mkdir -p "$script_dir/Test_Log"


# if [ $# -eq 1 ]; then
#     selected_dir="$1"
#     for ex in {00..04}; do
# 		echo "Entering 0$selected_dir/ex$ex"
#         if [ -d "0$selected_dir/ex$ex" ]; then
#             echo "Entering 0$selected_dir/ex$ex"
#             cd "0$selected_dir/ex$ex" || exit

#             make re
#             program_name=$(awk -F= '/^NAME/ {print $2}' Makefile | tr -d '[:space:]')
#             if [ -n "$program_name" ]; then
#                 echo "Running ./$program_name"
#                 ./"$program_name" &> "$script_dir/Test_Log/output${selected_dir}${ex}.log"
#             fi
#             make fclean
#             cd ../../
            
#         fi
#     done
# 	#exit 0 # Stop executing the rest of the loop
# fi


for directory in {2..8}; do
    for ex in {0..4}; do
        if [ -d "0$directory/ex0$ex" ]; then
            echo "Entering 0$directory/ex0$ex"
            cd "0$directory/ex0$ex" || exit
            make

            if [ -f "Makefile" ]; then
                program_name=$(awk -F= '/^NAME/ {print $2}' Makefile | tr -d '[:space:]')
                if [ -n "$program_name" ]; then
                    echo "Running ./$program_name"
                    ./"$program_name" &> "$script_dir/Test_Log/output${directory}${ex}.log"
                fi
            fi
            cd ../../
        fi
    done
done

for directory in {2..8}; do
    for ex in {0..4}; do
        if [ -d "0$directory/ex0$ex" ]; then
			cd "0$directory/ex0$ex" || exit
			make fclean
            cd ../../
        fi
    done
done


