@page Exercise_1-9 Exercise 1-9
Page 17
 
---

## Sentence
Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blanck.

---

## Answer
This program will read data input (stdin). if nothing is expecified when program is called (using pipes or other especific system ways), stdin is empty, so the system will give control to system terminal, and it will wait for the user write something and send the signal to finish the input ([CTRL-D] , in Linux-Bash), ([ctrl+z]+[RETURN], in Windows with psh or bash).


Source reference: @ref exercise_1-9.c
@include exercise_1-9.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_9_Test(CuTest *tc) for empty input


### Conclusion
