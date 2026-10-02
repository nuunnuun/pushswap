*This project has been created as part of the 42 curriculum by Kullatida.*

# push_swap

## Overview

My implementation of `push_swap` for 42 Bangkok. The program sorts unique
integers using two stacks and a limited set of operations. It prints the
instructions needed to sort Stack A in ascending order, with the smallest
value at the top and Stack B empty.

## Features

- Accepts separate arguments or numbers inside a quoted argument.
- Rejects duplicate values, invalid numbers, empty arguments, and values
  outside the signed `int` range.
- Prints `Error` to standard error when input is invalid.
- Prints no instructions when no arguments are given or the input is already sorted.
- Implements `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

## Concepts & Algorithm

Both stacks use non-circular doubly linked lists. Each node stores its
original value, an index, and pointers to the previous and next nodes.

Before sorting, each value receives an index from `0` to `n - 1` based on
its rank. This lets the algorithm sort negative and positive values using
non-negative indexes without changing the original numbers.

- **2–3 values:** dedicated routines using swaps and rotations.
- **4–5 values:** move the smallest values to Stack B, sort the remaining
  three values, then push the saved values back to Stack A.
- **More than 5 values:** Binary LSD Radix Sort, processing indexes from
  the least significant bit upward. A zero bit triggers `pb`; a one bit
  triggers `ra`. After each pass, `pa` returns all values to Stack A.

Index assignment takes O(n²) time. The radix sorting stage takes
O(n log n) time, so the overall implementation has O(n²) time complexity.
The stacks use O(n) memory.

## Build

Requires a C compiler and `make`.

```bash
make
```

This creates the `push_swap` executable using `-Wall -Wextra -Werror`.

## Usage

```bash
./push_swap 5 2 4 1 3
./push_swap "5 2 4 1 3"
```

For example, rotating `3 1 2` once produces `1 2 3`:

```bash
./push_swap 3 1 2
# Output: ra
```

To count the instructions for a valid input:

```bash
./push_swap "5 2 4 1 3" | wc -l
```

## Makefile Commands

| Command | Action |
| --- | --- |
| `make` | Build the program |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the executable |
| `make re` | Clean and rebuild |

## Project Status

The stack operations, input validation, small sorting routines, and radix
sort are implemented. No bonus checker is included.

## Resources

- The 42 push_swap subject
- C manual pages for `write`, `malloc`, `free`, and `exit`
- References on doubly linked lists, binary numbers, bitwise operators,
  and Binary LSD Radix Sort

AI tools were used while studying concepts, reviewing edge cases, planning
tests, and preparing documentation. Suggestions were reviewed and tested
before being used.

## Author

Nuun Kullatida — [nuunnuun](https://github.com/nuunnuun)
