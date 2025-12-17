*This project has been created as part of the 42 curriculum by ayafit*

# A brief overview of ft_printf:

![A meme of popular Marvel character Thanos' iconic line; a fun homage to the nature of printf being multiple applications of the write() function.](https://media.tenor.com/QMpojwxgbc4AAAAe/now-reality-can-be-whatever-i-want.png)

#### ***Now, `write()` can be whatever I want.***

All jokes aside, ft_printf is a reimplementation of the versatile and ever so popular `printf()` with a few twists.

This project serves as a nice introduction to variadic functions, while also providing good programming fundamentals by having us handle the following conversions:

- `%c`: This conversion prints a single character.
- `%s`: This conversion prints a string (a chain of characters stored in an array of the `char` data type).
- `%u`: This conversion prints an unsigned decimal number in base 10; in other words it prints out numbers between 0 and 4,294,967,295.
- `%i %d`: These two conversions print out an integer in base 10 or a decimal number in base 10 respectively; they've been put in the same category as they have the same output in `printf()` (they're different in `scanf()` though!).
- `%x %X`: These two conversions print out a number in base 16 lowercase format or a number in base 16 uppercase format respectively.
- `%%`: This conversion prints a percent sign.

## General instructions:

*For evaluators: Don't forget to check norminette :D*

A file named "test_main.c" will be provided with ample edge cases for testing purposes. Please archive the static library "libftprintf.a" using the command `make` and then compile using the command `cc test_main.c libftprintf.a`

## Resources used:

I've used dozens of resources while putting together the project.
Most notably:

- *Variadic Functions in C by GeeksforGeeks*
    This is a basic introduction to variadic functions in C; it gives an overview regarding `<stdarg.h>` and its uses in addition to our first look at the `va_list` data type.

- *Unlocking the Mystery of va_list: Understanding Variable Arguments in C by my peer Abdelhalim Elbouaami*
    This article on the other hand is a much more in-depth guide to how a variadic function works under the hood. It contains information about the structure of `va_list` and how it works on a lower level. It's a goldmine of well-structured information for any aspiring programmer and I recommend giving it a read.

- *No AI was used in this project.*

### Technical choices and considerations:

The base project itself is quite simple; it basically boils down to string manipulation and correct implementations which will be discussed down below.

1. The first thing to do when reimplementing a C function is understanding what it inputs as well as what it returns.
    * In `printf()`'s case it *inputs a string (`const char *restrict format`)* and displays its ordinary characters and the subsequent arguments according to the conversion modifiers used and returns *the number of bytes printed (excluding the null byte used to end output to strings)*.

2. Now that we understand the input, output, and return value of `printf()` we can start our implementation of the function.
    * The backbone of this project is the system call `write()`, thanks to it covering 2 essential parts of our `ft_printf()` function; namely *output* and *return value*.

3. With all that in mind we can start splitting up our `ft_printf()` into a few different functions:
    - `ft_putchar()` for `%c` and `%%`: This is quite self explanatory; it's a write wrap. It outputs a character into *`stdout`* and returns 1.
        - The reason why I used `ft_putchar()` is simply convenience, it allows me to comfortably use write in *iteration* or *recursion* (which will come in handy later).
        - In the case of `%%` we only need to output the character '%' therefore `ft_putchar()` is practical.

    - `ft_putstr()` for `%s`: An iterative use of `ft_putchar()` to print out a string (defined as a chain of characters stored in an array of type `char`). The most prominent edgecase is if the string is `NULL`; we output `(null)` in that case by using recursion.

    - `ft_putnbr()` for both `%d` and `%i`: As mentioned earlier, these conversion modifiers practically do the same thing when it comes to `printf()` so no need to handle both seperately. The function itself uses a recursive algorithm as it's the simplest solution when not using memory allocation. Otherwise `libft`'s outputting `ft_itoa()`'s returned string using `ft_putstr()` is also a viable solution.

    - `ft_putnbr_unsigned()` for `%u`: Same algorithm used by `ft_putnbr()` but due to the `unsigned int`'s viable values being between 0 and 4,294,967,295 there's no need to handle negative numbers. So we only use the recursive algorithm of converting an integer to a character by outputing the sum of the integer and 48 (the character '0') using `ft_putchar()`.

    - `ft_puthex_low()` and `ft_puthex_high()` for `%x` and `%X` respectively: When it comes to converting a number from a given base to another one, the mathematical formula is to divide the number by the base and keep the *remainder* which we use as a key of sorts; for example let's say we want to convert the number 59 to hexadecimal:
        - we'll first divide it by 16 by using the following expression: *59 = 3 * 16 + 11*, next we store the remainder (11 in this case) and divide the quotient (3 in this case) by 16 again resulting in the expression: *3 = 0 * 16 + 3* now that the next quotient is zero we stop the process.
        - We all know that the hexadecimal system uses the symbols: **0123456789ABCDEF**; therefore we use the remainder as an index for which symbol to use: if the remainder < 10 then we leave it as is, otherwise we convert it to the appropriate character.
        - In this case 11 is 'B' while 3 remains as is, keep in mind the final result is attained by reading the remainders in reverse, producing in the hexadecimal number 3B.
            - Now to apply this in code we just use a function to print a character array in reverse `ft_revputstr()` by utilizing `ft_putchar()` and the stack allocated array `res[8]`. The only difference between the two functions being the given base (in hindsight taking the base as a parameter would've been more practical).
    
    - `ft_putpointer()` for `%p`: The key insight to this functions is to realize that a pointer is the same size as an unsigned long in both x32 and x64 architecture (With the exception of Windows 64-bit systems which typically have its size be 4 bytes). Using this information we can do a type casting of the void pointer `void *p` to an unsigned long and use the helper function `ft_puthex()` on it using the same logic from `ft_puthex_low()` and `ft_puthex_high()`.

    - Finally `ft_printf()` itself. We must first have a function to handle the conversion modifiers for us, we use `format_conversion()` in this case which will check for a '%' character in our `const char *format` string and the character that follows it after, depending on the character that follows it will either use one of the functions mentioned above (if the conversion modifier is included in it) , return -1 to indicate an error (a conversion modifier that isn't coded in) or return 0 to indicate an ordinary character.
        - We use `va_list` in `format_conversion()` to make sure that we're grabbing the correct parameter and to tell the function what data type to expect, since we'll be using it in a while loop.
        - `ft_printf()` itself just uses a while loop to check what `format_conversion()` returns and outputs accordingly. In the end it will return the number of bytes written.
        - Overall: `ft_printf()` is a fun little project that really teaches you how to hande strings, and adds one more tool to you arsenal of knowledge: variadic functions, reinforces string manipulation and building a logical chain with correct implementations.
