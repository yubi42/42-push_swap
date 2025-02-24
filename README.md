# Push Swap

## Introduction
**Push Swap** is a **42 School project** that consists of sorting a stack of integers using a limited set of operations and the lowest number of moves possible. The project focuses on implementing efficient sorting algorithms and optimizing performance.

## Features
- Sorting a stack of integers using two stacks (A and B)
- Implemented operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Optimized sorting algorithm for different input sizes
- Error handling for invalid inputs

## Installation

### Prerequisites
- **gcc** (GNU Compiler Collection)
- **Make**

### Build
```sh
# Clone the repository
git clone https://github.com/yubi42/push_swap.git
cd push_swap

# Compile the program
make
```

### Run
```sh
./push_swap <list_of_numbers>
```

### Example
```sh
./push_swap 4 67 3 87 23
```

## Usage with Checker
To validate the sorting algorithm, use the **checker** program:
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Contributors
- [yubi42](https://github.com/yubi42)

