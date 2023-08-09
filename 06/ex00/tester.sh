#!/bin/bash

run_test() {
    local input=$1
    local expected_output=$2
    local test_number=$3

    # echo -n "Test $test_number - Input: $input"
    output=$(./convert "$input")
    if [ "$output" == "$expected_output" ]; then
		echo -n "Test $test_number - Input: $input"
        echo -e "\033[32m ✓ PASSED\033[0m"
        # echo -e "$output"
		# echo "-----------------------"
		local p=1;
    else
		echo -n "Test $test_number - Input: $input"
        echo -e "\033[31m ✗ FAILED\033[0m Input: $input"
        echo "Expected Output:"
        echo -e "$expected_output"
        echo "Actual Output:"
        echo -e "$output"
        echo "-----------------------"
    fi
}

test_number=0
lines_to_skip=0
input=""
expected_output=""
while IFS= read -r line; do
    if [ $lines_to_skip -eq 0 ]; then
        if [ -n "$line" ]; then
            ((test_number++))
            input="$line"
            lines_to_skip=5
        fi
    else
        ((lines_to_skip--))
        if [ $lines_to_skip -eq 4 ]; then
            expected_output="$line"
        elif [ $lines_to_skip -gt 0 ]; then
            expected_output="$expected_output"$'\n'"$line"
        elif [ $lines_to_skip -eq 0 ]; then
            run_test "$input" "$expected_output" "$test_number"
        fi
    fi
done < testcase
