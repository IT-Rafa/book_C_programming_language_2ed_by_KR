@page Exercise_1-24 Exercise 1-24
Page 34
 
---

## Sentence
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. ( This program is hard if you do it full generally.).
---

## Answer
- The quotes no closed in the same line are errors and will stop the read of file, showing the line and column where the error was detected

I supposed that a escape sequence only have sense if it is inside a quotes.
'\n' or "\n" -> are escape sequence
/* \n *\     -> is not a escape sequence
c code outside quotes,
\n           ->   is not a escape sequence

This solution dont't work very well.
If there are two fails, a bad opened and a bad closed, the counter of symbols result in 0, so it don't find any problem.

[] - Brackets or square brackets (Corchete)
<> - Angle brackets (Angulos o menor/mayor que)
() - Parentheses (Paréntesis)
{} - braces (Llaves)

my IDE don´t recognize \ out of quotes
### Source
Source reference: @ref exercise_1-24.c
@include exercise_1-24.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_24_ver_Test(CuTest *tc)
Exercise_1_24_Test1
Begin functions. Now use exercise as example, and test to check only the function.

### Conclusion
