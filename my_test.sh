#!/bin/bash

# Liste des commandes Perl pour générer des maps
perl_commands=(
    "perl perl_script.pl 10 10 4 > new_map_file_1"
    "perl perl_script.pl 10 10 4 > new_map_file_1"
    "perl perl_script.pl 10 10 4 > new_map_file_1"
    "perl perl_script.pl 10 10 4 > new_map_file_1"
    "perl perl_script.pl 10 10 4 > new_map_file_1"
    "perl perl_script.pl 10 10 4 > new_map_file_1"
    "perl perl_script.pl 10 10 4 > new_map_file_1"
)

# Chemin vers ton programme rush-02
program="./bsq"

# Boucle pour générer les maps et exécuter rush-02
for cmd in "${perl_commands[@]}"; do
    echo "Executing: $cmd"
    
    # Générer la map avec la commande Perl
    eval $cmd

    # Récupérer le nom du fichier généré (par ex. new_map_file_1)
    map_file=$(echo $cmd | awk '{print $NF}')

    # Exécuter rush-02 avec le fichier généré
    echo "Running $program with map file: $map_file"
    $program $map_file

    echo "----------------------------------------"
done
