#!/bin/bash
echo "O meu editor por omissão BASH $BASH \$BASH"
echo 'O meu editor por omissão BASH $BASH \$BASH'
echo $(( 5 + 5 ))
(( 5 > 0 )) && echo "cinco é maior do que zero"
today=$(date); echo $today
ls -dl /etc/
echo
ls -dl /etc/a*
echo
ls -dl /etc/a???*
echo
ls -dl /etc/*conf*
