@page Exercise_1-10 Exercise 1-10
Page 17
 
---

## Sentence
Exercise 1-10. Write a program to copy its input to its output, replacing
each tab with \t, each backspace by \b, and each backlash by \\.
This make tabs and backspaces visible in a unambiguous way.

---

## Answer
This program will read data input (stdin). if nothing is expecified when program is called (using pipes or other especific system ways), stdin is empty, so the system will give control to system terminal, and it will wait for the user write something and send the signal to finish the input (ctrd + d, in Linxu-Bash), (ctrl + z, in Windows with psh or bash).


Source reference: @ref exercise_1-10.c
@include exercise_1-10.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_10_Test(CuTest *tc) for empty input


### Conclusion
