# BSQ

Build:

```sh
make
```

Run with files:

```sh
./bsq maps/map1
./bsq maps/map1 maps/map2
```

Run from standard input:

```sh
./bsq < maps/map1
cat maps/map1 | ./bsq
```

Generate a map:

```sh
./map_generator.pl 50 20 3 > maps/generated
```

Run included tests:

```sh
./tests/run_tests.sh
```
