#!/bin/bash

# Chemin vers test files folder
test_folder="bsq_tester/testfiles"

# Liste des inputs à tester
inputs=(
"$test_folder/wrong_file_charset bsq_tester/"
"$test_folder/wrong_file_charset_len bsq_tester/"
"$test_folder/wrong_file_line_breaks bsq_tester/"
"$test_folder/wrong_file_line_len bsq_tester/"
"$test_folder/wrong_file_one_box"
"$test_folder/file_1"
)

# Chemin vers ton programme rush-02
program="./bsq"

# Nombre de caractères minimum pour aligner les outputs
padding=30

# Parcours des inputs
for input in "${inputs[@]}"; do

    # Exécuter rush-02 avec le fichier généré
    echo "$program $input :"
    $program "$input"

    echo "----------------------------------------"
done
