@page Exercise_1-1 Exercise 1-1
Page 8
 
---

## Sentence
Exercise 1-1. Run the "hello, world" program on your system. Experiment with leaving out parts of the program, to see what errors messages you get.

\note The original "hello, world" program (with comments): @ref helloworld_v1.c

---

## Answer

### Source 
Each experiment had its own source

### Experiment 1: Original source
source file: @ref helloworld_1_1_exp_1.c
@include helloworld_1_1_exp_1.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version, file compiled and generated files.<br>
    - Errors and Warnings: None
  - **Generated files:** .obj and .exe with same name as .c file

### Experiment 2: Del include line
source file: @ref helloworld_1_1_exp_2.c
@include helloworld_1_1_exp_2.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version, file compiled and generated files.<br>
    - Errors and Warnings:
      - helloworld_exp2.obj : error LNK2019: símbolo externo _printf sin resolver al que se hace referencia en la función _main
      - helloworld_exp2.exe : fatal error LNK1120: 1 externos sin resolver
  - **Generated files:** .obj with same name as .c file

### Experiment 3: Del main function header
source file: @ref helloworld_1_1_exp_3.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version, file compiled and generated files.<br>
    - Errors and Warnings:
      - helloworld_exp3.c(19): error C2449: se encontró '{' en el ámbito de archivo (¿falta el encabezado de función?)'
      - helloworld_exp3.c(21): error C2059: error de sintaxis: '}'
  - **Generated files:** None

### Experiment 4: Del main function parenthesis
source file: @ref helloworld_1_1_exp_4.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version and file compiled .<br>
    - Errors and Warnings:
      - helloworld_exp4.c(19): error C2054: se esperaba '(' a continuación de 'main'
  - **Generated files:** None

### Experiment 5: Del printf line
source file: @ref helloworld_1_1_exp_5.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version, file compiled and generated files.<br>
    - Errors and Warnings: None
  - **Generated files:** .obj and .exe with same name as .c file

### Experiment 6: Del printf argument
source file: @ref helloworld_1_1_exp_6.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version and file compiled .<br>
    - Errors and Warnings:
      - helloworld_exp6.c(20): error C2198: 'printf': no hay suficientes argumentos para la llamada
  - **Generated files:** None

### Experiment 7: Del printf parenthesis
source file: @ref helloworld_1_1_exp_7.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version, file compiled and generated files.<br>
    - Errors and Warnings:
      - helloworld_exp7.c(20): warning C4550: la expresión se evalúa como una función a la que le falta una lista de argumentos
  - **Generated files:** .obj and .exe with same name as .c file

### Experiment 8: Del printf semi colon
source file: @ref helloworld_1_1_exp_8.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version, file compiled and generated files.<br>
    - Errors and Warnings:
      - helloworld_exp8.c(21): error C2143: error de sintaxis: falta ';' delante de '}'
  - **Generated files:** None

### Experiment 9: Del block symbols
source file: @ref helloworld_1_1_exp_9.c
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Info about compiler and linker version, file compiled and generated files.<br>
    - Errors and Warnings:
      - helloworld_exp9.c(20): error C2061: error de sintaxis: identificador 'printf'
      - helloworld_exp9.c(20): error C2059: error de sintaxis: ';'
      - helloworld_exp9.c(20): error C2059: error de sintaxis: 'cadena'
  - **Generated files:** None

### Test
Since they are experiments, there isn´t test.

### Conclusion
The behavior is up to the compiler and the options with which it is called.
By default, if compiler detect warnings the executable is generated. If detect errors the source is never compiled.  
In some cases, compiler try to complete the code, for example it will add the library if exist a standard function with same name and arguments.
