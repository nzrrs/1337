#!/bin/bash
FT_LINE1=7
FT_LINE2=15
cut -d: -f1 /etc/passwd | awk 'NR % 2 == 0' | rev | sort -r| awk "(NR >= $FT_LINE1) && (NR <= $FT_LINE2)" |sed 's/$/, /g'|sed '$s/, /./g'| tr -d '\n'
