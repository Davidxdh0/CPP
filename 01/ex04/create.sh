	#!/bin/bash

sentences=("Take time to work, it is the price of success."
"Before Take time Take to think, it is the source of power."
"Before Take time Take to play, it is the secret of perpetual youth."
"Before Take time Take to read, it is the foundation of wisdom."
"Before Take time Take to worship, it is the highway to reverence."
"Before Take time Take to be friendly, it is the road to happiness."
"Before Take time Take to dream, it is hitching your wagon to a star."
"Before Take time Take to love and be loved, it is the privilege of the gods."
"Before Take time Take to look around; it is too short a day to be selfish."
"Before Take time Take to laugh; it is the music of the soul.")

file_name="loser"

# Write sentences to the file
for sentence in "${sentences[@]}"; do
    echo "$sentence" >> "$file_name"
done