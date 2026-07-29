*This project has been created as part of the 42 curriculum by kullatid.*

# push_swap

## Description

`push_swap` is a C program that sorts a stack of unique integers in
ascending order by printing a sequence of permitted stack operations.

The program begins with all values in Stack A and an empty Stack B.
When the instructions finish, Stack A must be sorted with the smallest
value at the top, and Stack B must be empty.

The project focuses on stack operations, linked lists, sorting algorithms,
error handling, memory management, and algorithmic complexity.


Algorithm : 
The program stores each stack as a non-circular doubly linked list.
Each input value is assigned a rank from 0 to n - 1. Sorting these ranks is equivalent to sorting the original values while avoiding complications from negative numbers and large gaps between values.
For two to five values, the program uses dedicated small-sorting routines. For more than five values, it uses Binary LSD Radix Sort. Starting from the
least significant bit, nodes whose current bit is zero are pushed to Stack B, while nodes whose bit is one are rotated in Stack A. All nodes in Stack B are then pushed back to Stack A before processing the next bit. Index assignment has O(n²) time complexity in this implementation. The radix sorting stage has O(n log n) time complexity.

Resources : 
Resources used while studying and developing this project included:
The official 42 push_swap subject C manual pages for write, malloc, free, and exit References about doubly linked lists References about binary numbers and bitwise operators References about Binary LSD Radix Sort AI tools were used to help explain unfamiliar concepts, review edge cases, design automated tests, identify possible pointer and memory errors, and prepare study material. Generated suggestions were reviewed, compiled, tested, and corrected before being used in the project.

## Instructions

Compile the program:

```bash
make

test
./push_swap "5 2 4 1 3"
./push_swap 5 2 4 1 3

## Final Gate 

```bash
make fclean
make
make
norminette include src
