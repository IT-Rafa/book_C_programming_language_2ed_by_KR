/**
 * @file exercise_2-5.c
 * @brief Exercise 2-5 from section 2.8
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-12
 * 
 */

/* LIBRARIES */
#include <stdio.h>
#include <string.h>

/* SYMBOLIC CONSTANTS */

/* EXTERNAL VARIABLES */
/* FUNCTIONS DECLARATIONS */
int any(char s1[], char s2[]);
void printAnyResult(char s[], char search[]);

/* FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 2-5 from section 2.8.
 * Exercise 2-5. Write the function any(s1, s2), which returns the first 
 * location in the string s1 where any character from the string s2 occurs, 
 * or -1 if s1 contains no characters from s2. 
 * (The standard library function strpbrk does the same job, but returns a 
 * pointer to the location.)
 * 
 * @return int State of program value
 */
int main(void)
{
    int n;
    char s[] = "abcdefABCDEF123456";
    char search1[] = "ab";
    char search2[] = "6";
    char search3[] = "321";
    char search4[] = "xyz";

    printf("searching into \"%s\"\n\n", s);
    printAnyResult(s, search1);
    printAnyResult(s, search2);
    printAnyResult(s, search3);
    printAnyResult(s, search4);
    return 0;
}

int any(char st[], char list[])
{
    int pos;
    int seek;
    int found = 0;
    for (pos = 0; !found && pos < strlen(st); pos++) {
        for (seek = 0; !found && seek < strlen(list); seek++) {
            if (st[pos] == list[seek]) {
                found = 1;
            }
        }
    }
    if (found == 1)
        return --pos;
    else
        return -1;
}

void printAnyResult(char s[], char search[])
{
    int pos;
    printf("\"%s\" - ", search);
    if ((pos = any(s, search)) != -1) {
        printf("\'%c\' was found in position: %d", s[pos], pos);
    }
    else {
        printf("No found");
    }
    putchar('\n');
}
