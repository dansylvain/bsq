#!/bin/bash

echo ""
echo "════════════════════════════════════════"
echo "          PARSING CONTROL TEST          "
echo "════════════════════════════════════════"
echo ""

# Chemin vers test files folder
test_folder="bsq_tester/testfiles/"

# Liste des inputs à tester
inputs=(
"wrong_file_charset"
"wrong_file_charset_len"
"wrong_file_line_breaks"
"wrong_file_line_len"
"wrong_file_one_box"
)

# Chemin vers ton programme rush-02
program="./bsq"

# Longueur minimale pour l'alignement
padding=40

# Icônes pour succès ou échec
icon_success="✅"
icon_error="❌"

# Parcours des inputs
for input in "${inputs[@]}"; do
    # Exécuter rush-02 avec l'input
    echo -n " ⚠️   "
    output=$($program "$test_folder$input")

    # Afficher l'input testé avec un alignement
	printf "%-${padding}s" "$input"

    # Vérifier si l'output contient une nouvelle ligne (erreur possible)
    if [[ "$output" == *$'\n'* ]]; then
        # Si l'output contient une nouvelle ligne, c'est potentiellement une erreur
        echo "$icon_error error"
        echo "$output"
    else
        # Si l'output tient sur une seule ligne, tout va bien
        echo "$icon_success passed"
        echo "$output"
    fi

    # echo "----------------------------------------"
done
