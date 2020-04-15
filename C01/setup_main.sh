#!/bin/zsh

# How to use
# cp ~/Desktop/setup_main.sh setup_main.sh
# sh ./setup_main.sh

# aliases (norminette -R ... ---> normi)
shopt -s expand_aliases

# copy files
cp ~/Desktop/makeheaders makeheaders
cp ~/Desktop/gitignore .gitignore
cp ~/Desktop/main.c main.c~
cp ~/Desktop/enleve_tabs.sh enleve_tabs.sh
cp ~/Desktop/show_fin.sh show_fin.sh

if [ ! -f main.c ]; then
    mv main.c~ main.c

    # make headers -->
    ./makeheaders */*.[ch]

    # reference the headers in main.c
    find . -not -iwholename "*.git*" -not -iwholename "*main.c" -name "*.c" | cut -c 3- | sed 's/\.c/\.h/g' | awk '{print "#include \""$1"\""}' | cat - main.c > temp && mv temp main.c
else
    rm main.c~
fi


# test
gcc -Wall -Werror -Wextra main.c -o a.out
./a.out

# norminette
echo "-----------------------\n"
norminette -R CheckForbiddenSourceHeader $(find . -name "*.c" -not -iwholename "*.git*" -not -iwholename "*main.c")
