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
echo "Introduza o primeiro número: "
read
arg1=$REPLY
echo "Introduza o segundo número: "
read
arg2=$REPLY

comparar_numeros $arg1 $arg2
teste=$?

if ((teste == 1)); then
	echo "Os números são iguais"
elif ((teste == 0)); then
	echo "$arg1 é maior"
else
	echo "$arg2 é maior"
fi
}
