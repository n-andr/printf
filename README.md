# Print_f

Print_f is a project assigned as part of the curriculum at 42 school. The goal of this project is to implement a simplified version of the standard C library function `printf`.

## Overview

The `printf` function in C is used to print formatted output. It allows you to specify the format of the output using format specifiers such as `%d`, `%s`, `%c`, etc., and then replace those specifiers with the corresponding values.

In the Print_f project, you will implement a basic version of the `printf` function that supports a subset of format specifiers and flags.

## Getting Started

To get started with the Print_f project, follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/yourusername/Print_f.git
```

## Supported Format Specifiers

The Print_f project supports the following format specifiers:

- %c: Character
- %s: String
- %d: Integer (decimal)
- %i: Integer (signed)
- %u: Unsigned integer
- %x: Hexadecimal (lowercase)
- %X: Hexadecimal (uppercase)

## Usage

To use the Print_f function in your C program, include the Print_f.h header file and call the Print_f function with the desired format string and arguments.
```bash
#include "ft_printf.h"

int main() {
    ft_print_f("Hello, %s!\n", "world");
    ft_print_f("The value of x is %d\n", x);
    return 0;
}
```
