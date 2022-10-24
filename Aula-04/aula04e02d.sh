#!/bin/bash
function comparar_numeros() {
	if [[ "$1" == "$2" ]]; then
		return 1
	elif (($1 > $2)); then
		return 0
	else
		return 2
	fi
}

{

comparar_numeros $1 $2
teste=$?

if ((teste == 1)); then
	echo "Os números são iguais"
elif ((teste == 0)); then
	echo "$1 é maior"
else
	echo "$2 é maior"
fi
}
