#!/bin/bash

echo ""
echo "════════════════════════════════════════"
echo "            NORMINETTE TEST             "
echo "════════════════════════════════════════"
echo ""

total=1  # Remplace par le nombre réel de tests dans ce script
passed=0 # Remplace par le nombre réel de tests réussis

norminette_output=$(norminette | grep "Error")

if [ -z "$norminette_output" ]; then
    # Si aucune erreur n'est trouvée
	((passed++))
    echo " Norminette test passed	      ✅"
	echo ""
else
    # Si des erreurs sont trouvées
    echo " Norminette test failed			❌"
    echo "$norminette_output"
fi

echo "$passed / $total"

if [ $passed -eq $total ]; then
    exit 0
else
    exit 1
fi

echo "$passed / $total"

if [ $passed -eq $total ]; then
    exit 1
else
    exit 0
fi