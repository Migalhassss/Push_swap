# Push_swap

## Overview

`Push_swap` is a custom implementation of algorithms for sorting data using two stacks: Stack A and Stack B. This project is designed to help you understand and implement sorting algorithms, particularly those used in push and swap operations for stack data structures.

This repository contains the source code for the `push_swap` program, along with usage instructions and a brief overview of its features.

## Table of Contents

- [Features](#features)
- [Introduction](#introduction)
- [Usage](#usage)
- [Building and Running Push_swap](#building-and-running-push_swap)
- [Example Usage](#example-usage)
- [Acknowledgments](#acknowledgments)
- [Suppport](#support)

## Features

- Implements sorting algorithms using two stacks.
- Provides a simple but educational example of stack-based sorting.
- Compatible with Unix-like systems (Linux, macOS).

## Introduction

- **`sa`** : **swap a** - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
- **`sb`** : **swap b** - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
- **`ss`** : **`sa`** and **`sb`** at the same time.
- **`pa`** : **push a** - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.
- **`pb`** : **push b** - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- **`ra`** : **rotate a** - shift up all elements of stack A by 1. The first element becomes the last one.
- **`rb`** : **rotate b** - shift up all elements of stack B by 1. The first element becomes the last one.
- **`rr`** : **`ra`** and **`rb`** at the same time.
- **`rra`** : **reverse rotate a** - shift down all elements of stack A by 1. The last element becomes the first one.
- **`rrb`** : **reverse rotate b** - shift down all elements of stack B by 1. The last element becomes the first one.
- **`rrr`** : **`rra`** and **`rrb`** at the same time.

The grade depends on how efficient the program's sorting process is.
 
- Sorting 3 values: no more than 3 actions.
- Sorting 5 values: no more than 12 actions.
- Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  - 5 points for less than 700 actions
  - 4 points for less than 900
  - 3 points for less than 1100
  - 2 points for less than 1300
  - 1 point for less than 1500
- Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  - 5 points for less than 5500 actions
  - 4 points for less than 7000
  - 3 points for less than 8500
  - 2 points for less than 10000
  - 1 point for less than 11500


## Usage

### Building and Running Push_swap

1. Clone this repository or download the source code.

2. Open a terminal and navigate to the project's root directory.

3. Use the provided Makefile to build the `push_swap` program. You can choose different compilation options by specifying the target in the Makefile.

    - To build the program with default settings:

        ```bash
        make
        ```
        
    - To clean up object files and executables:

        ```bash
        make clean
        ```

4. Run the compiled `push_swap` program:

    ```bash
    ./push_swap arg1 arg2 arg3 ...
    ```

    - `arg1`, `arg2`, `arg3`, ...: List of integers to be sorted.

### Example Usage

Here's an example of how to use `push_swap` to sort a list of integers:

```bash
./push_swap 4 2 7 1 5
```
This command will sort the list [4, 2, 7, 1, 5] using the implemented sorting algorithms.

## Acknowledgments

This project was inspired by the need for a simple, educational example of stack-based sorting algorithms in C. It is meant to serve as a starting point for those interested in learning about sorting and stack manipulation.

## Support 

If you have any questions, encounter issues, or need assistance with the libft project, please feel free to open an issue on GitHub. Im here to help and improve the library together
