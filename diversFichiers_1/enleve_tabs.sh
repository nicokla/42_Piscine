#!/bin/bash
#sh coucou.sh 
#*.c      "$@"

shopt -s globstar
liste=$(find . -name "*.c" -not -iwholename "*.git*")
for var in $liste do # Whitespace-safe and recursive
	sed -i -e 's/^	$//g' "$var"
	sed -i -e 's/^		$//g' "$var"
	sed -i -e 's/^			$//g' "$var"
	sed -i -e 's/while(/while (/g' "$var"
	sed -i -e 's/if(/if (/g' "$var"
done
