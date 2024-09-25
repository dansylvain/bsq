#!/bin/bash

perl_script="scripts/my_perl.pl"

# Exécuter ton script de vérification mémoire
./memo_check.sh

# Nombre de maps à générer
num_maps=7

# Chemin vers le répertoire de testfiles
testfiles_dir="bsq_tester/testfiles/"

# Chemin vers ton programme rush-02
program="./bsq"

# Boucle pour générer les maps et exécuter rush-02
for i in $(seq 1 $num_maps); do
    # Générer un nom de fichier unique pour chaque map
    map_file="${testfiles_dir}new_map_file_$i"
    
    # Générer la map avec le script Perl
    perl $perl_script 10 10 4 > "$map_file"

    # Exécuter rush-02 avec le fichier généré
    echo "$program $map_file :"
    $program "$map_file"

    echo "----------------------------------------"
done
