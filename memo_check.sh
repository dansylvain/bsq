#!/bin/bash

# Liste des inputs à tester
inputs=(
"file_1"
)

# Chemin vers ton programme rush-02
program="./bsq"

# Parcours des inputs
for input in "${inputs[@]}"; do
  echo "Testing with input: $input"

  # Exécuter valgrind sur le programme avec l'input
  valgrind_output=$(eval valgrind --leak-check=full --track-origins=yes --max-stackframe=4000064 $program "$input" 2>&1)

  # Grep pour trouver les adresses mémoire (0x...)
  if echo "$valgrind_output" | grep -q "0x"; then
    echo "Memory issues detected for input: $input"
    echo "$valgrind_output" | grep "0x"
  else
    echo "No memory issues for input: $input"
  fi

  echo "----------------------------------------"
done
