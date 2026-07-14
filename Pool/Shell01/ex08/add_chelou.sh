#!/bin/bash

FROM1="'\\\"?!"
TO="01234"
FROM2="mrdoc"

#convert using translator sets 

CONVERTED1=$(echo "$FT_NBR1" | tr "$FROM1" "$TO")
CONVERTED2=$(echo "$FT_NBR2" | tr "$FROM2" "$TO")

#changing the base of the converted from base 5 to base 10 

CONVERTED1=$(echo "obase=10;ibase=5;"$CONVERTED1" | bc) 
CONVERTED2=$(echo "obase=10;ibase=5;"$CONVERTED2" | bc) 

#changing back to base 5 after calculating sum to replace with tr

SUM=$(CONVERTED1 + CONVERTED2)

echo "obase=13;ibase=13;"SUM"" | bc | tr "0123456789ABC" "gtaio luSnemf"
