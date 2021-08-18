# Main
The examples and my answers for
"The C Programming Language (2º ED)"
by Brian W. Kernighan &amp; Dennis M. Ritchie.

Mi intención, además hacer los ejercicios, es conocer en la práctica el uso de doxygen y CuTest.
En este sentido todo el código, incluido los test, están documentados y he creado páginas adicionales para facilitar la navegación en la documentación.

Mientras que en los ejercicios el uso de las instruccions está limitado a lo que se va aprendiendo en cada capítulo, en los test he usado todo lo que ya sabia.

\note My native language is spanish, Sorry for the strange expressions and the output of some programs (I would reinstall all system in english but I don't feel like it)

### Compilations
all programs are proved on Windows 10 native, WSL2 (Ubuntu) on Windows 10 and Ubuntu.<br>
The compilers used are:
* Windows 10 Native: MSVC (MicroSoft Visual C++)
* WSL2: gcc
* Ubuntu: gcc 

### Running on Windows 10
Each experiment was compiled with Microsoft Visual C++ (MSVC) Versión 19.29.30038.1 for x86.<br>
Init folder is the project root.
\code{.psh}
  cd .\book\chapter_1\section_1.01\exercise_1-1\experiments\exp_1\src
  cl .\helloworld_exp1.c
\endcode

### Running on Linux
Each experiment was compiled with gcc.<br>
Init folder is the project root.
\code{.bash}
  cd ./book/chapter_1/section_1.01/exercise_1-1/experiments/exp_1/src
  gcc ./helloworld_exp1.c
\endcode

### Testing
Each exercise is tested.
The exercises with functions has test for each function.
The exercises that only have a main function are tested comparing the output with expected.

