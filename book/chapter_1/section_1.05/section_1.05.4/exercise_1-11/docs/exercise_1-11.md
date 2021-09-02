@page Exercise_1-11 Exercise 1-11
Page 21
 
---

## Sentence
Exercise 1-11. How would you test the word count program? What kind of input are most likely to uncover bugs if there are any?.

---

## Answer
In this case, the solution is part of the added test.
The source is just a copy of the example of the book in page 20 (@ref wc_book_v1.c).

This program will read data input (stdin). if nothing is expecified when program is called (using pipes or other especific system ways), stdin is empty, so the system will give control to system terminal, and it will wait for the user write something and send the signal to finish the input ([CTRL-D] , in Linux-Bash), ([ctrl+z]+[RETURN], in Windows with psh or bash).


Source reference: @ref exercise_1-11.c
@include exercise_1-11.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_11_Test(CuTest *tc) for empty input


### Conclusion
