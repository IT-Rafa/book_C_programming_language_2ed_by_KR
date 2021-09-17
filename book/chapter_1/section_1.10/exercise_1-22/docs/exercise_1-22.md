@page Exercise_1-22 Exercise 1-22
Page 34
 
---

## Sentence
Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specific column.

---

## Answer
I´m no sure about the sentence.
if n = 5, and columns init with 1
1234567890 -> columns
12 3456
the nth column contains the number 4, and the last non-blank character before it is 3
If we make the division after it, the output will be:
12 3
456

I think it's not the expected.
It seems me better make the division after the last blank before the n-th column (pos 3 in example)
12 
3456

Anyway, I don´t know if output must preserve the blanks between the divided lines and where preserve them, at end of first line or at init of second one.

After test with several inputs, I decided cut the line at the end of first group of blanks before the n-th column, preserving the spaces to make easier rebuild the complete line.


### Source
Source reference: @ref exercise_1-22.c
@include exercise_1-22.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_22_ver_Test(CuTest *tc)
Exercise_1_22_Test1
Begin functions. Now use exercise as example, and test to check only the function.

### Conclusion
