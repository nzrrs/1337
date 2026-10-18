#!/bin/bash
cat /etc/passwd |
grep -v "^#" |
cut -d: -f1 |
awk 'NR % 2 == 0' |
rev |
sort -r |
awk "(NR >= $FT_LINE1) && (NR <= $FT_LINE2)" |
sed 's/$/, /' |
sed '$s/, /./' |
tr -d '\n'
