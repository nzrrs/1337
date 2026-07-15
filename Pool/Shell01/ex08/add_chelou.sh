#!/bin/bash

TO="01234"

CONVERTED1=$(echo "$FT_NBR1" | tr "'\\\\\"?!" "$TO")
CONVERTED2=$(echo "$FT_NBR2" | tr "mrdoc" "$TO")

echo "obase=13;ibase=5;$CONVERTED1+$CONVERTED2" | bc | tr "0123456789ABC" "gtaio luSnemf"
