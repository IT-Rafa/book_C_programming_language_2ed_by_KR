@page Exercise_1-6 Exercise 1-6
Page 17
 
---

## Sentence
Exercise 1-6. Verify that the expression **getchar() != EOF** is 0 or 1.

---

## Answer
For this exercise we need differents input and, if we execute our program directly, the input will be the standard input what is controlled by the ssoo where we are.
So, the complete process will be:
1. Run the program (only print the result of **getchar() != EOF**)
2. When getchar() is called, the system pass the control to the terminal to get a input.
3. The terminal wait for a input.
  - 3.1 If we use a Linux shell
  - 3.1.1. We write a standard input ( no signal as ctrl +d) and return.
      - 3.1.2. The content is sended to our program, and getchar read the first char of it.
  - 3.1.1. We send signal of EOF (ctrl +d)

  3.1 If we use a Windows terminal (cmd.exe or powershell)
    3.1.1. We write a standard input ( no signal as ctrl+z + return) and return.
         3.1.2. The content is sended to our program, and getchar read the first char of it.
    3.1.1. We send signal of EOF (ctrl+z + return)    
4. Compare the code of this char versus EOF.
 
- Terminal
exe
  - getchar -> terminal
  input -> a + enter -> input to program - program return 1

  input -> a + ctrl+c -> input to program - program return 0

  input -> a + ctrl+z + return -> input to program return 1

Source reference: @ref exercise_1-6.c
@include exercise_1-6.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_6_Test1(CuTest *tc) for empty input
Test source: @ref Exercise_1_6_Test2(CuTest *tc) for with-content input

### Conclusion
