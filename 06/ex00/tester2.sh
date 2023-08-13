#!/bin/bash

# Define the testValues function
# function testValues {
#     ./convert "$1" >> testcase
# }
# #Clear the existing testcase file
# > testcase

input_filename="testcase"
output_filename="ss"

input_lines=$(cat "$input_filename")

IFS=$'\n' lines=($input_lines)
array_index=0

> "$output_filename"

while IFS= read -r condition && IFS= read -r char_value && IFS= read -r int_value && IFS= read -r float_value && IFS= read -r double_value && IFS= read -r separator; do
    echo "else if (!strcmp(input, \"$condition\"))" >> "$output_filename"
    echo "        array[$array_index] = \"$char_value\"; array[$((array_index + 1))] = \"$int_value\"; array[$((array_index + 2))] = \"$float_value\"; array[$((array_index + 3))] = \"$double_value\";" >> "$output_filename"
done < "$input_filename"

testValues "1"
testValues "-1"
testValues "+42"
testValues "2147483647"
testValues "-2147483648"
testValues "+2147483647"
testValues "+2147483648"
testValues "-2147483649"
testValues "1222222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222"
testValues "1222222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222222222222222222223333333333333333333333333333333333333333333333333333333322222222222222222222222222222222"
testValues ".1"
testValues "-2147483649"
testValues "2147483648"
testValues "1.1"
testValues "-inff"
testValues "+inff"
testValues "inff"
testValues "nanf"
testValues "1.111111111"
testValues "inf"
testValues "-inf"
testValues "+inf"
testValues "inf"
testValues "nan"
testValues "1233.00040040404"
testValues "++1"
testValues "--1"
testValues "-"
testValues "+"
testValues "--"
testValues "++"
testValues "--1"
testValues "++1"
testValues "1.f"
testValues "1f"
testValues ".f"
testValues "-1.f"
testValues "-1f"
testValues "-.f"
testValues "f.1"
testValues "f1."
testValues "1.1"
testValues "-1.1"
testValues "+1.1"
testValues "--1.1"
testValues "-1f1"
testValues "1ff"
testValues "1f1"
testValues ".40545"
testValues "42.40545464454543434"
testValues "1242.0022342"
testValues "545453434343434343434354545343434343434343435454534343434343434343545453434343434343434354545343434343434343435454534343434343434343.03"
