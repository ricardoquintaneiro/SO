#!/bin/bash
# This script checks the existence of a file
echo "Checking..."
if [[ -f $1 ]] ; then
	echo "$1 existe."
	if [[ -d $1 ]] ; then
		echo "	é uma diretoria."
	fi
	if [[ -r $1 ]] ; then
		echo "	tem permissões de leitura."
	fi
	if [[ -w $1 ]] ; then
		echo "	tem permissões de escrita."
	fi
	if [[ -x $1 ]] ; then
		echo "	tem permissões de execução."
	fi
else
	echo "$1 não existe"
fi
echo "...done."
