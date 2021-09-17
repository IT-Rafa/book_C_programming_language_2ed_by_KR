@page Exercise_1-20 Exercise 1-20
Page 34
 
---

## Sentence
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

---

## Answer
Since n (tabsize) is a fixed value, it's prefer use a symbolic symbol and avoid create a var. 

Definition of tabstop.
En los editores de texto plan, dependiendo de la configuración, el carácter tab se puede interpretar de distintas formas.
La forma simple, que sería añadir la cantidad de espacios configurada, normalmente 4 u 8.
Esta forma solo evita tener que escribir varios espacios, pero no es muy útil para alinear texto.

Para alinear el texto se suele usar el sistema con tabstops
Cada línea se divide en columnas con la distancia definida por el ancho del caracter tab (4, 8, otros)
Estas columnas son las llamadas tabstops
Mostramos una línea con las columnas representadas con |
|	|	|	|	|	| ...
Cada vez que pulsamos tab, el siguiente carácter se alineará al siguiente tabstop, es decir usará la cantidad de espacios que necesite para llegar a la posición del tabstop.
Esto afecta a la forma en la que el editor muestra los caracteres tab, pero no afecta a los caracteres almacenados realmente en el texto, de la misma manera que un salto de línea hace que el cursor pase a la siguiente línea

si pulsamos las teclas  1, 2, 3, 4, [tab], 1, 2, 3, 4 se almacenarán como 1234\t1234
y si pulsamos las teclas 1[tab] se almacenarán como 1\t1
sin embargo con tabstop, con un ancho de tab de 8, se mostrarán de la siguiente manera.
----------------------------------------------------------------------------
1234	1234
1	1

### Source
Source reference: @ref exercise_1-20.c
@include exercise_1-20.c

### Compilation
- Linux
  - **Compiler message:** Pending
  - **Generated files:** Pending
- Windows
  - **Compiler message:** Pending
  - **Generated files:** Pending

### Test
Test source: @ref Exercise_1_20_ver_Test(CuTest *tc)
Exercise_1_20_Test1
Begin functions. Now use exercise as example, and test to check only the function.

### Conclusion
