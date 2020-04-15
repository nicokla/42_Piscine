#!/bin/bash
#shopt -s globstar

liste=$(find . -name "*.c" -not -iwholename "*.git*")

for var in $liste; do # Whitespace-safe and recursive
	echo "$var"
	cat "$var" | tail -4
	echo ""
done


