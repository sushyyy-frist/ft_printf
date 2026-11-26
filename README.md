
*This project has been created as part of the 42 curriculum by sait-ouc.*

# ft_printf

## Description

The `ft_printf` project consists of recreating the behavior of the standard C library's `printf()` function.

The main goal of this project is to understand how formatted output works in C, how variadic functions operate, and how arguments of different types can be handled dynamically.

Unlike a standard function that receives a fixed number of arguments, `ft_printf` uses variadic arguments to accept a variable number of parameters. The format string determines how these arguments are interpreted and displayed.

This project provides a custom implementation of `printf()` using a format string, a parsing mechanism, and dedicated functions to handle different conversion specifiers.

It also introduces important concepts such as:

- Variadic functions and `va_list`.
- Argument retrieval using `va_start`, `va_arg`, and `va_end`.
- Format string parsing.
- Type conversion and formatted output.
- Return value management.
- Modular programming and code organization.

The function returns the total number of characters printed, excluding the terminating null character.

---

## Supported Format Specifiers

The mandatory part of this project supports the following format specifiers:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints an integer in decimal format. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal format. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal format. |
| `%%` | Prints a literal percent sign. |

---

## Instructions

### Compilation

The project uses a Makefile to compile the source files and generate a static library named `libftprintf.a`.

To compile the library, run:

```bash
make
```

The available Makefile rules are:

- `make` or `make all`: Compiles the library.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the library.
- `make re`: Recompiles the project from scratch.

### Usage

To use `ft_printf` in another C project, include the header file:

```c
#include "ft_printf.h"
```

Compile your source file with the generated library:

```bash
cc main.c -L. -lftprintf
```

Make sure that `ft_printf.h` and `libftprintf.a` are accessible to the compiler.

### Example

```c
#include "ft_printf.h"

int main(void)
{
    int result;

    result = ft_printf("Hello %s! Your score is %d.\n", "World", 42);
    ft_printf("Number of characters printed: %d\n", result);
    return (0);
}
```

Output:

```text
Hello World! Your score is 42.
Number of characters printed: 29
```

---

## Algorithm and Data Structure

### 1. Algorithm

The main algorithm of `ft_printf` is based on sequential parsing of the format string.

The format string is traversed character by character from left to right. During this process, the program distinguishes between regular characters and format specifiers.

When a regular character is encountered, it is printed directly and the character counter is incremented.

When a `%` character is encountered, the program examines the following character to identify the corresponding format specifier. It then retrieves the appropriate argument using `va_arg` and calls the dedicated function responsible for handling that conversion.

The process continues until the end of the format string is reached.

The general algorithm can be summarized as follows:

1. Initialize the variadic argument list using `va_start`.
2. Initialize the character counter.
3. Traverse the format string character by character.
4. If the current character is not `%`, print it directly and increment the counter.
5. If `%` is encountered, identify the following format specifier.
6. Retrieve the corresponding argument using `va_arg`.
7. Call the appropriate conversion function.
8. Update the character counter according to the number of characters printed.
9. Continue parsing until the end of the format string.
10. End the variadic argument list using `va_end`.
11. Return the total number of characters printed.

This approach allows the function to process the format string dynamically without requiring the entire output to be constructed in advance.

### 2. Data Structure

The implementation mainly relies on a few basic data types and the variadic argument mechanism rather than complex data structures.

| Element | Role |
|---------|------|
| `char *format` | Points to the format string that is parsed character by character. |
| `va_list` | Provides access to the variable arguments passed to the function. |
| `int` counter | Tracks the total number of characters printed. |
| `char` | Represents the current character or format specifier being processed. |

The `va_list` structure is used to manage the variadic arguments. It allows the program to retrieve each argument in the correct order and with the appropriate type according to the format specifier.

The character counter is used to keep track of the output length, which is necessary because `printf()` returns the number of characters printed.

No complex data structure is required because the processing is sequential. Each character or conversion is handled immediately when it is encountered, and the variadic arguments are consumed in order.

### 3. Justification of the Algorithm and Data Structure

A sequential parsing algorithm was chosen because the format string naturally defines the order in which the output must be produced.

Processing the string from left to right makes it possible to distinguish regular characters from conversion specifiers while maintaining a simple and predictable execution flow.

Each conversion is handled by a dedicated function. This modular approach separates the logic of parsing from the logic of displaying each data type. It also makes the implementation easier to understand, test, debug, and maintain.

The use of `va_list` is essential because the function accepts a variable number of arguments. Instead of storing all arguments in an additional array or structure, they are retrieved when needed, according to the format string.

The character counter is maintained during execution rather than calculating the output length afterward. This makes it possible to return the number of characters printed directly at the end of the function.

This design avoids unnecessary intermediate storage and keeps the implementation simple, efficient, and adapted to the behavior of `printf()`.

---

## Resources

### Documentation and References

The following resources were used to understand the behavior of `printf()`, variadic functions, argument handling, and the C language:

- [printf — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)  
  Reference for the behavior of `printf()`, conversion specifiers, and formatted output.

- [stdarg.h — C documentation](https://en.cppreference.com/w/c/variadic.html)  
  Documentation about variadic functions and the use of `va_list`, `va_start`, `va_arg`, and `va_end`.

- [The GNU C Library documentation](https://www.gnu.org/software/libc/manual/)  
  Reference for C library functions and their behavior.

- [The C Programming Language — cppreference](https://en.cppreference.com/w/c)  
  General reference for C language concepts, types, functions, and syntax.

- [System V AMD64 ABI](https://gitlab.com/x86-psABIs/x86-64-ABI)  
  Reference for understanding function calling conventions, argument passing, registers, and stack behavior on x86-64 systems.

### AI Usage

AI was used as a learning and support tool throughout the development of this project.

It helped with:

- Understanding the concept of variadic functions and how they work in C.
- Understanding the role of `va_list`, `va_start`, `va_arg`, and `va_end`.
- Exploring how function arguments are passed through registers and the stack according to calling conventions.
- Understanding the relationship between the format string and the arguments retrieved by the function.
- Clarifying the behavior of format specifiers and identifying possible edge cases.
- Developing test cases and analyzing unexpected results.
- Understanding debugging errors and improving the reasoning behind the implementation.

AI was mainly used for explanations, conceptual clarification, debugging assistance, and learning support. The implementation was developed, tested, reviewed, and adapted as part of the learning process.

---

## Testing

The project was tested using different combinations of format specifiers, argument types, and output scenarios.

Tests include:

- Printing regular characters without format specifiers.
- Printing individual characters using `%c`.
- Printing strings using `%s`.
- Printing pointer addresses using `%p`.
- Printing signed integers using `%d` and `%i`.
- Printing unsigned integers using `%u`.
- Printing hexadecimal values using `%x` and `%X`.
- Printing literal percent signs using `%%`.
- Mixing multiple format specifiers in a single format string.
- Checking the returned number of characters.
- Testing zero, negative values, and boundary cases where applicable.

Comparisons with the original `printf()` function were also used to verify the output and return values for supported cases.

---

## Author

**sait-ouc**  
42 Student
