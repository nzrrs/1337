#!/bin/sh
set -u

make >/dev/null || exit 1

pass=0
fail=0

check_error()
{
    file="$1"
    output=$(./bsq "$file")
    if [ "$output" = "map error" ]; then
        echo "PASS error: $file"
        pass=$((pass + 1))
    else
        echo "FAIL error: $file"
        printf 'got:\n%s\n' "$output"
        fail=$((fail + 1))
    fi
}

check_valid()
{
    file="$1"
    if ./bsq "$file" | grep -q 'map error'; then
        echo "FAIL valid: $file"
        fail=$((fail + 1))
    else
        echo "PASS valid: $file"
        pass=$((pass + 1))
    fi
}

for file in maps/map1 maps/map2 maps/one_empty maps/one_obstacle \
    maps/all_empty maps/all_obstacles maps/tie_top_left maps/one_row \
    maps/one_column
 do
    check_valid "$file"
 done

for file in maps/invalid_empty maps/invalid_zero_rows \
    maps/invalid_duplicate_symbols maps/invalid_wrong_rows \
    maps/invalid_bad_character maps/invalid_unequal_width \
    maps/invalid_empty_line maps/invalid_missing_newline
 do
    check_error "$file"
 done

stdin_output=$(./bsq < maps/one_empty)
if [ "$stdin_output" = "x" ]; then
    echo "PASS stdin"
    pass=$((pass + 1))
else
    echo "FAIL stdin"
    fail=$((fail + 1))
fi

multi_output=$(./bsq maps/one_empty maps/one_obstacle)
expected='x

o'
if [ "$multi_output" = "$expected" ]; then
    echo "PASS multiple files"
    pass=$((pass + 1))
else
    echo "FAIL multiple files"
    fail=$((fail + 1))
fi

printf '\nPassed: %d\nFailed: %d\n' "$pass" "$fail"
[ "$fail" -eq 0 ]
