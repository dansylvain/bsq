#!/bin/bash

echo ""
echo "════════════════════════════════════════"
echo "          OUTPUT VALIDITY CHECK         "
echo "════════════════════════════════════════"
echo ""

total=0  # Remplace par le nombre réel de tests dans ce script
passed=0 # Remplace par le nombre réel de tests réussis

perl_script="scripts/my_perl.pl"

# Nombre de maps à générer
num_maps=7

# Chemin vers le répertoire de testfiles
testfiles_dir="bsq_tester/testfiles/"

# Chemin vers ton programme rush-02 (exécutable testé)
program="./bsq"

# Chemin vers l'exécutable étalon
reference_program="bsq_tester/scripts/bsq"  # Change ce chemin selon la localisation de ton exécutable étalon

# Nombre de caractères minimum pour aligner les outputs
padding=30

# Boucle pour générer les maps et exécuter les programmes
for i in $(seq 1 $num_maps); do
    # Générer un nom de fichier unique pour chaque map
    map_file="${testfiles_dir}script_test_file_${i}"
	((total++))
    # Générer la map avec le script Perl
    perl $perl_script 10 10 4 > "$map_file"

    # Exécuter l'exécutable étalon avec le fichier généré et capturer la sortie
    expected_output=$($reference_program "$map_file")

    # Exécuter l'exécutable testé avec le même fichier généré et capturer la sortie
    output=$($program "$map_file")

    # Comparaison des sorties
    if [ "$output" == "$expected_output" ]; then
		((passed++))
        # Calculer l'espace nécessaire pour aligner l'icône
        printf "%-30s" "script_test_file_${i}"
        echo "✅ no difference found"
    else
        echo "Difference found for script_test_file_${i}"
        echo "Expected output:"
        echo "$expected_output"
        echo "Actual output:"
        echo "$output"
    fi

done

echo ""
echo "$passed / $total"

if [ $passed -eq $total ]; then
    exit 0
else
    exit 1
fi