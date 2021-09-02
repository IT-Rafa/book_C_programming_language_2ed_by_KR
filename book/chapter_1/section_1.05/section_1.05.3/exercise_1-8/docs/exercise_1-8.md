@page Exercise_1-8 Exercise 1-8
Page 17
 
---

## Sentence
Exercise 1-8. Write a program to count blanks, tabs, and newlines.

---

## Answer
This program will read data input (stdin). if nothing is expecified when program is called (using pipes or other especific system ways), stdin is empty, so the system will give control to system terminal, and it will wait for the user write something and send the signal to finish the input (ctrd + d, in Linxu-Bash), (ctrl + z, in Windows with psh or bash).


Source reference: @ref exercise_1-8.c
@include exercise_1-8.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_8_Test1(CuTest *tc) for empty input\n
Test source: @ref Exercise_1_8_Test2(CuTest *tc) for input with (blanks: 25; tabs: 3; newlines: 3)

### Conclusion
