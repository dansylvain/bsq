#!/bin/bash

path="bsq_tester/scripts/"
# Exécuter la norminette et capturer les erreurs
"${path}norminette_test.sh"
norminette_status=$?  # Capturer le code de retour

Exécuter les autres scripts
"${path}./memo_check.sh"
memo_status=$?  # Capturer le code de retour

"${path}./multi_map_test.sh"
multi_map_status=$?  # Capturer le code de retour

"${path}./parsing_test.sh"
parsing_status=$?  # Capturer le code de retour

echo ""
echo "════════════════════════════════════════"
# Vérifier si tous les tests ont réussi
if [[ $norminette_status -eq 0 && $memo_status -eq 0 && $multi_map_status -eq 0 && $parsing_status -eq 0 ]]; then
	echo " 🎉            ! well done !         🎉 "
else
	echo " 😵               ! KO !             😵 "
fi

echo "════════════════════════════════════════"
echo ""
# Optionnel : retourner un code d'erreur global
if [[ $norminette_status -ne 0 || $memo_status -ne 0 || $multi_map_status -ne 0 || $parsing_status -ne 0 ]]; then
    exit 1
else
    exit 0
fi
