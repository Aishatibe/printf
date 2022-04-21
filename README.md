# _printf :page_facing_up:

A formatted output conversion C program completed as part of the low-level
programming and algorithm track at ALX . The program is a pseudo-
recreation of the C standard library function, `printf`.

## Dependencies :couple:

The `_printf` function was coded on an Ubuntu 20.04 LTS machine with `gcc` version 4.8.4.

## Usage :running:

To use the `_printf` function, assuming the above dependencies have been installed,
compile all `.c` files in the repository and include the header `main.h` with
any main function.

Example `main.c`:
```
#include "main.h"

int main(void)
{
    _printf("Let's try to printf a simple sentence.");

    return (0);
}
```

Compilation:
```
$ gcc *.c -o tester
```

Output:
```
$ ./tester
Let's try to printf a simple sentence.
$
```
