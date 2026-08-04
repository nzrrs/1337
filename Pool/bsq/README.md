# BSQ Project Structure

```text
.
├── include
│   └── bsq.h
├── Makefile
├── map_generator.pl
├── maps
│   ├── map1
│   └── map2
└── src
    ├── fill_square.c
    ├── free.c
    ├── main.c
    ├── output.c
    ├── parser.c
    ├── parser_utils.c
    ├── reader.c
    ├── solver.c
    ├── utils.c
    └── validator.c
```

---

## include/

### `bsq.h`

Contains everything shared between source files.

Responsibilities:

* Struct definitions
* Function prototypes
* Required includes
* Macros/constants (if needed)

---

## Makefile

Responsibilities:

* Build the `bsq` executable.
* Compile all source files.
* Provide at least:

  * `all`
  * `clean`
  * `fclean`
  * `re`

---

## map_generator.pl

Testing tool provided by the subject.

Responsibilities:

* Generate random valid maps.
* Not part of the final program logic.

---

## maps/

Contains test maps only.

Examples:

* Small maps
* Large maps
* Random maps
* Invalid maps

Used while developing and debugging.

---

## src/

### `main.c`

Program entry point.

Responsibilities:

* Handle command-line arguments.
* Decide whether to read from files or stdin.
* Process every map independently.
* Coordinate the program flow.

---

### `reader.c`

Reads raw input.

Responsibilities:

* Open files.
* Read from stdin when no arguments are given.
* Store file contents in memory.
* Handle read errors.

Should not validate the map.

---

### `parser.c`

Parses the input.

Responsibilities:

* Parse the first line.
* Extract:

  * number of rows
  * empty character
  * obstacle character
  * fill character
* Build the in-memory representation of the map.

---

### `parser_utils.c`

Small helper functions used by the parser.

Examples:

* Character checks
* Number parsing
* Header parsing helpers
* String helpers specific to parsing

---

### `validator.c`

Verifies that the parsed map is valid.

Checks:

* Valid header.
* Three different symbols.
* Correct number of rows.
* Same number of columns everywhere.
* Only valid characters.
* No malformed input.

---

### `solver.c`

Core BSQ algorithm.

Responsibilities:

* Search for the largest possible square.
* Resolve ties according to the subject.
* Store:

  * square size
  * top-left position (or equivalent)

This is the heart of the project.

---

### `fill_square.c`

Applies the solution.

Responsibilities:

* Replace every cell inside the chosen square with the fill character.

Does not search for the square.

---

### `output.c`

Produces program output.

Responsibilities:

* Print the solved map.
* Print `map error` when required.
* Handle formatting between multiple files.

---

### `utils.c`

General helper functions.

Examples:

* String length
* Character tests
* Memory helpers
* Small reusable utilities

Avoid placing parser- or solver-specific logic here.

---

### `free.c`

Memory cleanup.

Responsibilities:

* Free allocated arrays.
* Free map structures.
* Prevent memory leaks.

---
