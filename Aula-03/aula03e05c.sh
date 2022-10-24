#!/bin/bash
for f in $1/*; do
	mv -v $f $1/new_${f##*/}
done
