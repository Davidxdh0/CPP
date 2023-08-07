#!/bin/bash

# Function to run the converter and compare the output
run_test() {
    local input=$1
    local expected_output=$2
    local test_number=$3

    echo -n "Test $test_number - "

    # Run the converter and capture the output
    output=$(./converter "$input")

    # Compare the output with the expected output
    if [ "$output" == "$expected_output" ]; then
        echo -e "\033[32m✓ PASSED\033[0m $expected_output"
    else
        echo -e "\033[31m✗ FAILED\033[0m $expected_output input: $input"
        echo "Expected Output:"
        echo -e "$expected_output"
        echo "Actual Output:"
        echo -e "$output"
        echo "-----------------------"
    fi
}

# Read test cases from the "testcases" file
while read -r line; do
    if [ -n "$line" ]; then
        ((test_number++))
        input=$(echo "$line" | cut -d " " -f 1)
        expected_output=$(echo "$line" | cut -d " " -f 2)
        run_test "$input" "$expected_output" "$test_number"
    fi
done < testcases
