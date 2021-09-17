@page Exercise_1-16 Exercise 1-16
Page 30
 
---

## Sentence
Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.
---

## Answer
the original function name, getline, was changed becouse the standard library have a function with this name 
Instructions added in main function to check the value of char before '\0' is '\n'.
This check fail if last line in input isn't finished with end-of-line char.

### Source
Source reference: @ref exercise_1-16.c
@include exercise_1-16.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_16_ver_Test(CuTest *tc)
Exercise_1_16_Test1
Begin functions. Now use exercise as example, and test to check only the function.

### Conclusion
