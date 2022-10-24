#!/bin/bash
#This script does a very simple test for checking disk space.
case $1 in
	([1-9]|[1-8][0-9]|[9][0-8])
	case $2 in
		(sec)
		Message="Argumentos OK."
		;;
		(*)
		Message="Segundo argumento inválido."
		;;
	esac
	;;
	* )
	case $2 in
		(sec)
		Message="Primeiro argumento inválido."
		;;
		(*)
		Message="ARGUMENTOS INVÁLIDOS."
		;;
	esac
	;;
esac
echo $Message
