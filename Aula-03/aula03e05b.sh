#!/bin/bash
# For all the files in a folder, show their properties
if (( $# != 1 )); then
    >&2 echo "Illegal number of parameters"
elif [[ -d $1 ]]; then
	for f in $1/*; do
		file "$f"
	done
else
    >&2 echo "Not a directory."
fi
