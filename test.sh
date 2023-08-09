#!/bin/bash
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
mkdir -p "$script_dir/Test_Log"

for directory in {02..09}; do
    for ex in {00..04}; do
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

for directory in {02..09}; do
    for ex in {00..04}; do
        if [ -d "0$directory/ex0$ex" ]; then
			cd "0$directory/ex0$ex" || exit
			make fclean
            cd ../../
        fi
    done
done


