#!/bin/bash

echo ""
echo "════════════════════════════════════════"
echo "        MEMORY MANAGEMENT CHECK         "
echo "════════════════════════════════════════"
echo ""

total=0  # Remplace par le nombre réel de tests dans ce script
passed=0 # Remplace par le nombre réel de tests réussis

# Liste des inputs à tester
inputs=(
"file_1"
"file_1 file_2 toto"
"toto file_1"
"toto"
""
"wrong_file_charset"
)

# Chemin vers ton programme rush-02
program="./bsq"


# Chemin vers test files folder
test_folder="bsq_tester/testfiles/"

# Nombre de caractères minimum pour aligner les outputs
padding=30

# Parcours des inputs
for input in "${inputs[@]}"; do
  # Calculer le nombre de caractères restants pour l'alignement
  input_length=${#input}
  spaces=$((padding - input_length))
  ((total++))
  # Si l'input est plus long que le padding, ne pas réduire les espaces
  if [ $spaces -lt 1 ]; then
    spaces=1
  fi

  # Afficher l'input sans retour à la ligne, puis ajouter des espaces pour aligner
  printf "%s%${spaces}s" "$input" ""

  # Exécuter valgrind sur le programme avec l'input
  valgrind_output=$(eval valgrind --leak-check=full --track-origins=yes --max-stackframe=4000064 $program "$input" 2>&1)

  # Grep pour trouver les adresses mémoire (0x...)
  if echo "$valgrind_output" | grep -q "0x"; then
    echo "Memory issues detected"
    echo "$valgrind_output" | grep "0x"
  else
    # Ajouter "✅ no leaks, no error" sur la même ligne, aligné
    echo "✅ no leaks, no error"
	((passed++))
  fi

#   echo "----------------------------------------"
done

echo ""
echo "$passed / $total"

if [ $passed -eq $total ]; then
    exit 0
else
    exit 1
fi