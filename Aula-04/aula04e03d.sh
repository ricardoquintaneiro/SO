#!/bin/bash

declare -A numArray

input="$1"

i=0
while IFS= read -r line
do
  numArray+=([$i]=$line)
  i+=1
done < "$input"

echo ${numArray[@]}

# falta ordenar o array
