find . -type f -iname "*.sh" | rev | cut -f 2- -d '.' | cut -f 1 -d '/' | rev
