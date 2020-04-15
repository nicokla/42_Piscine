cat /etc/passwd | cut -f 1 -d ':' | grep "^[^#;]" | awk 'NR%2==0' | rev | tail -r  | head -n $FT_LINE2  | tail -n +$FT_LINE1  |  awk 1 ORS=', ' | awk '{print substr($0,1,length-2)"."}' | tr -d "\n"
