@page Exercise_1-2 Exercise 1-2
Page 8
 
---

## Sentence
Exercise 1-2. Experiment to find out what happens when printf's argument string contains \\c, where c is some character not listed above.

\note - The original "hello, world" program (with comments): @ref helloworld_v1.c

\note - "character listed above" might be:<br>
 \code \n, \t, \b, \", \\ \endcode <br> 
 or "complete list in Section 2.3":<br> 
 \code \a, \b, \f, \n, \r, \t, \v, \\, \?, \', \", \ooo (o=octal number), \xhh (h=hexadecimal number)\endcode

---

## Answer

### Source 
Each experiment had its own source

### Experiment 1: ascii letter: \j
source file: @ref helloworld_1_2_exp_1.c
- Linux
    - **Compiler message:** Pending
    - **Output:** Pending
- Windows
    - **Compiler message:** helloworld_1_2_exp_1.c(20): warning C4129: 'j': secuencia de escape de carácter no reconocida
    - **Output:** replace \\j by only letter: j

### Experiment 2: spanish letter, no ascii: \ñ
source file: @ref helloworld_1_2_exp_2.c
- Linux
    - **Compiler message:** Pending\
    - **Output:** Pending
- Windows

    - **Compiler message:** helloworld_1_2_exp_2.c(20): warning C4129: '': secuencia de escape de car
    <em>(message was cut)</em>
    - **Output:** replace \\ñ by visible unknown character:  ├▒

### Experiment 3: number no octal letter: \9
source file: @ref helloworld_1_2_exp_3.c
- Linux
    - **Compiler message:** Pending
    - **Output:** Pending
- Windows
    - **Compiler message:** helloworld_1_2_exp_3.c(20): warning C4129: '9': secuencia de escape de carácter no reconocida
    - **Output:** Pending
    
### Test
Since they are experiments, there isn´t test.

### Conclusion
If the escape sequence is not provided by language, the behavior will be up to the compiler, the command interpreter, what character code is used, etc.
Usually the escape sequence with others ascii characters are converted to one simple character.
